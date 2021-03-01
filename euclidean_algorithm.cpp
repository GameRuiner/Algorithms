// Euclid's algorithm, is an efficient method for computing the greatest common divisor (GCD) 
// of two integers (numbers)

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    while (a != b) {
        if (a > b) {
            a = a - b;
        } else {
            b = b - a;
        }
    }
    return a;
}



int gcd_rec(int a , int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd_rec(b, a % b);
    }
}

int gcdExtended(int a, int b, int *x, int *y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = gcdExtended(b%a, a, &x1, &y1);

    *x = y1 - (b/a) * x1;
    *y = x1;

    return gcd;
}


int main() {
    int a = 252, b = 105;
    cout << "Greatest common divisor of " << a << " " << b << "\n";
    cout << "is " << gcd(a,b) << "\n";
    cout << "is " << gcd_rec(a,b) << "\n";

    int x,y;
    a = 35; b = 15;
    int g = gcdExtended(a, b, &x, &y);
    cout << "GCD(" << a << ", " << b 
         << ") = " << g << endl;
    cout << x*a + y*b << endl;
    return 0;
    
}

// This code is contributed by TusharSabhani
// https://www.geeksforgeeks.org/euclidean-algorithms-basic-and-extended/