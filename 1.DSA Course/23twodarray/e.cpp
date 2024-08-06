#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* Spiral Print:
Print the 2D arr in the from of a spiral like
1 2 3 4
5 6 7 8
9 10 11 12
print it like:
1,2,3,4,8,12,11,10,9,5,6,7.
Sol:
we need to follow a series of steps to print it in a sprial from :
1. First print the first row and move the pointer to the second row.
2. print the last column and move the last column pointer to the second last column
3.print the last row and move the counter
4. print the first column 
Continue this till all the columns and rows are printed.

Time Complexity : O(N*M)
 */
int main() {
    vector<vector<int>> arr = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int rows = arr.size();
    int cols = arr[0].size();
    vector<int> ans;

    int count = 0;
    int total = rows * cols;

    // Pointers:
    int firstrow = 0;
    int lastcol = cols - 1;
    int lastrow = rows - 1;
    int firstcol = 0;

    while (count < total) {
        // Print the first row:
        for (int i = firstcol; count < total && i <= lastcol; i++) {
            ans.push_back(arr[firstrow][i]);
            count++;
        }
        firstrow++;

        // Print the last column:
        for (int i = firstrow; count < total && i <= lastrow; i++) {
            ans.push_back(arr[i][lastcol]);
            count++;
        }
        lastcol--;

        // Print the last row:
        for (int i = lastcol; count < total && i >= firstcol; i--) {
            ans.push_back(arr[lastrow][i]);
            count++;
        }
        lastrow--;

        // Print the first column:
        for (int i = lastrow; count < total && i >= firstrow; i--) {
            ans.push_back(arr[i][firstcol]);
            count++;
        }
        firstcol++;
    }

    // Print the spiral order:
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    
    return 0;
}