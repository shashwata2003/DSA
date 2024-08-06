#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.

 

Example 1:

Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.
Example 2:

Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.

Apporach 1: recursion
This solution will give TLA, to save time we need to use memorization.

apporach 2: add memorization to implement top down

apporach 3: adding tabulation and reducing complexity:

apporach 4:Optimizing space
 */

//TS: simple recursion 
int solve(vector<int> cost, int n){
    if(n == 0){
        return cost[0];
    }
    if(n == 1){
        return cost[1];
    }
    int ans = cost[n] + min(solve(cost,n-1),solve(cost,n-2));
}

// Apoorach 2: DP + recursion +  memorization
//TS: O(n) SP: o(N)+O(n)
int solveusingdp(vector<int> cost, int n,vector<int> &dp){
    if(n == 0){
        return cost[0];
    }
    if(n==1){
        return cost[1];
    }
    if(dp[n] != -1){
        return dp[n];
    }
    dp[n] = cost[n] + min(solveusingdp(cost,n-1,dp) , solveusingdp(cost,n-2,dp));

    return dp[n];
}


// APporach 3: using tabulatization
//TS: O(n) SP: o(N)
int dpusingtabulation(vector<int> cost, int n){
    vector<int> dp(n+1);
    // analysis the basecase:
    dp[0] = cost[0];
    dp[1] = cost[1];

    for (int i = 2; i < n; i++)
    {
        dp[i] = cost[i] + min(dp[i-2],dp[i-1]);
    }
    return min(dp[n-1],dp[n-2]);    
}

// Optimizing the Space complexitt:
// SP: O(1)
int spaceoptimized(vector<int> cost, int n){
    int prev1 = cost[0];
    int prev2 = cost[1];

    for (int i = 2; i < n; i++)
    {
        int curr = cost[i] + min(prev1,prev2);
        prev1 = prev2;
        prev2 = curr;
    }
    return min(prev1,prev2);
}


int mincost(vector<int> cost){
    int n = cost.size();
    //usind DP:
    vector<int> dp(n+1,-1);
    // return min(solveusingdp(cost,n-1,dp),solveusingdp(cost,n-2,dp));
    // return dpusingtabulation(cost,n);

    return spaceoptimized(cost,n);
}


int main(){
    vector<int> arr = {10,15,20};
    cout<<mincost(arr);
return 0;
}