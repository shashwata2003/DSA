#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Number of Islands:

Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the 
number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
 */

/*
Apporach 1:
Using recursion:
Here we first find the 1 and then increment the cnt, now after doing that we remove all the possibles
surrounding that 1 and make it to 0.
*/

void removezeros(vector<vector<char>> &grid,int row, int col, int n, int m){
    if(row >= n || row < 0 || col >= m || col < 0 || grid == '0'){
        return;
    }
    grid[row][col] = 0;
    removezeros(grid,row+1,col,n,m); //up
    removezeros(grid,row-1,col,n,m); //down
    removezeros(grid,row,col+1,n,m); // right
    removezeros(grid,row,col-1,n,m); //left
}

int numIslands(vector<vector<char>>& grid) {
    int cnt = 0;
    int n = grid.size();
    int m = grid[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(grid[i][j] == '1'){
                //Once we hit a 1 hence we have encountered a island hence increment the counter:
                cnt++;
                //after doing that we need to remove all the zeros surrounding that 1 so that we do not count those
                //1's again.
                removezeros(grid,i,j,n,m);
            }
        }
        
    }
    return cnt;    
}

/*
Using Graphs (DFS) or BFS:
 Here we are going to  take each {row, col} as a node in the graph and do a DFS traversal for it.

*/
class Solution {
public:
    // Depth First Search to mark the visited cells and collect their relative positions
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid, vector<pair<int, int>>& vec, int row0, int col0) {
        // Mark the cell as visited
        vis[row][col] = 1;

        // Collect relative coordinates
        vec.push_back({row - row0, col - col0});
        
        int n = grid.size();
        int m = grid[0].size();

        // Delta arrays for traversing the neighbors (up, left, down, right)
        int delrow[] = {-1, 0, +1, 0}; 
        int delcol[] = {0, -1, 0, +1}; 

        // Traverse all 4 neighbors
        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            // Check for valid unvisited land neighbor coordinates
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == '1') {
                dfs(nrow, ncol, vis, grid, vec, row0, col0);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Visited array to mark cells as visited
        vector<vector<int>> visited(n, vector<int>(m, 0));
        // Set to store the unique shapes of islands
        set<vector<pair<int, int>>> st;

        // Traverse the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // If cell is unvisited and land ('1'), perform DFS
                if (!visited[i][j] && grid[i][j] == '1') {
                    vector<pair<int, int>> vec;
                    dfs(i, j, visited, grid, vec, i, j);
                    // Insert the unique island shape into the set
                    st.insert(vec);
                }
            }
        }
        // Number of unique island shapes
        return st.size();
    }
};

int main(){

return 0;
}