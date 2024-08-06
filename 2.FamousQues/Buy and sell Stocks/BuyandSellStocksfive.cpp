#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer 
fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to
pay the transaction fee for each transaction.

Note:
You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
The transaction fee is only charged once for each stock purchase and sale.
 

Example 1:
Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.

Example 2:
Input: prices = [1,3,7,5,10,3], fee = 3
Output: 6


Ts: O(n) Sp: O(1)
 */

int solveusingspaceopti(vector<int> prices, int fee){
    vector<int> curr(2,0);
    vector<int> next(2,0);
    int n = prices.size();
    for (int index = n-1; index >= 0; index--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int profit = 0;
            if(buy){
                profit = max((-prices[index]) + next[0],next[1]);
            }else{
                profit = max(prices[index]+next[1]-fee,next[0]);
            }
            curr[buy] = profit;
        }
        next = curr;
    }
    return curr[1];
}

int maxProfit(vector<int>& prices, int fee) {
    int index = 0, buy = 1;
    int ans = solveusingspaceopti(prices,fee);
    return ans;
}
int main(){
    vector<int> arr = {1,3,7,5,10,3};
    int fee = 3;
    cout<<maxProfit(arr,fee); 
return 0;
}