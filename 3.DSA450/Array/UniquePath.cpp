#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.

Input: m = 3, n = 7
Output: 28
Example 2:

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
 */

/*Using Recursion:*/

class Solution {
public:
     int countPaths(int i, int j, int n, int m)
    {
        if(i == (n-1) && j == (m-1)){
            return 1;
        }
        if(i>=n||j>=m){
            return 0;
        } 

        return countPaths(i+1,j,n,m)+countPaths(i,j+1,n,m);
    }

    int uniquePaths(int m, int n) {
       return countPaths(0,0,m,n);
    }
};


/*Using DP */
class Solution {
private:
    int solveusingDP(int m, int n, int i, int j, vector<vector<int>> &dp){
        if(i == m-1 && j == n-1){
            return 1;
        }
        if(i >= m || j >= n){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        return dp[i][j] = solve(m,n,i+1,j,dp) + solve(m,n,i,j+1,dp);
    }

public:
    int uniquePaths(int m, int n) {
        int i = 0;
        int j = 0;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(m,n,i,j,dp);
    }
};

int main(){

return 0;
}