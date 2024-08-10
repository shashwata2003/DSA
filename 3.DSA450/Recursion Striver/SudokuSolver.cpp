#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*
Sudoku Solver:
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.

Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
 */

bool isafe(int row, int col, char val, vector<vector<char>> &board)
{
    for (int i = 0; i < 9; i++)
    {
        // check the row
        if (board[row][i] == val)
        {
            return false;
        }
        // check the col
        if (board[i][col] == val)
        {
            return false;
        }
        // check 3*3 box
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
        {
            return false;
        }
    }
    return true;
}
bool solve(vector<vector<char>> &board)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == '.')
            {
                for (char k = '1'; k <= '9'; k++)
                {
                    if (isafe(i, j, k, board))
                    {
                        board[i][j] = k;
                        if (solve(board))
                        {
                            return true;
                        }
                        else
                        {
                            board[i][j] = '.';
                        }
                    }
                }
                return false; // add this line to ensure false is returned if no solution is found
            }
        }
    }
    return true; // add this line to indicate that the board is solved
}
void solveSudoku(vector<vector<char>> &board)
{
    solve(board);
}

int main()
{

    return 0;
}