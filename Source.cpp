#include "Header.h"

//KLASA SORT
template <class T>
Sort<T>::Sort()
{
    arr = nullptr;
    size = 0;
    percent = 0.0;
}
template <class T>
Sort<T>::~Sort()
{
    delete[] arr;
    arr = nullptr;
}

void check_if_open(std::ofstream& file)
{
    if (!file.is_open())
    {
        std::cout << "File is not open!\nProgram closing...";
        std::cin.get();
        exit(1);
    }
}
template <class T>
void Sort<T>::randomInit()
{
    srand((unsigned int)time(NULL));
    for (int j = 0; j < this->size; j++)
    {
        arr[j] = rand() % 2000000 + 1;
    }
}

template <class T>
T Sort<T>::retVal(int nrIndeksu)
{
    return arr[nrIndeksu];
}

template <class T>
void Sort<T>::setAllArr()
{
    percent = 100;
}

template <class T>
void Sort<T>::initArr(int rozmiar)
{
    switch (rozmiar)
    {
    case 0: size = 10000; arr = new T[size];  break; //10k
    case 1: size = 50000; arr = new T[size];  break; //50k
    case 2: size = 100000; arr = new T[size];  break; //100k
    case 3: size = 500000; arr = new T[size];  break; //500k
    case 4: size = 1000000; arr = new T[size];  break; //1000k
    }
}
template <class T>
void Sort<T>::reversal(int rozmiar)
{
    int i = 0;
    int j = rozmiar - 1;
    T temp;
    for (i, j; i < j; i++, j--)
    {
        temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
    }
}

template <class T>
void Sort<T>::checkSort(int maxIndex)
{
    //std::cout << "NR " << 0 << " " << this->retVal(0) << std::endl;
    for (int i = 1; i < maxIndex + 1; i++)
    {
        //std::cout << "NR " << i << " " << this->retVal(i) << std::endl;
        if (arr[i] < arr[i - 1])
        {
            std::cout << "Blad!!!!" << std::endl;
            exit(7001);
        }
    }
}

template <class T>
T* Sort<T>::retArr()
{
    return arr;
}


//!QUICKSORT
template <class T>
void Sort<T>::QuickSort(int low, int high)
{
    int v = arr[(low + high) / 2];
    int i, j, x;
    i = low;
    j = high;
    do {
        while (arr[i] < v) i++;
        while (arr[j] > v) j--;
        if (i <= j)
        {
            x = arr[i];
            arr[i] = arr[j];
            arr[j] = x;
            i++;
            j--;
        }
    } while (i <= j);
    if (j > low)   QuickSort(low, j);
    if (i < high) QuickSort(i, high);
}

//!MERGESORT
template <class T>
void Sort<T>::MergeSort(int left, int right)
{
    if (left < right)
    {
        int m = left + (right - left) / 2;

        MergeSort(left, m);
        MergeSort(m + 1, right);

        merge(left, m, right);
    }
}
template <class T>
void Sort<T>::merge(int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    T* L = new int[n1];
    T* R = new int[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

//!INTROSORT
template <class T>
void Sort<T>::Hybrid_Introspective_Sort(T* Array, int N)
{
    IntroSort(Array, N, (int)floor(2 * log(N) / M_LN2));
    Insertion_Sort(Array, N);
}

template <class T>
void Sort<T>::IntroSort(T* Array, int N, int M)
{
    int i;
    if (M <= 0)
    {
        Heap_Sort(Array, N);
        return;
    }
    i = Partition(Array, 0, N);
    if (i > 9)
        IntroSort(Array, i, M - 1);
    if (N - 1 - i > 9)
        IntroSort(Array + i + 1, N - 1 - i, M - 1);
}

template <class T>
long Sort<T>::Partition(T* Array, int L, int R)
{
    int i, j;
    if (R >= 3)
        MedianOfThree(Array, L, R);
    for (i = L, j = R - 2; ; )
    {
        for (; Array[i] < Array[R - 1]; ++i);
        for (; j >= L && Array[j] > Array[R - 1]; --j);
        if (i < j)
            Exchange(Array, i++, j--);
        else break;
    }
    Exchange(Array, i, R - 1);
    return i;
}

template <class T>
void Sort<T>::MedianOfThree(T* Array, int& L, int& R)
{
    if (Array[++L - 1] > Array[--R])
        Exchange(Array, L - 1, R);
    if (Array[L - 1] > Array[R / 2])
        Exchange(Array, L - 1, R / 2);
    if (Array[R / 2] > Array[R])
        Exchange(Array, R / 2, R);
    Exchange(Array, R / 2, R - 1);
}

template <class T>
void Sort<T>::Exchange(T* Array, int i, int j)
{
    T temp;
    temp = Array[i];
    Array[i] = Array[j];
    Array[j] = temp;
}


template <class T>
void Sort<T>::Heap_Sort(T* Array, int N)
{
    int i;
    for (i = N / 2; i > 0; --i)
        Heapify(Array - 1, i, N);
    for (i = N - 1; i > 0; --i)
    {
        Exchange(Array, 0, i);
        Heapify(Array - 1, 1, i);
    }
}

template <class T>
void Sort<T>::Heapify(T* Array, int i, int N)
{
    int j;
    while (i <= N / 2)
    {
        j = 2 * i;
        if (j + 1 <= N && Array[j + 1] > Array[j])
            j = j + 1;
        if (Array[i] < Array[j])
            Exchange(Array, i, j);
        else break;
        i = j;
    }
}


template <class T>
void Sort<T>::Insertion_Sort(T* Array, int N)
{
    int i, j;
    T temp;
    for (i = 1; i < N; ++i)
    {
        temp = Array[i];
        for (j = i; j > 0 && temp < Array[j - 1]; --j)
            Array[j] = Array[j - 1];
        Array[j] = temp;
    }
}

//#####################################################################################################################################################





template class Sort<int>;
