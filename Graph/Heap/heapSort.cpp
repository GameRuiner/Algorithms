// C++ program for implementation of Heap Sort
#include <iostream>
#include "heap.h"
 
using namespace std;

void MinHeap::HeapSort(int arr[], int n) {
    harr = arr;
    capacity = n;
    heap_size = n;
    
    for (int i = n/2 - 1; i >=0; i--) {
        MinHeap::MinHeapify(i);
    }

    for (int i = 1; i < n; i++) {
        harr = arr + 1;
        heap_size -= 1; 
        MinHeap::MinHeapify(0);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);

    MinHeap h(0);
    h.HeapSort(arr, n);
 
    cout << "Sorted array is \n";
    printArray(arr, n);
}