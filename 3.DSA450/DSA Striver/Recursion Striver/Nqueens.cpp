#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack 
each other.
Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in 
any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' 
both indicate a queen and an empty space, respectively.

Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
Example 2:

Input: n = 1
Output: [["Q"]]
 */

// Function to print the solution in the required format
void printans(vector<vector<int>>& board, int n, vector<vector<string>>& ans) {
    vector<string> temp;
    for (int i = 0; i < n; i++) {
        string row = "";
        for (int j = 0; j < n; j++) {
            if (board[i][j] == -1) {
                row += ".";
            } else {
                row += "Q";
            }
        }
        temp.push_back(row);
    }
    ans.push_back(temp);
}

// Function to check if placing a queen at board[row][col] is safe
bool issafe(int row, int col, vector<vector<int>>& board, int n) {
    // Check the left side of the current row
    for (int c = col; c >= 0; c--) {
        if (board[row][c] == 1) {
            return false;
        }
    }

    // Check upper diagonal on the left side
    for (int r = row, c = col; r >= 0 && c >= 0; r--, c--) {
        if (board[r][c] == 1) {
            return false;
        }
    }

    // Check lower diagonal on the left side
    for (int r = row, c = col; r < n && c >= 0; r++, c--) {
        if (board[r][c] == 1) {
            return false;
        }
    }

    return true;
}

// Recursive function to solve the N-Queens problem
void solve(int n, vector<vector<int>>& board, int col, vector<vector<string>>& ans) {
    if (col == n) {
        printans(board, n, ans);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (issafe(i, col, board, n)) {
            board[i][col] = 1;
            solve(n, board, col + 1, ans);
            board[i][col] = -1; // Backtrack
        }
    }
}

// Function to return all solutions to the N-Queens problem
vector<vector<string>> solveNQueens(int n) {
    vector<vector<int>> board(n, vector<int>(n, -1));
    vector<vector<string>> ans;
    solve(n, board, 0, ans);
    return ans;
}

int main() {
    int n = 4;
    vector<vector<string>> ans = solveNQueens(n);
    for (const auto& solution : ans) {
        for (const auto& row : solution) {
            cout << row << endl;
        }
        cout << endl;
    }
    return 0;
}