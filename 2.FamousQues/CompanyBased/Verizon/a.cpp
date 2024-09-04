#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*
Given a positive integer n. The problem is to print the pyramid pattern as described in the examples below.
Examples: 
Input : n = 4
Output : 
1
3*2
4*5*6
10*9*8*7

Input : n = 5
Output :
1
3*2
4*5*6
10*9*8*7
11*12*13*14*15
*/

/*
Initialize a counter to track the next number to be printed.
For each row:
If the row index is odd, print the numbers in increasing order.
If the row index is even, print the numbers in decreasing order.
For each row, print the numbers separated by *.
*/
void printPyramidPattern(int n) {
    int number = 1;

    for (int i = 1; i <= n; i++) {

        // Print row in increasing order
        if (i % 2 != 0) {
            for (int j = 0; j < i; j++) {
                cout << number;
                if (j < i - 1) {
                    cout << "*";
                }
                number++;
            }
        }
        // Print row in decreasing order
        else {
            number += i - 1; // Move number to the end of the row
            for (int j = 0; j < i; j++) {
                cout << number;
                if (j < i - 1) {
                    cout << "*";
                }
                number--;
            }
            number += i + 1; // Adjust the number for the next row
        }

        cout << endl;
    }
}

int main() {
    int n = 5;  // You can change this value to test other cases
    printPyramidPattern(n);
    return 0;
}