#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Best Time to Buy and Sell Stock II:

You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at 
any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum 
profit of 0.
 */

int solveusingrecursion(vector<int> prices, int buy, int index){
    if(index == prices.size()){
        //If the index goes out of bound
        return 0;
    }

    int profit = 0;
    if(buy){
        // if we are allowed to buy
        int buystock = (-prices[index]) + solveusingrecursion(prices,0,index+1); //hence sending false
        // as we already bought a stock we need to sell it first the we can buy a new.
        int ignorestock = (0) + solveusingrecursion(prices,1,index+1); // as we didnot buy the current hence
        // sending buy true as we can buy next stock
        profit = max(buystock,ignorestock);
    }else{
        int sellstock = (+prices[index]) + solveusingrecursion(prices,1,index+1); // as we sold the stock hence
        // we can buy a new stock
        int ignorecurrstock = (0) + solveusingrecursion(prices,0,index+1); // we cannot buy a new stock as we
        //have not sold the old stock
        profit = max(sellstock,ignorecurrstock);
    }
    return profit;
}

int solveusingmemorization(vector<int> prices, int buy, int index,vector<vector<int>> &dp){
    if(index == prices.size()){
        //If the index goes out of bound
        return 0;
    }
    if(dp[index][buy] != -1){
        return dp[index][buy];
    }
    int profit = 0;
    if(buy){
        // if we are allowed to buy
        int buystock = (-prices[index]) + solveusingmemorization(prices,0,index+1,dp); //hence sending false
        // as we already bought a stock we need to sell it first the we can buy a new.
        int ignorestock = (0) + solveusingmemorization(prices,1,index+1,dp); // as we didnot buy the current hence
        // sending buy true as we can buy next stock
        profit = max(buystock,ignorestock);
    }else{
        int sellstock = (+prices[index]) + solveusingmemorization(prices,1,index+1,dp); // as we sold the stock hence
        // we can buy a new stock
        int ignorecurrstock = (0) + solveusingmemorization(prices,0,index+1,dp); // we cannot buy a new stock as we
        //have not sold the old stock
        profit = max(sellstock,ignorecurrstock);
    }
    return dp[index][buy] = profit;
}

//Ts: O(n) Sp: O(n2)
int solveusingtabulation(vector<int> &prices){
    int n = prices.size();
    //base case is handled by the init of the dp
    vector<vector<int>> dp(n+1,vector<int> (2,0));
    
    for (int index = n-1; index >= 0; index--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int profit = 0;
            if(buy){
                // if we are allowed to buy
                int buystock = (-prices[index]) + dp[index+1][0]; //hence sending false
                // as we already bought a stock we need to sell it first the we can buy a new.
                int ignorestock = (0) + dp[index+1][1]; // as we didnot buy the current hence
                // sending buy true as we can buy next stock
                profit = max(buystock,ignorestock);
            }else{
                int sellstock = (+prices[index]) + dp[index+1][1]; // as we sold the stock hence
                // we can buy a new stock
                int ignorecurrstock = (0) + dp[index+1][0]; // we cannot buy a new stock as we
                //have not sold the old stock
                profit = max(sellstock,ignorecurrstock);
            }
            dp[index][buy] = profit;
        }
        
    }
    return dp[0][1];   
}

//Sp: O(1);
int solveusingspaceoptimization(vector<int> &prices){
    int n = prices.size();
    vector<int> curr(2,0); //index;
    vector<int> next(2,0); //index+1
    
    for (int index = n-1; index >= 0; index--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int profit = 0;
            if(buy){
                // if we are allowed to buy
                int buystock = (-prices[index]) + next[0]; //hence sending false
                // as we already bought a stock we need to sell it first the we can buy a new.
                int ignorestock = (0) + next[1]; // as we didnot buy the current hence
                // sending buy true as we can buy next stock
                profit = max(buystock,ignorestock);
            }else{
                int sellstock = (+prices[index]) + next[1]; // as we sold the stock hence
                // we can buy a new stock
                int ignorecurrstock = (0) + next[0]; // we cannot buy a new stock as we
                //have not sold the old stock
                profit = max(sellstock,ignorecurrstock);
            }
            curr[buy] = profit;
        }
        next = curr;
    }
    return curr[1];   
}

int maxProfit(vector<int>& prices) {
    int buy = true;
    int index = 0;
    int n = prices.size();
    //Using recursion:
    // int ans = solveusingrecursion(prices,buy,index);

    //Using memorization:
    // vector<vector<int>> dp(n,vector<int>(2,-1));
    // int ans = solveusingmemorization(prices,buy,index,dp);

    //Using buttom up approach using tabulation:
    //in memorization index was going from 1 to n here we will be move from n to 1.
    // int ans = solveusingtabulation(prices);

    //Using space optimization:
    // The ans depends upons the index+1 and index hence we created two vectors next and curr
    int ans = solveusingspaceoptimization(prices);

    return ans;
}

int main(){
 vector<int> arr = {1,2,3,4,5};
 cout<<maxProfit(arr);
return 0;
}