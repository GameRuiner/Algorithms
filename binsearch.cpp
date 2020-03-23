// BinSearch
#include "binsearch.h"
#include <vector>
using namespace std;

int binsearch(vector<int> A, int n) {
	int a,b,c;
	b = A.size() - 1;
	a = 0;
	while (A[b] != n && a != b) {
		c = (int) (a+b)/2;
		if (n > A[c])
			a = c;
		else
			b = c;
	}
	if (n == A[b])
		return b;
	else
		return -1;
}
