#include <iostream>
#include <vector>
#include "output.h"

using namespace std;

int printVector(vector<int> A) {
		for (int i = 0; i < (int) A.size(); i++) {
			cout << A[i] << " ";
		}
		cout << "\n";
		return 0;
}
