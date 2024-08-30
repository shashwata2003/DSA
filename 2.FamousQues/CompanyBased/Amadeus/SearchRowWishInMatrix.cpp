#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Problem statement
You are given an 'N * N' matrix of integers where each row and each column is sorted in increasing order. 
You are given a target integer 'X'.



Find the position of 'X' in the matrix. If it exists then return the pair {i, j} where 'i' 
represents the row and 'j' represents the column of the array, otherwise return {-1,-1}



For example:
If the given matrix is:
[ [1, 2, 5],
  [3, 4, 9],
  [6, 7, 10]] 
We have to find the position of 4. We will return {1,1} since A[1][1] = 4.
Sample Input 1:
2
3 4
1 2 5
3 4 9
6 7 10
2 5
4 5
8 6
Sample Output 1:
1 1
0 1
 */


pair<int, int> search(vector<vector<int>> matrix, int x) {
    int n = matrix.size();

    for (int i = 0; i < n; i++) {
        // Check if the target element is within the current row's range
        if (x < matrix[i][0] || x > matrix[i][n - 1]) {
            continue; // Skip the row if it's impossible to find the target
        }

        int s = 0;
        int e = n - 1;
        int mid = s + (e - s) / 2;

        while (s <= e) {
            if (matrix[i][mid] == x) {
                return {i, mid}; // Target found
            } else if (matrix[i][mid] > x) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
            mid = s + (e - s) / 2;
        }
    }

    return {-1, -1}; // Target not found
}

int main(){

return 0;
}