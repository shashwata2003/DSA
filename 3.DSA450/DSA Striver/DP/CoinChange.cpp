#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Coin Change:
Given an integer array coins[ ] of size N representing different denominations of currency and an integer sum, 
find the number of ways you can make sum by using different combinations from coins[ ].  
Note: Assume that you have an infinite supply of each type of coin. And you can use any coin as many times as 
you want.

Example 1:

Input:
N = 3, sum = 4
coins = {1,2,3}
Output: 4
Explanation: Four Possible ways are: {1,1,1,1},{1,1,2},{2,2},{1,3}.
Example 2:

Input:
N = 4, Sum = 10
coins = {2,5,3,6}
Output: 5
Explanation: Five Possible ways are: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}.

https://www.geeksforgeeks.org/problems/coin-change2448/1
 */


/*
recursive:
when we are including a val then we keep that in the coins,
hen we are excluding it we will remove that val form the coins

                        inclu                           exclu
count(coins,n,sum) = count(coins,n,sum-count[n-1]) + count(coins,n-1,sum)
*/

long long int solve(int coins[], int N, int sum){
    if(sum == 0){
        return 1;
    }
    if(N <= 0){
        return 0;
    }
    if(sum < 0){
        return 0;
    }
    long long int inclu = solve(coins,N,sum - coins[N-1]);
    long long int exclu = solve(coins,N-1,sum);
    return inclu + exclu;
}

long long int count(int coins[], int N, int sum) {
    // long long int ans = solve(coins,N,sum);

    
    return ans;
}

int main(){

return 0;
}