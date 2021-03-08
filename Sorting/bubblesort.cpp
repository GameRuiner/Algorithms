// BubleSort
#include "bubblesort.h"
#include <vector>
#include "../output.h"
using namespace std;

vector<int> bubble(vector<int> A) {
	for (int i = 0; i < (int) A.size(); i++) {
		for (int j = 0; j < (int) A.size() - i - 1; j ++) {
			if (A[j] > A[j+1]) {
				int c = A[j];
				A[j] = A[j+1];
				A[j+1] = c;
			}
		}
		printVector(A);
	}
	return A;
}

