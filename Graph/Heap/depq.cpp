// A C++ program to demonstrate Double-Ended-Priority-Queue
#include<iostream> 
#include<climits>
#include "depq.h" 
using namespace std;

DEPQ::DEPQ(int cap) {
    heap_size = 1;
    capacity = cap+1;
    harr = new int[cap+1];
}

int DEPQ::parent(int i) {
    int p = i/2;
    int r = i%2;
    if (p%2 == 0) {
        return p-r;
    }
    if (p%2 == 1) {
        if (r == 0) {
            return p-1;
        }
        return p;
    }
}

int DEPQ::left(int i) {
    return (2*i + i%2);
}

int DEPQ::right(int i) {
    return (2*i + 2 + i%2);
}

int DEPQ::peek_min() {
    return harr[2];
}

int DEPQ::peek_max() {
    return harr[1];
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void DEPQ::heapify_down(int i) {
    int k = harr[i];
    int j;
    do {
        j = k;
        int leftI = left(j);
        int rightI = right(j);
        if (i%2 == 1) {
            if (leftI < heap_size && harr[leftI] > harr[k]) {
                k = leftI;
            }
            if (rightI < heap_size && harr[rightI] > harr[k]) {
                k = rightI;
            }
        } else {
            if (leftI < heap_size && harr[leftI] < harr[k]) {
                k = leftI;
            }
            if (rightI < heap_size && harr[rightI] < harr[k]) {
                k = rightI;
            }
        }
        swap(&harr[j], &harr[k]);
    } while(j != k);

    int leftI = left(j);
    if (leftI >= heap_size) {
        if (j%2 == 0) {
            if(harr[j-1] < harr[j]);
            swap(&harr[j], &harr[j-1]);
            heapify_up(j-1);
        } else {
            if (j+1 < heap_size) {
                if(harr[j+1] > harr[j]) {
                    swap(&harr[j], &harr[j+1]);
                    heapify_up(j+1);
                }
            }
        }
    }
}

void DEPQ::heapify_up(int i) {
    int k = i;
    int j;
    do {
        j = k;
        int parentI = parent(i);
        if (i%2 == 1) {
            if (i != 1 && harr[parentI] < harr[k]) {
                k = parentI;
            }
        } else {
            if (i != 2 && harr[parentI] > harr[k]) {
                k = parentI;
            }
        }
        swap(&harr[j], &harr[k]);
    } while(j != k);
}

void DEPQ::heapify() {
    for (int i = heap_size/2; i >=1 ; i--) {
        heapify_up(i);
    }
}

void DEPQ::change_elem(int i, int u) {
    harr[i] = u;
    heapify_up(i);
    heapify_down(i);
}

void DEPQ::push(int k) {
    if (heap_size == capacity) {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }
    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;
    if (size() > 1) {
        if (i%2 == 0) {
            if (harr[i-1] < harr[i]) {
                swap(&harr[i-1], &harr[i]);
                heapify_up(i-1);
            }
        } else {
            if (harr[i-1] > harr[i]) {
                swap(&harr[i-1], &harr[i]);
                heapify_up(i-1);
            }
        }
    }
    heapify_up(i);
}

int DEPQ::size() {
    return heap_size-1;
}

bool DEPQ::empty() {
    return heap_size == 1;
}

void DEPQ::pop_min() {
    if (heap_size <= 1) {
        cout << "\nQueue is empty: Could not delete min\n";
        return;
    }
    int x = harr[heap_size-1];
    int i = 2;
    while (left(i) < heap_size) {
        int leftI = left(i);
        int rightI = right(i);
        if (rightI < heap_size) {
            if (harr[leftI] > harr[rightI]) {
                swap(&harr[rightI], &harr[i]);
                i = rightI;
            } else {
                swap(&harr[leftI], &harr[i]);
                i = leftI;
            }
        } else {
            swap(&harr[leftI], &harr[i]);
            i = leftI;
        }
    }
    harr[i] = x;
    heap_size--;
}

void DEPQ::pop_max() {
    if (heap_size <= 1) {
        cout << "\nQueue is empty: Could not delete min\n";
        return;
    }
    int x = harr[heap_size-1];
    int i = 1;
    while (left(i) < heap_size) {
        int leftI = left(i);
        int rightI = right(i);
        if (rightI < heap_size) {
            if (harr[leftI] < harr[rightI]) {
                swap(&harr[rightI], &harr[i]);
                i = rightI;
            } else {
                swap(&harr[leftI], &harr[i]);
                i = leftI;
            }
        } else {
            swap(&harr[leftI], &harr[i]);
            i = leftI;
        }
    }
    harr[i] = x;
    heap_size--;
}


void DEPQ::print_arr() {
   for(int loop = 1; loop < heap_size; loop++)
      printf("%d ", harr[loop]);
    printf("\n");
}

int main()
{
    DEPQ h(10);
    h.push(9);
    h.push(52);
    h.push(40);
    h.push(17);
    h.push(20);
    h.push(89);
    h.print_arr();
    cout << h.peek_min() << '\n';
    cout << h.peek_max() << '\n';
    h.pop_min();
    cout << h.peek_min() << '\n';
    h.print_arr();
    h.pop_max();
    cout << h.peek_max() << '\n';
    h.pop_min();
    h.pop_min();
    h.print_arr();
}