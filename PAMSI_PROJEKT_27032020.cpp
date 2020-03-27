/*
    MOZE WYSTEPOWAC
    WARNING
    @@@@@@@@@@@@@@@@@@@@
    ZE WZGLEDU NA
    KONWERSJE TYPU
    CLOCK_T
    NA
    DOUBLE
*/

#include "Header.h"
using namespace std;


const int ILOSC_TABLIC = 100;
clock_t start, stop;
double czas = 0.0;
double proCent[8] = { 0.0, 25.0, 50.0, 75.0, 95.0, 99.0, 99.7, 100.0 };
int indexTab;
int rozmiarTab;

int main()
{
    std::ofstream plik("Wyniki_sortowan.txt");
    check_if_open(plik);
    //WYBOR SORTOWANIA
    for (int wyborSort = 0; wyborSort < 3; wyborSort++) //0-QS 1-MR 2-IS
    {
        cout << "Wybor sortowania (0-2): " << wyborSort << endl;
        plik << "RODZAJ SORTOWAÑ: " << wyborSort << " | 0-QS 1-MR 2-IS" << endl;
        //WYBOR ILOSCI ELEMENTOW W TABLICY 0-10000 1-50000 2-100000 3-500000 4-1000000
        for (int rozmiarT = 0; rozmiarT < 5; rozmiarT++)
        {
            cout << "Wybor rozmiaru tablicy (0-4): " << rozmiarT << endl;
            plik << "Rozmiar Tablicy: " << rozmiarT << " | 0-10000 1-50000 2-100000 3-500000 4-1000000" << endl;
            //WYBOR % POSORTOWANYCH ELEMENTOW NA STARCIE 0-NONE 1-25% 2-50% 3-75% 4-95% 5-99% 6-99.7% 7-REVERSAL
            for (int wyborProc = 0; wyborProc < 8; wyborProc++)
            {
                cout << "Wybor warunkow poczatkowych (0-7): " << wyborProc << endl;
                plik << "Procent poczatkowy: " << proCent[wyborProc] << "%" << endl;
                Sort<int>* Tab = new Sort<int>[ILOSC_TABLIC]; //(rozmiar tablicy, procent poczatkowego wypelnienia tablicy)

                switch (rozmiarT)
                {

                case 0: indexTab = (int)(proCent[wyborProc] * 10000 / 100 - 1); rozmiarTab = 10000; if (indexTab < 0)
                    indexTab = 0; break;
                case 1: indexTab = (int)(proCent[wyborProc] * 50000 / 100 - 1); rozmiarTab = 50000; if (indexTab < 0)
                    indexTab = 0; break;
                case 2: indexTab = (int)(proCent[wyborProc] * 100000 / 100 - 1); rozmiarTab = 100000; if (indexTab < 0)
                    indexTab = 0; break;
                case 3: indexTab = (int)(proCent[wyborProc] * 500000 / 100 - 1); rozmiarTab = 500000; if (indexTab < 0)
                    indexTab = 0; break;
                case 4: indexTab = (int)(proCent[wyborProc] * 1000000 / 100 - 1); rozmiarTab = 1000000; if (indexTab < 0)
                    indexTab = 0; break;
                }


                for (int x = 0; x < ILOSC_TABLIC; x++)//przygotowanie
                {
                    Tab->initArr(rozmiarT);
                    Tab->randomInit();
                    Tab->QuickSort(0, indexTab);
                    Tab->checkSort(indexTab);
                    if (wyborProc == 7)
                    {
                        Tab->reversal(rozmiarTab);
                    }
                    Tab++;
                }Tab -= ILOSC_TABLIC;

                if (wyborSort == 0)
                {
                    //QS

                    for (int x = 0; x < ILOSC_TABLIC; x++)
                    {
                        start = clock();
                        Tab->QuickSort(0, rozmiarTab - 1);
                        stop = clock();
                        czas += (double)(stop - start) / CLOCKS_PER_SEC;
                        Tab->checkSort(rozmiarTab - 1);
                        Tab++;
                    }Tab -= ILOSC_TABLIC;
                    plik << czas << endl;
                    cout << czas << endl;
                    czas = 0.0;
                }
                else if (wyborSort == 1)
                {
                    //MS

                    for (int x = 0; x < ILOSC_TABLIC; x++)
                    {
                        start = clock();
                        Tab->QuickSort(0, rozmiarTab - 1);
                        stop = clock();
                        czas += (double)(stop - start) / CLOCKS_PER_SEC;
                        Tab->checkSort(rozmiarTab - 1);
                        Tab++;
                    }Tab -= ILOSC_TABLIC;
                    cout << czas << endl;
                    plik << czas << endl;
                    czas = 0.0;
                }
                else if (wyborSort == 2)
                {
                    //IS

                    for (int x = 0; x < ILOSC_TABLIC; x++)
                    {
                        start = clock();
                        Tab->Hybrid_Introspective_Sort(Tab->retArr(), rozmiarTab);
                        stop = clock();
                        czas += (double)(stop - start) / CLOCKS_PER_SEC;
                        Tab->checkSort(rozmiarTab - 1);
                        Tab++;
                    }Tab -= ILOSC_TABLIC;
                    cout << czas << endl;
                    plik << czas << endl;
                    czas = 0.0;
                }

                //USUNIECIE
                delete[] Tab;
            }
        }
        plik << endl << endl;
    }

    plik.close();




    //PRZEJSCIE PO 2 TABLICACH - PRZYGOTOWANIE DO STARTU



    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;


}
