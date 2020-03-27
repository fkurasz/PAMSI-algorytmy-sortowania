#pragma once
#ifndef _HEADER_H_
#define _HEADER_H_


#include <iostream>
#include <time.h>
#include <fstream>
#include <windows.h>
#include <string>
# define M_LN2          0.69314718055994530942  /* log_e 2 */

void check_if_open(std::ofstream& file);

/*Klasa Sort alokuje dynamicznie tablice o dlugosci podanej podczas
	inicjalizowania klasy poprzez metode arrInit(). Z posrod metod mozna wybrac
	rodzaj sortowania (quickSort, mergeSort, insertionSort*/


template <class T>
class Sort
{
private:
	int size;
	double percent;
	T* arr;

	/*
	void Sortowanie()
	{
		S = new QS();
		S->sortuj(0,n-1);
		delete S;
	}
	*/

public:
	Sort();
	~Sort();

	//ustaw na 100% sortowanie tablicy
	void setAllArr();
	//inicjalizacja
	void initArr(int rozmiar);
	//zwraca rozmiar
	T retVal(int nrIndeksu);
	//inicjalizacja randomowymi
	void randomInit();
	//reversal
	void reversal(int rozmiar);
	//sprawdzenie
	void checkSort(int maxIndex);
	//zwroc adres tablicy
	T* retArr();

	//funckcje dla quicksort
	void QuickSort(int low, int high);

	//funkcje dla mergesort
	void MergeSort(int left, int right);
	void merge(int l, int m, int r);

	//funckje dla insertonsort
	void Hybrid_Introspective_Sort(T* Array, int N);
	void IntroSort(T* Array, int N, int M);
	long Partition(T* Array, int L, int R);
	void MedianOfThree(T* Array, int& L, int& R);
	void Exchange(T* Array, int i, int j);
	void Heap_Sort(T* Array, int N);
	void Heapify(T* Array, int i, int N);
	void Insertion_Sort(T* Array, int N);
};

void check_if_open(std::ofstream& file);


#endif // !HEADER_H
