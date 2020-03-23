// InsertionSort
#include "insertionsort.h"
#include <vector>
#include "../output.h"
using namespace std;

vector<int> insertion(vector<int> A) {
	for (int i = 1; i < (int) A.size(); i++) {
		for (int j = i - 1; A[j] > A[j+1] && j >= 0; j--) {
			int c = A[j+1];
			A[j+1] = A[j];
			A[j] = c;
		}
		printVector(A);
	}
	return A;
}
