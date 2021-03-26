#include <bits/stdc++.h>
using namespace std;

class DEPQ {
    int *harr;
    int capacity; 
    int heap_size;

public:
    DEPQ (int capacity);

    void change_elem(int i, int u);

    void heapify_up(int i);

    void heapify_down(int i);

    void heapify();
    
    void push(int k);
    
    void pop_min();

    void pop_max();

    int peek_min();

    int peek_max();

    int parent(int i);
    
    int left(int i);

    int right(int i);

    int size();

    bool empty();

    void print_arr();
};