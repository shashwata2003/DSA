#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*
Consider a rat placed at (0, 0) in a square matrix mat of order n* n. It has to reach the destination at (n - 1, n - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell. In case of no path, return an empty list. The driver will output "-1" automatically.

Examples:

Input: mat[][] = [[1, 0, 0, 0],
                [1, 1, 0, 1], 
                [1, 1, 0, 0],
                [0, 1, 1, 1]]
Output: DDRDRR DRDDRR
Explanation: The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.
Input: mat[][] = [[1, 0],
                [1, 0]]
Output: -1
Explanation: No path exists and destination cell is blocked.
 */

void solve(vector<string> &ans, vector<vector<int>> &mat, int row, int col,
           string &temp, vector<vector<bool>> &visited)
{
    int n = mat.size();

    if (row == n - 1 && col == n - 1)
    {
        ans.push_back(temp);
        return;
    }

    visited[row][col] = true;

    // Move up
    if (row - 1 >= 0 && mat[row - 1][col] == 1 && !visited[row - 1][col])
    {
        temp.push_back('U');
        solve(ans, mat, row - 1, col, temp, visited);
        temp.pop_back();
    }

    // Move down
    if (row + 1 < n && mat[row + 1][col] == 1 && !visited[row + 1][col])
    {
        temp.push_back('D');
        solve(ans, mat, row + 1, col, temp, visited);
        temp.pop_back();
    }

    // Move right
    if (col + 1 < n && mat[row][col + 1] == 1 && !visited[row][col + 1])
    {
        temp.push_back('R');
        solve(ans, mat, row, col + 1, temp, visited);
        temp.pop_back();
    }

    // Move left
    if (col - 1 >= 0 && mat[row][col - 1] == 1 && !visited[row][col - 1])
    {
        temp.push_back('L');
        solve(ans, mat, row, col - 1, temp, visited);
        temp.pop_back();
    }

    visited[row][col] = false; // Unmark the cell for backtracking
}

vector<string> findPath(vector<vector<int>> &mat)
{
    vector<string> ans;
    if (mat[0][0] == 0)
    {
        return ans; // Return an empty vector if the start point is blocked
    }
    int r = 0, c = 0;
    string temp = "";
    int n = mat.size();
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    solve(ans, mat, r, c, temp, visited);
    return ans;
}
int main()
{

    return 0;
}