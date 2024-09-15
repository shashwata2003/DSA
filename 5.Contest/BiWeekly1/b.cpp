#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
You are given an m x n binary matrix grid and an integer health.

You start on the upper-left corner (0, 0) and would like to get to the lower-right corner (m - 1, n - 1).

You can move up, down, left, or right from one cell to another adjacent cell as long as your health remains positive.

Cells (i, j) with grid[i][j] = 1 are considered unsafe and reduce your health by 1.

Return true if you can reach the final cell with a health value of 1 or more, and false otherwise.

 

Example 1:

Input: grid = [[0,1,0,0,0],[0,1,0,1,0],[0,0,0,1,0]], health = 1

Output: true

Explanation:

The final cell can be reached safely by walking along the gray cells below.


Example 2:

Input: grid = [[0,1,1,0,0,0],[1,0,1,0,0,0],[0,1,1,1,0,1],[0,0,1,0,1,0]], health = 3

Output: false

Explanation:

A minimum of 4 health points is needed to reach the final cell safely.


Example 3:

Input: grid = [[1,1,1],[1,0,1],[1,1,1]], health = 5

Output: true

Explanation:

The final cell can be reached safely by walking along the gray cells below.



Any path that does not go through the cell (1, 1) is unsafe since your health will drop to 0 when reaching the final cell.

 

 */

class Solution {
private:
    bool solve(vector<vector<int>>& grid, int health, int i, int j, int n, int m, vector<vector<int>>& dp) {
        // Check if we've reached the bottom-right corner
        if (i == n - 1 && j == m - 1) {
            if (grid[i][j] == 1) {
                health--;
            }
            return health > 0;  // Health should be positive when we reach the end
        }

        // Check for out-of-bounds conditions
        if (i < 0 || j < 0 || i >= n || j >= m) {
            return false;
        }

        // If already computed, return the memoized result
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // Reduce health if the current cell is unsafe
        if (grid[i][j] == 1) {
            health--;
        }

        // If health is now 0 or less, return false
        if (health <= 0) {
            return dp[i][j] = false;
        }

        // Try moving in all four directions
        bool up = solve(grid, health, i - 1, j, n, m, dp);
        bool down = solve(grid, health, i + 1, j, n, m, dp);
        bool right = solve(grid, health, i, j + 1, n, m, dp);
        bool left = solve(grid, health, i, j - 1, n, m, dp);

        // Store the result in dp array and return it
        return dp[i][j] = (up || down || right || left);
    }

public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();

        // Memoization table initialized to -1
        vector<vector<int>> dp(n, vector<int>(m, -1));

        // Start recursion from the top-left corner (0, 0)
        return solve(grid, health, 0, 0, n, m, dp);
    }
};


int main(){

return 0;
}