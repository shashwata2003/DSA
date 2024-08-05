#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Unique Binary Search Trees:
Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly
n nodes of unique values from 1 to n.

Exp 1:
Input: n = 3
Output: 5

Example 2:
Input: n = 1
Output: 1

Sol:
Check notes:
 */

//Using recursion
int solveusingrecursion(int n){
    if(n <= 1){
        // if there are 0 or 1 node possible return 1
        return 1;
    }

    int ans = 0;
    // Taking each no. b/w 1 to n as a node, excluding 0
    for (int i = 1; i <= n; i++)
    {
        ans = ans + (solveusingrecursion(i-1) * solveusingrecursion(n-i));
    }
    return ans;
}

//Using memorization:
int solvesuingmemorization(int n, vector<int>& dp){
     if(n <= 1){
        // if there are 0 or 1 node possible return 1
        return 1;
    }
    if(dp[n] != -1){
        return dp[n];
    }

    int ans = 0;
    // Taking each no. b/w 1 to n as a node, excluding 0
    for (int i = 1; i <= n; i++)
    {
        ans = ans + (solvesuingmemorization(i-1,dp) * solvesuingmemorization(n-i,dp));
    }
    return dp[n] = ans;
}

//Using tabulation: TS: O(n2) Sp: O(n)
int solveusingtabulation(int n){
    vector<int> dp(n+1,0);
    dp[0] = 1;
    dp[1] = 1;

    
    //i -> represents the no. of nodes we are preocess for the currrent root
    for (int i = 2; i <= n; i++)
    {
        // J -> represents the root
        for (int j = 1; j <= i; j++)
        {
            dp[i] = dp[i] + (dp[j-1]*dp[i-j]);
        }
        
    }
    return dp[n];
}


int numTrees(int n) {
    //Using only recursion:
    // int ans = solveusingrecursion(n);

    //Using memorixation:
    // vector<int> dp(n+1, -1);
    // int ans = solvesuingmemorization(n,dp);

    //Using tabulation:
    // int ans = solveusingtabulation(n);

    //Using space optimization:
    // the no. of unique ways to create a bST is depended upon to catalan number(google it):
    // eg: for n = 3 catalan no. will be 5 similar to our ans:
    // hence we can just print the catalin no. and we will be done.
    // Formula: Cn = (2n)! / (n+1)! n! 


    return ans ;
}

int main(){
    int n = 3;
    cout<<numTrees(n);
return 0;
}