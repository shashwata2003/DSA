#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Largest square formed in a matrix
Given a binary matrix mat of size n * m, find out the maximum length of a side of a square 
sub-matrix with all 1s.
Input: n = 6, m = 5
mat = [[0, 1, 1, 0, 1], 
       [1, 1, 0, 1, 0],
       [0, 1, 1, 1, 0],
       [1, 1, 1, 1, 0],
       [1, 1, 1, 1, 1],
       [0, 0, 0, 0, 0]]
Output: 3

Input: n = 2, m = 2
mat = [[1, 1], 
       [1, 1]]
Output: 2


 */

int solveusingrecursion(int n, int m, vector<vector<int>>& mat, int i, int j, int& maxi) {
    if (i >= n || j >= m) {
        // Out of the matrix
        return 0;
    }

    // when we start from 0, 0 we have three places to move to , right , down and diagonal 
    int right = solveusingrecursion(n, m, mat, i, j + 1, maxi);
    int down = solveusingrecursion(n, m, mat, i + 1, j, maxi);
    int diag = solveusingrecursion(n, m, mat, i + 1, j + 1, maxi);

    //if only the current index is 1 then only we can make a squae
    if (mat[i][j] == 1) {
        int ans = 1 + min(right, min(down, diag));
        maxi = max(ans, maxi);
        return ans;
    } else {
        return 0;
    }
}
//Ts: O(n*m) SP:O(n*m)
int Solveusingmemorization(int n, int m, vector<vector<int>>& mat, int i, int j, int& maxi,vector<vector<int>> &dp){
    if (i >= n || j >= m) {
        // Out of the matrix
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    // when we start from 0, 0 we have three places to move to , right , down and diagonal 
    int right = Solveusingmemorization(n, m, mat, i, j + 1, maxi,dp);
    int down = Solveusingmemorization(n, m, mat, i + 1, j, maxi,dp);
    int diag = Solveusingmemorization(n, m, mat, i + 1, j + 1, maxi,dp);

    //if only the current index is 1 then only we can make a squae
    if (mat[i][j] == 1) {
        dp[i][j] = 1 + min(right, min(down, diag));
        maxi = max(dp[i][j], maxi);
        return dp[i][j];
    } else {
        return dp[i][j] = 0;
    }
}

//Ts: O(n*m) SP:O(n*m)
void solveusingtabulation(int n, int m, vector<vector<int>>& mat, int &maxi){
    vector<vector<int>> dp(n+1,vector<int> (m+1,0));

    //Traverse in the bound :
    for (int i = n-1; i >= 0 ; i--)
    {
        for (int j = m-1; j >= 0; j--)
        {
            // when we start from 0, 0 we have three places to move to , right , down and diagonal 
            int right = dp[i][j + 1];
            int down = dp[i + 1][j];
            int diag = dp[i + 1][j + 1];

            //if only the current index is 1 then only we can make a squae
            if (mat[i][j] == 1) {
                dp[i][j] = 1 + min(right, min(down, diag));
                maxi = max(dp[i][j], maxi);
            } else {
               dp[i][j] = 0;
            }
        }
        
    }
}

void Solveusingspaceoptimization(int n, int m, vector<vector<int>> mat, int &maxi){
    vector<int> currrow(m+1,0); //replace dp[i]
    vector<int> nextrow(m+1,0); //replace dp[i+1]

    for (int i = n-1; i >= 0 ; i--)
    {
        for (int j = m-1; j >= 0; j--)
        {
            // when we start from 0, 0 we have three places to move to , right , down and diagonal 
            int right = currrow[j + 1];
            int down = nextrow[j];
            int diag = nextrow[j + 1];

            //if only the current index is 1 then only we can make a squae
            if (mat[i][j] == 1) {
                currrow[j] = 1 + min(right, min(down, diag));
                maxi = max(currrow[j], maxi);
            } else {
               currrow[j] = 0;
            }
        }
        //Move the next pointer:
        nextrow = currrow;
    }

}

int maxSquare(int n, int m, vector<vector<int>> mat) {
    int row = 0, col = 0;
    int maxi = 0; // Initialize maxi to 0
    
    // Using only recursion
    // solveusingrecursion(n, m, mat, row, col, maxi);

    //Using memorization:
    // vector<vector<int>> dp(n,vector<int>(m,-1));
    //  Solveusingmemorization(n,m,mat,row,col,maxi,dp);

    //Using Tabulation:
    //solveusingtabulation(n,m,mat,maxi);

    // SPace optimization:
    //Here the dp[i][j] depends upon the current row and the row +1 same for col:
    // Hence do dont have to create a entire n*m matrix we can just create a const row  and col matrix
    Solveusingspaceoptimization(n,m,mat,maxi);
    return maxi; // Return the maximum size of the square
}

int main(){
    int n = 6, m = 5;
    vector<vector<int>> arr = {{0, 1, 1, 0, 1}, 
       {1, 1, 0, 1, 0},
       {0, 1, 1, 1, 0},
       {1, 1, 1, 1, 0},
       {1, 1, 1, 1, 1},
       {0, 0, 0, 0, 0}};
    cout<<maxSquare(n,m,arr);
return 0;
}