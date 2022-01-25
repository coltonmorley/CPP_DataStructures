//Colton Morley CS 302 PA2
//Code taken and adapted from Dr Alexis CS302 UNR Fall 2020 Lecture Slides
#ifndef MERGESORT_H
#define MERGESORT_H

#include <stdexcept>
#include <iostream>

using namespace std;

template <class DataType, int S>
class MergeSort {
    public:
        MergeSort();
        void transferNumbers(const string inputfile, const int numAmount);
        void merge(int first, int mid, int last);
        void mergeSort(int first, int last);
        void print();
        void data(int totalSorts);
        void reset();

    private:
        int size;
        DataType arr[S];
        unsigned long comparisons;
        unsigned long swaps;
};

#endif