#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Set Matrix Zeroes
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
 */

/*Apporach 1:
Follow the steps to solve the problem:

A row array of size N and a col array of size M are initialized with 0 to store which row and which column 
to mark with zeroes.

Then, we will use two loops to traverse all the cells of the matrix.

For each cell (i, j) containing the value 0, we will mark the ith index of the row array i.e. row[i], and 
jth index of col array col[j] as 1. It signifies that all the elements in the ith row and jth column will 
be 0 in the final matrix.

Finally, we will again traverse the entire matrix and we will put 0 into all the cells (i, j) for which 
either row[i] or col[j] is marked as 1.
Thus we will get our final matrix.
*/
void setZeroes(vector<vector<int>>& matrix) {
    vector<int> row(matrix.size(),0);
    vector<int> col(matrix[0].size(),0);

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if(matrix[i][j] == 0){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if(row[i] || col[j]){
                matrix[i][j] = 0;
            }
        }
        
    }
}

/*
Apporach 2:
First, we will traverse the matrix and update the first row and first column as follows we check for cell(i,j) if it is zero then we mark arr[i][0] equal to zero and arr[0][j] equal to zero.
one special case to keep in mind is when i is 0, we will mark matrix[0][0] with 0 but if j is 0, we will mark the C0 variable with 0 instead of marking matrix[0][0] again because one cell can not represent for both row and column.
Now we will traverse cells from (1,1) to (n-1,m-1) and update the matrix’s cell(i,j) according to the first row and first column.
In the end, we will change the matrix’s first row and first column of the matrix as follows, we will change the row first and then the column.
If arr[0][0] = 0, we will change all the elements from the cell (0,1) to (0, m-1), to 0.
If C0 = 0, we will change all the elements from the cell (0,0) to (n-1, 0), to 0.
*/
void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    int c0 = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0) {

                // mark i-th row:
                arr[i][0] = 0;

                // mark j-th column:
                if (j == 0)
                    C0 = 0;
                else
                    arr[0][j] = 0;
            }
        }
    }

    // Mark with 0 from (1,1)
    // to (n-1, m-1):
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (arr[i][j] != 0) {

                // Check for col & row:
                if (arr[i][0] == 0 || arr[0][j] == 0) {
                    arr[i][j] = 0;
                }
            }
        }
    }

    // Finally mark the
    // 1st row then 1st col:
    if (arr[0][0] == 0) {
        for (int j = 0; j < m; j++) {
            arr[0][j] = 0;
        }
    }
    if (c0 == 0) {
        for (int i = 0; i < n; i++) {
            arr[i][0] = 0;
        }
    }        
}
int main(){

return 0;
}