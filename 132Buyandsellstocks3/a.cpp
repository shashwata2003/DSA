#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Best Time to Buy and Sell Stock III:
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy 
again).

Example 1:
Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.

Example 2:
Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple 
transactions at the same time. You must sell before buying again.

Example 3:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
 
 */

int solveusingrecursion(vector<int> &prices, int index, int buy, int limit){
    if(index == prices.size()){
        return 0;
    }
    //Addition base to check weather we based the limit of 2 transaction:
    if(limit == 0){
        return 0;
    }

    int profit = 0;
    if(buy){
        profit = max((-prices[index]) + solveusingrecursion(prices,index+1,0,limit) , 
                        0 + solveusingrecursion(prices,index+1,1,limit));
    
    }
    else{
        // we only complete a transection when we buy a stock and then sell it hence decresing the limit
        profit = max((prices[index]) + solveusingrecursion(prices,index+1,1,limit-1) , 
                        0 + solveusingrecursion(prices,index+1,0,limit));
    }
    return profit;
}

int solveusingmemorization(vector<int> &prices, int index, int buy, int limit,vector<vector<vector<int>>> &dp){
    if(index == prices.size()){
        return 0;
    }
    //Addition base to check weather we based the limit of 2 transaction:
    if(limit == 0){
        return 0;
    }

    if(dp[index][buy][limit] != -1){
        return dp[index][buy][limit];
    }

    int profit = 0;
    if(buy){
        profit = max((-prices[index]) + solveusingmemorization(prices,index+1,0,limit,dp) , 
                        0 + solveusingmemorization(prices,index+1,1,limit,dp));
    
    }
    else{
        // we only complete a transection when we buy a stock and then sell it hence decresing the limit
        profit = max((prices[index]) + solveusingmemorization(prices,index+1,1,limit-1,dp) , 
                        0 + solveusingmemorization(prices,index+1,0,limit,dp));
    }
    return dp[index][buy][limit] = profit;
}
//TS: O(n*2*3) O(n*2*3)
int solveusingtabulation(vector<int> &prices){
    int n = prices.size();
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));

    for (int index = n-1; index >= 0; index--)
    {
       for (int buy = 0; buy <= 1; buy++)
       {
            //we start from 1 as limit = 0 is 0 which is handled in the init of the base case
            for (int limit = 1; limit <= 2; limit++)
            {
                int profit = 0;
                if(buy){
                    profit = max((-prices[index]) + dp[index+1][0][limit], 
                                    0 + dp[index+1][1][limit]);
                
                }
                else{
                    // we only complete a transection when we buy a stock and then sell it hence decresing the limit
                    profit = max((prices[index]) + dp[index+1][1][limit-1] , 
                                    0 + dp[index+1][0][limit]);
                }
                dp[index][buy][limit] = profit;
            }

       }
    }
    
    return dp[0][1][2];
    
}

//Sp: O(1)
int solveusingspaceopti(vector<int> &prices){
    int n = prices.size();
    vector<vector<int>> curr(2,vector<int>(3,0));// index
    vector<vector<int>> next(2,vector<int>(3,0)); // index+1

    for (int index = n-1; index >= 0; index--)
    {
       for (int buy = 0; buy <= 1; buy++)
       {
            //we start from 1 as limit = 0 is 0 which is handled in the init of the base case
            for (int limit = 1; limit <= 2; limit++)
            {
                int profit = 0;
                if(buy){
                    profit = max((-prices[index]) + next[0][limit], 
                                    0 + next[1][limit]);
                
                }
                else{
                    // we only complete a transection when we buy a stock and then sell it hence decresing the limit
                    profit = max((prices[index]) + next[1][limit-1] , 
                                    0 + next[0][limit]);
                }
                curr[buy][limit] = profit;
            }

       }
       next = curr;
    }
    
    return curr[1][2];
    
}

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int index = 0, buy = 1, limit = 2;
    //Using recursion:
    // int ans = solveusingrecursion(prices,index,buy,limit);

    //Using Memorization:
    //DP vector : index , buy , limits
    // vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
    // int ans = solveusingmemorization(prices,index,buy,limit,dp);

    //Using buttom up : tabulation
    // int ans =  solveusingtabulation(prices);

    //USing space optimization:
    int ans = solveusingspaceopti(prices);
    return ans;
}

int main(){
    vector<int> arr = {3,3,5,0,0,3,1,4};
    cout<<maxProfit(arr);
return 0;
}