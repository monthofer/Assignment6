/*
Sarah Monthofer
2317035
monthofer@chapman.edu
CPSC 350 - Assignment 6

Description: Header file which calls all the classes for the sorting algorithms, and
      creates pointers to each array.

*/

#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

class Sort {
  private:
    int arraySize;
    double *bubbleArray;
    double *selectionArray;
    double *insertArray;
    double *mergeArray;

  public:
    void readFile(string file);
    void startSort();
    void bubbleSort(double array[]);
    void insertSort(double array[]);
    void selectionSort(double aray[]);
    // void mergeSort(double array[], int  0, int arraySize - 1);
};
