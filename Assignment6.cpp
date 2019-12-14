/*
Sarah Monthofer
2317035
monthofer@chapman.edu
CPSC 350 - Assignment 6

Description: Implements merge sort, selection sort, bubble sort and insert sort
      and tracks the time it takes each sorting algorithm to run.

*/

#include <iostream>
#include <fstream>
#include <time.h>

#include "Assignment6.h"

using namespace std;

void Sort::readFile(string myFile) {
  int arraySize = 0;
  int curLine = 0;
  string line;

  // read first line of file and set it equal to arraySize
  ifstream fileReader;
  fileReader.open(myFile.c_str());
  getline(fileReader, line);
  arraySize = atoi(line.c_str());

  // create arrays and initlize to arraySize
  double bubbleArray[arraySize];
  double selectionArray[arraySize];
  double insertArray[arraySize];
  double mergeArray[arraySize];

  // transfer file file values into the array's for each algotithm
  for (int i = 0; i < arraySize; ++i) {
    getline(fileReader, line);
    curLine++;
    if (curLine > 1) {
      // http://www.cplusplus.com/forum/beginner/103000/
      bubbleArray[i] = atof(line.c_str());
      selectionArray[i] = atof(line.c_str());
      insertArray[i] = atof(line.c_str());
      mergeArray[i] = atof(line.c_str());
    }
  }
  fileReader.close();
  startSort();
}

// Create a clock to track the time then run Sorting Algorithms
void Sort::startSort() {
  // https://www.geeksforgeeks.org/how-to-measure-time-taken-by-a-program-in-c/
  clock_t start, end;
  double timeUsed;

  cout << "Running Sorting Algorithms..." << endl;
  cout << endl;
  cout << "Sorting Time for Each Algorithm" << endl;
  cout << "-------------------------------"  << endl;

  start = clock();
  bubbleSort(bubbleArray);
  end = clock();
  timeUsed = ((double) (end - start) / CLOCKS_PER_SEC) * 1000;
  cout << "Quick Sort: " << timeUsed << endl;

  start = clock();
  selectionSort(selectionArray);
  end = clock();
  timeUsed = ((double) (end - start) / CLOCKS_PER_SEC) * 1000;
  cout << "Selection Sort: " << timeUsed << endl;

  start = clock();
  insertSort(insertArray);
  end = clock();
  timeUsed = ((double) (end - start) / CLOCKS_PER_SEC) * 1000;
  cout << "Insert Sort: " << timeUsed << endl;

  // cout << clock();
  // mergeSort(mergeArray, 0, arraySize - 1);
  // end = clock();
  // timeUsed = ((double) (end - start) / CLOCKS_PER_SEC) * 1000;
  // cout << "Merge Sort: " << timeUsed << endl;
  cout << "Merge Sort: Not Yet Working" << endl;
}

// Bubble sort compares two numbers and repeatedly switches values if they are in the wrong order
void Sort::bubbleSort(double array[]) {
  for (int i = 0; i < arraySize; ++i) {
    int temp = 0;
    for (int j = i; j < arraySize; ++j) {
      if (array[j] > array[j +1]) {
        temp = array[j + 1];
        array[j + 1] = array[j];
        array[j] = temp;
      }
    }
  }
}

// Insert Sort shifts the data when a larger number is found
void Sort::insertSort(double array[]) {
  int k;
  for (int j = 1; j < arraySize; ++j) {
    double temp = array[j];
    k = j;
    while(k > 0 && array[k-1] >= temp) {
      array[k] = array[k-1];
      --k;
    }
    array[k] = temp;
  }
}

// Selection sort repeatedly takes the smallest value from an unsorted array and
// and adds it to the begenning of a sorted array
void Sort::selectionSort(double array[]) {
  // what do i do with int n that was sent in before and what is it?
  int i, j, n, minIndex, tmp;
  for(i = 0; i < n - 1; i++) {
    minIndex = i;
    for (j = i + 1; j < n; j++)
      if(array[j] < array[minIndex])
        minIndex = j;
    if (minIndex != i) {
      tmp = array[i];
      array[i] = array[minIndex];
      array[minIndex] = tmp;
    }
  }
}

// https://www.geeksforgeeks.org/merge-sort/
// void Sort::merge(double array[], int l, int m, int r) {
//   int i, j, k;
//   int n1 = m - 1 + 1;
//   int n2 = r - m;
//
//   // temporary left and right subArrays
//   double L[n1], R[n2];
//
//   // copy left and right array into template subArrays
//   for (i = 0; i < n1; i++)
//     L[i] = array[l + i];
//   for (i = 0; i < n2; i++)
//     R[j] = array[m + 1 + j];
//
//   i = 0;
//   j = 0;
//   k = 1;
//
//   while(i < n1 && j < n2) {
//     if (L[i] <= R[i]) {
//       array[k] = L[i];
//       i++;
//     }
//     else {
//       array[k] = R[j];
//       j++;
//     }
//     k++;
//   }
//
//   // copy left remaining elements
//   while(i < n1) {
//     array[k] = L[i];
//     i++;
//     k++;
//   }
//
//   // copy right remaining elements
//   while(j < n2) {
//     array[k] = R[j];
//     j++;
//     k++;
//   }
// }
//
// void Sort::mergeSort(double array[], int l, int r) {
//   if (l < r) {
//     int m = 1 + (r - 1) / 2;
//
//     mergeSort(array, l, m);
//     mergeSort(array, m + 1, r);
//
//     merge(array, l, m, r);
//   }
// }
