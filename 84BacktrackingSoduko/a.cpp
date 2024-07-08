#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Sudoku Solver:
You have been given a 9x9 2d integer matrix 'MAT' representing a Sudoku puzzle. 

The empty cells of the Sudoku are filled with zeros,

and the rest of the cells are filled with integers from 1 to 9. 
Your task is to fill all the empty cells such that the final matrix represents a Sudoku solution.

Note:
A Sudoku solution must satisfy all the following conditions-
1. Each of the digits 1-9 must occur exactly once in each row.
2. Each of the digits 1-9 must occur exactly once in each column.
3. Each of the digits 1-9 must occur exactly once in each of the 9, 3x3 sub-grids of the grid.

You can also assume that there will be only one sudoku solution for the given matrix.

eg:
Sample Input 1
3 0 6 5 0 8 4 0 0
5 2 0 0 0 0 0 0 0
0 8 7 0 0 0 0 3 1
0 0 3 0 1 0 0 8 0
9 0 0 8 6 3 0 0 5
0 5 0 0 9 0 6 0 0
1 3 0 0 0 0 2 5 0
0 0 0 0 0 0 0 7 4
0 0 5 2 0 6 3 0 0

Sample Output 1
3 1 6 5 7 8 4 9 2
5 2 9 1 3 4 7 6 8
4 8 7 6 2 9 5 3 1
2 6 3 4 1 5 9 8 7
9 7 4 8 6 3 1 2 5
8 5 1 7 9 2 6 4 3
1 3 8 9 4 7 2 5 6
6 9 2 3 5 1 8 7 4
7 4 5 2 8 6 3 1 9

Explanation For Sample Output 1
In the output:
In each row, each of the digits 1-9 is occurring exactly once.
In each column, each of the digits 1-9 is occurring exactly once.
In each 3x3 sub-grids of the grid, each of the digits is occurring exactly once.

Apporach:
Here we are going to use recursion:
first we need to find the empty spot
after that we will try for every no from 1-9 and check weather it issafe or not 
and rest of the empty will be taken care by the recursion.

Issafe will check the given condition which will check weather we can place the val at that box or not.


TS: O(9^m) m = no. of empty box
SP: O(1)
 */



bool issafe(vector<vector<int>>& arr, int n, int val, int row, int col) {
    for (int i = 0; i < n; i++) {
        // Check the row
        if (arr[row][i] == val) {
            return false;
        }
        // Check the column
        if (arr[i][col] == val) {
            return false;
        }
        // Check the 3x3 box
        if (arr[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val) {
            return false;
        }
    }
    return true;
}

bool solve(vector<vector<int>>& arr) {
    int n = 9;  // given in the question
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            // Check whether the spot is empty or not
            if (arr[row][col] == 0) {
                // Try all numbers from 1-9
                for (int val = 1; val <= 9; val++) {
                    if (issafe(arr, n, val, row, col)) {
                        arr[row][col] = val;
                        // Recursive call to solve the next empty spot
                        if (solve(arr)) {
                            return true;
                        } else {
                            // Backtrack
                            arr[row][col] = 0;
                        }
                    }
                }
                return false;  // If no number is valid in this empty spot, return false
            }
        }
    }
    return true;  // If no empty spot is left, the puzzle is solved
}

void solvesudoku(vector<vector<int>>& arr) {
    if (solve(arr)) {
        cout << "Sudoku solved successfully!" << endl;
    } else {
        cout << "No solution exists for the given Sudoku." << endl;
    }
}

void printSudoku(const vector<vector<int>>& arr) {
    for (const auto& row : arr) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> arr = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };

    solvesudoku(arr);
    printSudoku(arr);

    return 0;
}
