// SelectionSort
#include "selectionsort.h"
#include <vector>
#include "../output.h"
using namespace std;


vector<int> selection(vector<int> A) {
	for(int i = 0; i < (int) A.size(); i++) {
		int min = A[i];
		int pos = i;
		for(int j = i+1; j < (int) A.size(); j++) {
			if (A[j] < min) {
				min = A[j];
				pos = j;
			}
		}
		int c = A[pos];
		A[pos] = A[i];
		A[i] = c;
		//printVector(A);
	}
	return A;
}
