#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Permutation Coefficient:
P(n, k) = P(n-1, k) + k* P(n-1, k-1)
*/

int permutation(int n, int k) {
    // Base cases
    if (k == 0) {
        return 1;
    }
    if (n < k) {
        return 0;
    }

    // Recursive case
    return n * permutation(n - 1, k - 1);
}


int PermutationCoeff(int n, int k)
{
    int P = 1;

    // Compute n*(n-1)*(n-2)....(n-k+1)
    for (int i = 0; i < k; i++)
        P *= (n-i) ;

    return P;
}

// Driver Code
int main()
{
    int n = 10, k = 2;
    cout << "Value of P(" << n << ", " << k
         << ") is " << permutation(n, k);

    return 0;
}

