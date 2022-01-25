#include <stdexcept>
#include <iostream>
#include <fstream>

#include "MergeSort.h"

using namespace std;


const int MAX_SIZE = 1000000;


//default constructor
template <class DataType, int S>
MergeSort<DataType, S>::MergeSort()
{
    size = S;
    comparisons = 0;
    swaps = 0;
}

//Transfers numbers from parameterized input file to array arr
template <class DataType, int S>
void MergeSort<DataType, S>::transferNumbers(const string inputfile, const int numAmount)    
{
    ifstream iFile;
    iFile.open(inputfile);
    for(int i = 0; i < numAmount; i++)
    {
        iFile >> arr[i];
    }
    iFile.close();
}

//Code taken and adapted from Dr Alexis CS302 UNR Fall 2020 Lecture Slides
template <class DataType, int S>
void MergeSort<DataType, S>::merge(int first, int mid, int last)
{
    DataType tempArray[MAX_SIZE];
    int first1 = first;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = last;

    int index = first1;
    while((first1 <= last1) && (first2 <= last2))
    {
        comparisons++;
        if(arr[first1] <= arr[first2])
        {
            swaps++;
            tempArray[index] = arr[first1];
            first1++;
        }
        else
        {
            swaps++;
            tempArray[index] = arr[first2];
            first2++;
        }
        index++;
    }
    while(first1 <= last1)
    {
        swaps++;
        tempArray[index] = arr[first1];
        first1++;
        index++;
    }
    while(first2<=last2)
    {
        swaps++;
        tempArray[index] = arr[first2];
        first2++;
        index++;
    }
    for(index = first; index <= last; index++)
    {
        swaps++;
        arr[index] = tempArray[index];
    }
    
}

//Code taken and adapted from Dr Alexis CS302 UNR Fall 2020 Lecture Slides
template <class DataType, int S>
void MergeSort<DataType, S>::mergeSort(int first, int last)
{
    if(first < last)
    {
        int mid = first + (last-first)/2;
        mergeSort(first,mid);
        mergeSort(mid+1,last);
        merge(first,mid,last);
    }
}

//prints the data stored in arr
template <class DataType, int S>
void MergeSort<DataType, S>::print()
{
     for(int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
}

//prints current count of comparisons and swaps the object has made
template <class DataType, int S>
void MergeSort<DataType, S>::data(int totalSorts)
{
    cout << "Average Comparisons over " << totalSorts << " sorts: " << comparisons / totalSorts << endl;
    cout << "Average Swaps over " << totalSorts << " sorts: " << swaps / totalSorts << endl;
}

//resets swap and comparison counters to 0
template <class DataType, int S>
void MergeSort<DataType, S>::reset()
{
    swaps = 0;
    comparisons = 0;
}