#include <iostream>
#include <stdexcept>
#include <fstream>
#include <ctime>

#include "MergeSort.h"
#include "BubbleSort.h"

//Inclding .cpp's got rid of undefined architecutre errors
//Still slightly unsure as to why
#include "BubbleSort.cpp"
#include "MergeSort.cpp"

using namespace std;

#define ONE 1000
#define TWO 10000
#define THREE 100000
#define SORTS 10

int comparisons = 0;


int main()
{
    long double elapsed;
    clock_t start, end;

    //Bubble sort for 1,000 integers
    cout << endl  << "BUBBLE SORT DATA" << endl << endl;
    cout << "1,000 integer sort" << endl;
    BubbleSort<int,ONE> bubble;
    for(int i = 0; i < SORTS; i ++)
    {
    bubble.transferNumbers("1Thousand.txt", ONE);
    start = clock();
    bubble.sort(ONE);
    end = clock();
    elapsed += ((end-start));
    }
    elapsed /= CLOCKS_PER_SEC;
    bubble.data(SORTS);
    cout << "Average time per sort:  " << elapsed / SORTS << "s" << endl;

    //10,000 integer bubblesort
    cout << endl << "10,000 integer sort" << endl;
    BubbleSort<int,TWO> bubble2;
    for(int i = 0; i < SORTS; i ++)
    {
    bubble2.transferNumbers("10Thousand.txt", TWO);
    start = clock();
    bubble2.sort(TWO);
    end = clock();
    elapsed += ((end-start));
    }
    elapsed /= CLOCKS_PER_SEC;
    bubble2.data(SORTS);
    cout << "Average time per sort:  " << elapsed / SORTS << "s" << endl;

    //100,000 integer bubblesort
    cout << endl << "100,000 integer sort" << endl;
    BubbleSort<int,THREE> bubble3;
    for(int i = 0; i < SORTS; i ++)
    {
    bubble3.transferNumbers("100Thousand.txt", THREE);
    start = clock();
    bubble3.sort(THREE);
    end = clock();
    elapsed += ((end-start));
    }
    elapsed /= CLOCKS_PER_SEC;
    bubble3.data(SORTS);
    cout << "Average time per sort:  " << elapsed / SORTS << "s" << endl;


    cout << endl << endl << "MERGE SORT DATA" << endl;
    
    //Merge sort for 1,000 integers
    cout << "1,000 integer sort" << endl;
    MergeSort<int,ONE> merge;
    for(int i = 0; i < SORTS; i ++)
    {
    merge.transferNumbers("1Thousand.txt", ONE);
    start = clock();
    merge.mergeSort(0, ONE - 1);
    end = clock();
    elapsed += ((end-start));
    }
    elapsed /= CLOCKS_PER_SEC;
    merge.data(SORTS);
    cout << "Average time per sort:  " << elapsed / SORTS << "s" << endl;

    //10,000 integer mergesort
    cout << endl << "10,000 integer sort" << endl;
    MergeSort<int,TWO> merge2;
    for(int i = 0; i < SORTS; i ++)
    {
    merge2.transferNumbers("10Thousand.txt", TWO);
    start = clock();
    merge2.mergeSort(0, TWO - 1);
    end = clock();
    elapsed += ((end-start));
    }
    elapsed /= CLOCKS_PER_SEC;
    merge2.data(SORTS);
    cout << "Average time per sort:  " << elapsed / SORTS << "s" << endl;

    //100,000 integer mergesort
    cout << endl << "100,000 integer sort" << endl;
    MergeSort<int,THREE> merge3;
    for(int i = 0; i < SORTS; i ++)
    {
    merge3.transferNumbers("100Thousand.txt", THREE);
    start = clock();
    merge3.mergeSort(0, THREE - 1);
    end = clock();
    elapsed += ((end-start));
    }
    elapsed /= CLOCKS_PER_SEC;
    merge3.data(SORTS);
    cout << "Average time per sort:  " << elapsed / SORTS << "s" << endl;


    //Tests with sorted data
    /* 
    Clears swap and comparison counters so that the already sorted arrays that
        are stored in the objects can be used again for the pre-sorted tests below
    */
    bubble.reset();
    bubble2.reset();
    bubble3.reset();
    merge.reset();
    merge2.reset();
    merge3.reset();

    //1,000 integer bubble sort
    cout << endl  << "BUBBLE SORT DATA" << endl << endl;
    cout << "1,000 integer sort (Pre-Sorted)" << endl;
    for(int i = 0; i < SORTS; i ++)
    {
    start = clock();
    bubble.sort(ONE);
    end = clock();
    elapsed += ((end-start));
    }
    elapsed /= CLOCKS_PER_SEC;
    bubble.data(SORTS);
    cout << "Average time per sort:  " << elapsed / SORTS << "s" << endl;

    //10,000 integer bubblesort
    cout << endl << "10,000 integer sort (Pre-Sorted)" << endl;
    for(int i = 0; i < SORTS; i ++)
    {
    start = clock();
    bubble2.sort(TWO);
    end = clock();
    elapsed += ((end-start));
    }
    elapsed /= CLOCKS_PER_SEC;
    bubble2.data(SORTS);
    cout << "Average time per sort:  " << elapsed / SORTS << "s" << endl;

    //100,000 integer bubblesort
    cout << endl << "100,000 integer sort (Pre-Sorted)" << endl;
    for(int i = 0; i < SORTS; i ++)
    {
    start = clock();
    bubble3.sort(THREE);
    end = clock();
    elapsed += ((end-start));
    }
    elapsed /= CLOCKS_PER_SEC;
    bubble3.data(SORTS);
    cout << "Average time per sort:  " << elapsed / SORTS << "s" << endl;


    cout << endl << endl << "MERGE SORT DATA" << endl;
    
    //Merge sort for 1,000 integers
    cout << "1,000 integer sort (Pre-Sorted)" << endl;
    for(int i = 0; i < SORTS; i ++)
    {
    start = clock();
    merge.mergeSort(0, ONE - 1);
    end = clock();
    elapsed += ((end-start));
    }
    elapsed /= CLOCKS_PER_SEC;
    merge.data(SORTS);
    cout << "Average time per sort:  " << elapsed / SORTS << "s" << endl;

    //10,000 integer mergesort
    cout << endl << "10,000 integer sort (Pre-Sorted)" << endl;
    for(int i = 0; i < SORTS; i ++)
    {
    start = clock();
    merge2.mergeSort(0, TWO - 1);
    end = clock();
    elapsed += ((end-start));
    }
    elapsed /= CLOCKS_PER_SEC;
    merge2.data(SORTS);
    cout << "Average time per sort:  " << elapsed / SORTS << "s" << endl;

    //100,000 integer mergesort
    cout << endl << "100,000 integer sort (Pre-Sorted)" << endl;
    for(int i = 0; i < SORTS; i ++)
    {
    start = clock();
    merge3.mergeSort(0, THREE - 1);
    end = clock();
    elapsed += ((end-start));
    }
    elapsed /= CLOCKS_PER_SEC;
    merge3.data(SORTS);
    cout << "Average time per sort:  " << elapsed / SORTS << "s" << endl;

    return 0;
}

