#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* Get Minimum Squares:

Given a number N. Find the minimum number of squares of any number that sums equal to N. For Example: 
If N = 100, N can be expressed as (10*10) and also as (5*5 + 5*5 + 5*5 + 5*5) but the output will be 1 as 
the minimum number of square is 1, i.e (10*10).

Example 1:

Input: N = 100
Output: 1
Explanation: 10 * 10 = 100
Example 2:

Input: N = 6
Output: 3
Explanation = 1 * 1 + 1 * 1 + 2 * 2 = 6

 */

//Using only recursion:
//TS: Exponial
int solveusingrecursion(int n){
    if(n == 0){
        return 0;
    }
    int ans = n;
    for (int i = 1; i*i <= n; i++)
    {
        int temp = i*i;
        ans = min(ans,1+solveusingrecursion(n-temp));
    }
    return ans;
}

//Using recusion plus memorization:
//TS: O(n) SP: O(n)
int solveusingmemorization(int n, vector<int> &dp){
    if(n == 0){
        return 0;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    int ans = n;
    for (int i = 1; i*i <= n; i++)
    {
        int temp = i*i;
        ans = min(ans,1+solveusingmemorization(n-temp,dp));
    }
    dp[n] = ans;
    return dp[n];
}

//Using Tabulation:
//TS: O(n) SP: O(n)
int solveusingtablulation(int n){
    vector<int> dp(n+1,INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for(int j = 1; j*j<=i ; j++){
            int temp = j*j;
            if(i-temp >= 0){
                dp[i] = min(dp[i],1+dp[i-temp]);
            }
        }
    }
    return dp[n];
}

int MinSquares(int n)
{
    //Using only recursion:
	// int ans = solveusingrecursion(n);

    //using memorization:
    // vector<int> dp(n+1,-1);
    // int ans = solveusingmemorization(n,dp);

    //using tabulation:
    int ans = solveusingtablulation(n);

    //Using space optimization:
    /*Here the solutions of dp[i] depends i - j*j which we cannot implment using two prev variable.*/

    return ans;
}

int main(){
    int n = 6;
    cout<<MinSquares(n);
return 0;
}