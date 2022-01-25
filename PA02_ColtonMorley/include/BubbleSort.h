//Colton Morley CS 302 PA2
//Code taken and adapted from Dr Alexis CS302 UNR Fall 2020 Lecture Slides
#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <stdexcept>
#include <iostream>

using namespace std;

template <class DataType, int S>
class BubbleSort {
  public:
    BubbleSort();
    void transferNumbers(const string inputfile, const int numAmount);
    void sort(int n);
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