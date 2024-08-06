#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
 Best Time to Buy and Sell Stock IV:
You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an 
integer k.

Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most 
k times and sell at most k times.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you 
buy again).

 

Example 1:
Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.

Example 2:
Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. 
Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.

Sol:
Apporach 1:
Using the previous question method,
Just sent the limit to k and everything else will be same

Apporach 2:
Using Transaction no.
 */

int solveusingrecursion(int index, int transaction, int k, vector<int> &prices){
    if(index == prices.size()){
        return 0;
    }
    if(transaction == 2*k){
        return 0;
    }

    int profit = 0;
    if(transaction%2 == 0){
        // wecan buy: as the buy operation is associated with even index , if the transaction is odd hence 
        // we need to sell first as we already bought a stock
        int buystock = (-prices[index]) + solveusingrecursion(index+1,transaction+1,k,prices);  // increasing the tran+1
        int ignorestock = (0) + solveusingrecursion(index+1,transaction,k,prices); 
        profit = max(buystock,ignorestock);
    }else{
        int sellstock = (+prices[index]) + solveusingrecursion(index+1,transaction+1,k,prices); 
        int ignorecurrstock = (0) + solveusingrecursion(index+1,transaction,k,prices); 
        profit = max(sellstock,ignorecurrstock);
    }

    return profit;
}

//Sp: O(n*k) TS: O(n*k)
int solveusingmemorization(int index, int transaction, int k, vector<int> &prices,vector<vector<int>> &dp){
    if(index == prices.size()){
        return 0;
    }
    if(transaction == 2*k){
        return 0;
    }
    if(dp[index][transaction] != -1){
        return dp[index][transaction];
    }
    int profit = 0;
    if(transaction%2 == 0){
        // wecan buy: as the buy operation is associated with even index , if the transaction is odd hence 
        // we need to sell first as we already bought a stock
        int buystock = (-prices[index]) + solveusingmemorization(index+1,transaction+1,k,prices,dp);  // increasing the tran+1
        int ignorestock = (0) + solveusingmemorization(index+1,transaction,k,prices,dp); 
        profit = max(buystock,ignorestock);
    }else{
        int sellstock = (+prices[index]) + solveusingmemorization(index+1,transaction+1,k,prices,dp); 
        int ignorecurrstock = (0) + solveusingmemorization(index+1,transaction,k,prices,dp); 
        profit = max(sellstock,ignorecurrstock);
    }

    return dp[index][transaction] = profit;
}

//Sp: O(n*k) TS: O(n*k)
int solveusingtabulation( int k, vector<int> &prices){
    int n = prices.size();
    vector<vector<int>> dp(n+1,vector<int>(2*k+1,0));

    for (int index = n-1; index >= 0; index--)
    {
        for (int transaction = 0; transaction < 2*k; transaction++)
        {
            int profit = 0;
            if(transaction%2 == 0){
                // wecan buy: as the buy operation is associated with even index , if the transaction is odd hence 
                // we need to sell first as we already bought a stock
                int buystock = (-prices[index]) + dp[index+1][transaction+1];  // increasing the tran+1
                int ignorestock = (0) + dp[index+1][transaction];
                profit = max(buystock,ignorestock);
            }else{
                int sellstock = (+prices[index]) + dp[index+1][transaction+1];
                int ignorecurrstock = (0) + dp[index+1][transaction];
                profit = max(sellstock,ignorecurrstock);
            }

            dp[index][transaction] = profit;
        }
        
    }
    
    return dp[0][0];
}
//SP: O(k) TS: O(n*k)
int solveusingspaceoptimization( int k, vector<int> &prices){
    int n = prices.size();
    vector<int> curr(2*k +1 , 0); //i
    vector<int> next(2*k +1 , 0); // i+1

    for (int index = n-1; index >= 0; index--)
    {
        for (int transaction = 0; transaction < 2*k; transaction++)
        {
            int profit = 0;
            if(transaction%2 == 0){
                // wecan buy: as the buy operation is associated with even index , if the transaction is odd hence 
                // we need to sell first as we already bought a stock
                int buystock = (-prices[index]) + next[transaction+1];  // increasing the tran+1
                int ignorestock = (0) + next[transaction];
                profit = max(buystock,ignorestock);
            }else{
                int sellstock = (+prices[index]) + next[transaction+1];
                int ignorecurrstock = (0) + next[transaction];
                profit = max(sellstock,ignorecurrstock);
            }

            curr[transaction] = profit;
        }
        next = curr;
    }
    
    return curr[0];
}

int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    int index = 0, transactions = 0;
    //Solveusingrecursion : transaction no.
    // int ans = solveusingrecursion(index,transactions,k,prices);

    //Using memorization:
    // vector<vector<int>> dp(n,vector<int>(2*k,-1));
    // int ans = solveusingmemorization(index,transactions,k,prices,dp);

    //USing Tabulation:
    // int ans = solveusingtabulation(k,prices);

    //Using space optimization:
    int ans = solveusingspaceoptimization(k, prices);
    return ans;
}

int main(){
    vector<int> arr = {3,2,6,5,0,3};
    int k = 2;
    cout<<maxProfit(k,arr);
return 0;
}