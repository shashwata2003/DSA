#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Maximum Sum of Non-Adjacent Elements:
You are given an array/list of ‘N’ integers. You are supposed to return the maximum sum of the subsequence 
with the constraint that no two elements are adjacent in the given array/list.
Note:
A subsequence of an array/list is obtained by deleting some number of elements (can be zero)
from the array/list, leaving the remaining elements in their original order.

eg:
Input 1:
2
3
1 2 4
4
2 1 4 9
Sample Output 1:
5
11
 */

// Apporach 1: Just recursion:
int solverec(vector<int> nums, int s, int n){
    if(s > n-1){
        return 0;
    }
    if( s == n-1){
        return nums[n-1];
    }

    int inclu = solverec(nums,s+2,n) + nums[s]; // adding the current index in the sum
    int exclu = solverec(nums,s+1,n) + 0;

    return max(inclu,exclu);
}

//Apporach 2: Resurcsion and Memorization
//TS: O(N) SP: O(n) * O(n)
int solvememorization(vector<int> &nums, int s, int n, vector<int> &dp){
    if(s > n-1){
        return 0;
    }
    if(s == n-1){
        return nums[n-1];
    }
    if(dp[s] != -1){
        return dp[s];
    }
    int inclu = solvememorization(nums,s+2,n,dp) + nums[s]; // adding the current index in the sum
    int exclu = solvememorization(nums,s+1,n,dp) + 0;
    dp[s] = max(inclu,exclu);
    return dp[s];
}

//Using Tabulation:
//TS: O(N) SP: O(n)
int solveusingtable(vector<int> &nums, int s, int n){
    vector<int> dp(n,-1);
    dp[n-1] = nums[n-1];
    for (int i = n-2; i >= 0; i--){
        int inclu = nums[i];
        // checking if i+2 is out of bound or nor
        if(i + 2 < n){
            inclu += dp[i+2];
        }
        int exclu = dp[i+1];
        dp[i] = max(inclu, exclu);
    }
    return dp[s];
}

//Space opyimization: O(n) O(1)
// Here we can optimize the space as the current ans only depends upon i +1 and i +2 element of the dp:
int solvespaceopti(vector<int> &nums, int s, int n){
    int prev1= nums[n-1]; // n+1
    int prev2 = 0; // n+2
    for (int i = n-2; i >= 0; i--)
    {
        int inclu =  prev2 + nums[i];
        int exclu = prev1;
        int ans = max(inclu,exclu);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}


int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    int st = 0; // starting index

    // using only recursion:
    // int ans = solverec(nums,st,n);

    // // USing recursion + memorixzation:
    // vector<int> dp(n+1,-1);
    // int ans = solvememorization(nums,st,n,dp);

    //Using Tabulation:
    // int ans = solveusingtable(nums,st,n);

    //Space optimization:
    int ans = solvespaceopti(nums,st,n);

    return ans;
}

int main(){
    vector<int> arr = {2, 1, 4 ,9};
    cout<<maximumNonAdjacentSum(arr);
return 0;
}