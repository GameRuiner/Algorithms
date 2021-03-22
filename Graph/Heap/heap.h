#include <bits/stdc++.h>
using namespace std;

class MinHeap {
    int *harr;
    int capacity; 
    int heap_size;
public:
    MinHeap(int capacity);

    void HeapSort(int arr[], int n);

    // to heapify a subtree with the root at given index
    void MinHeapify(int);

    int parent(int i);
    
    int left(int i);

    int right(int i);

    int extractMin();

    void decreaseKey(int i, int new_val);

    int getMin();

    void deleteKey(int i);

    void insertKey(int k);

    // for priority queue
    void push(int k);

    int size();

    int top();

    void pop();

    bool empty();
};

void swap(int *x, int *y);