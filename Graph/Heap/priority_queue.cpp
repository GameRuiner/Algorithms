// C++ program for implementation of Priority Queues
#include <iostream>
#include "heap.h"
 
using namespace std;

void MinHeap::push(int k) {
    insertKey(k);
}

int MinHeap::size() {
    return heap_size;
}

int MinHeap::top() {
    return getMin();
}

void MinHeap::pop() {
    deleteKey(0);
}

bool MinHeap::empty() {
    return size() < 1;
}

void showpq(MinHeap pq) 
{ 
    while (!pq.empty()) { 
        cout << '\t' << pq.top(); 
        pq.pop(); 
    } 
    cout << '\n'; 
} 

int main() {
    MinHeap pq(11);
    pq.push(10); 
    pq.push(20); 
    pq.push(5);
    pq.push(1);
    pq.push(0);
  
    cout << "Top : " << pq.top() << "\n";
    cout << "Size : " << pq.size() << "\n"; 
    showpq(pq); 
} 