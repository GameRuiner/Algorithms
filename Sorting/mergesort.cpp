// MergeSort
#include "mergesort.h"
#include <vector>
#include "../output.h"
#include "math.h"
using namespace std;


vector<int> mergesort(vector<int> A) {
	//vector<int> recmerge()
	if (A.size() == 1) return A;
	int midle = floor(A.size() / 2);
	vector<int> L(A.begin(), A.begin() + midle);
	vector<int> R(A.begin() + midle, A.end());
	L = mergesort(L);
	R = mergesort(R);
	A = merge(L, R);

	return A;
}
vector<int> merge(vector<int> A, vector<int> B) {
	vector<int> res;
	int a = 0, b = 0;
	for (; a < A.size() && b < B.size();) {
		if (A[a] <= B[b]) {
			res.push_back(A[a]);
			a++;
		}
		else {
			res.push_back(B[b]);
			b++;
		}
	}
	while (a < A.size()) {
		res.push_back(A[a]);
		a++;
	}
	while (b < B.size()) {
		res.push_back(B[b]);
		b++;
	}
	return res;
}
