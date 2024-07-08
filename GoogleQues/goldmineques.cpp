#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Path with maximum gold:
Given a gold mine of m*n we need to find a paths which will return the maximum amount of gold, do not visit
a cell with 0 gold in it
eg:
grid ={{0,6,0},{5,8,7},{0,9,0}}
ans = 24
 */

int solve(int row, int col, int trow, int tcol, vector<vector<bool>> &visited, vector<vector<int>> &grid) {
    if (row < 0 || col < 0 || row >= trow || col >= tcol || grid[row][col] == 0 || visited[row][col]) {
        return 0;
    }

    visited[row][col] = true;
    int currentGold = grid[row][col];

    int up = solve(row + 1, col, trow, tcol, visited, grid);
    int down = solve(row - 1, col, trow, tcol, visited, grid);
    int left = solve(row, col - 1, trow, tcol, visited, grid);
    int right = solve(row, col + 1, trow, tcol, visited, grid);

    visited[row][col] = false;
    return currentGold + max({up, down, left, right});
}

int findmaxgold(vector<vector<int>> &grid, int n, int m) {
    if (grid.size() == 0) {
        return 0;
    }

    int maxi = 0;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] != 0) {
                int gold = solve(i, j, n, m, visited, grid);
                maxi = max(gold, maxi);
            }
        }
    }
    return maxi;
}

int main() {
    vector<vector<int>> grid = {{0, 6, 0}, {5, 8, 7}, {0, 9, 0}};
    int n = 3, m = 3;
    cout << findmaxgold(grid, n, m);
    return 0;
}