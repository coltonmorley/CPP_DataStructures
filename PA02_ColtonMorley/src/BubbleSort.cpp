//Colton Morley CS 302 PA2
#include <stdexcept>
#include <iostream>
#include <fstream>

using namespace std;


#include "BubbleSort.h"


//Default Constructor
template <class DataType, int S>
BubbleSort<DataType, S>::BubbleSort()
{
    size = S;
    comparisons = 0;
    swaps = 0;
}

//Completes a bubblesort
//Code taken and adapted from Dr Alexis CS302 UNR Fall 2020 Lecture Slides
template <class DataType, int S>
void BubbleSort<DataType, S>::sort(int n)
{
    //Sorted begins as false
    bool sorted = false;
    int pass = 1;
    while (!sorted && (pass<n))
    {
        sorted = true;
        for(int index = 0; index < n-pass; index++)
        {
            int nextIndex = index + 1;
            comparisons++;
            if(arr[index] > arr[nextIndex])
            {
                swaps++;
                swap(arr[index], arr[nextIndex]);
                sorted = false;
                //Sets sorted to false so the while loop continues until
                //no sorts are made
            }
        }
        //Keeps track of how many passes are done on array
        pass++;
    }
}


template <class DataType, int S>
void BubbleSort<DataType, S>::print()
{
    //prints the array contained in the class
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
}

template <class DataType, int S>
void BubbleSort<DataType, S>::transferNumbers(const string inputfile, const int numAmount)
{
    //inputs numAmount numbers seperated by new lines from input file into array of size S
    ifstream iFile;
    iFile.open(inputfile);
    for(int i = 0; i < numAmount; i++)
    {
        iFile >> arr[i];
    }
    iFile.close();
}


template<class DataType, int S>
void BubbleSort<DataType,S>::data(int totalSorts)
{
    //Prints to console the current number of comparisons and swaps done by the sort
    cout << "Average Comparisons over " << totalSorts << " sorts: " << comparisons / totalSorts << endl;
    cout << "Average Swaps over " << totalSorts << " sorts: " << swaps / totalSorts << endl;

}


//Sets the swaps and comparisons counter back to 0
template<class DataType,int S>
void BubbleSort<DataType, S>::reset()
{
    swaps = 0;
    comparisons = 0;
}