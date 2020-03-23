#include "output.h"

#include <iostream>
#include <vector>

#include "Sorting/bublesort.h"
#include "Sorting/insertionsort.h"
#include "Sorting/selectionsort.h"
#include "Sorting/mergesort.h"
#include "binsearch.h"


using namespace std;


int main() {

	vector<int> A = {100, 2, 95, 6, 8, 3, 7, 42, 6, 1};
	vector<int> B = {4, 3, 2, 10, 12, 1, 5, 6};
	vector<int> C = {8, 6, 2 ,4 ,6, 8, 7, 3};
	vector<int> res;
	int resint;

	// binsearch test
	/*A = selection(A);
	printVector(A);
	resint = binsearch(A,100);
	cout << resint;
	resint = binsearch(A,2);
	cout << resint;
	resint = binsearch(A,6);
	cout << resint;
	resint = binsearch(A,8);
	cout << resint;
	resint = binsearch(A,3);
	cout << resint;
	resint = binsearch(A,42);
	cout << resint;
	resint = binsearch(A,1);
	cout << resint; */

	// selection sort test

	//res = selection(A);
	//printVector(res);


	// buble sort test
	//A = buble(A);
	//printVector(A);

	// insertion sort test
	//res = insertion(A);
	//res = insertion(B);
	//printVector(A);
	//printVector(res);

	return 0;
}
