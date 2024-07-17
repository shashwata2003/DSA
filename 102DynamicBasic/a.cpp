#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Fibbonachi series using DP:
TS = SP = O(n)
 */

// apporach 1: Memorization and recursion
//TS: O(n) SP:O(n)
int fib(int n, vector<int> &dp){
    if( n<=1){
        return n;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    dp[n] = fib(n-1,dp) + fib(n-2,dp);
    return dp[n];
}

int main(){
    int n = 6;
    vector<int> dparray(n+1,-1);//apporach 1:
    // cout<<fib(n,dparray);

    // apporach 2: BFS Tabulation form:
    //TS: O(n) SP: O(n)
    vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    // cout<<dp[n];

    // apporach 3: using just variable inplace of dp : space optimization:
    //TS: O(n) Sp: O(1)
    int prev1 = 1;
    int prev2 = 0;
    if(n == 0){
        cout<<prev2;
    }
    for (int i = 2; i <= n; i++)
    {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    cout<<prev1;
    
    
return 0;
}