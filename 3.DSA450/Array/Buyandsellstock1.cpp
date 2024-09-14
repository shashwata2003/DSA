#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the 
future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
 */

/*Apporach 1: Brute Force
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        int maxprofit = INT_MIN;
        for(int i = 0; i < n;i++){
            for(int j = i; j<n; j++){
                int profit = prices[j] - prices[i];
                maxprofit = max(maxprofit,profit);
            }
        }
        return maxprofit;
    }
};

/*Apporach 2: Optimized no TLE
1. maintain a mini pointer to store minimum place to buy a stock
2. update the mini pointer with every iteration
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = prices[0];
        int maxprofit = INT_MIN;
        int n = prices.size();
        for(int i = 0; i<n; i++){
            int profit = prices[i] - minprice;
            maxprofit = max(profit,maxprofit);
            minprice = min(prices[i],minprice);
        }
        return maxprofit;
    }
};

int main(){

return 0;
}