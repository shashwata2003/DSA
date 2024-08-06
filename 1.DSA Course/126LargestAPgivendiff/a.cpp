#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Longest Arithmetic Subsequence of Given Difference:

Given an integer array arr and an integer difference, return the length of the longest subsequence in arr 
which is an arithmetic sequence such that the difference between adjacent elements in the subsequence equals 
difference.

A subsequence is a sequence that can be derived from arr by deleting some or no elements without changing the 
order of the remaining elements.

 

Example 1:
Input: arr = [1,2,3,4], difference = 1
Output: 4
Explanation: The longest arithmetic subsequence is [1,2,3,4].

Example 2:
Input: arr = [1,3,5,7], difference = 1
Output: 1
Explanation: The longest arithmetic subsequence is any single element.

Example 3:
Input: arr = [1,5,7,8,5,3,4,2,1], difference = -2
Output: 4
Explanation: The longest arithmetic subsequence is [7,5,3,1].

TS: O(n)
Sp: O(n)
 */

int longestSubsequence(vector<int>& arr, int difference) {
    int n = arr.size();
    if(n<=1){
        return n;
    }

    // Map is between the current elem and length of the ap
    unordered_map<int,int> dp;
    int ans = 0;

    //Traversing every element
    for (int i = 0; i < n; i++)
    {
        // When are are currently standing on a val we need to check weather possible ap series val is present
        // on the left of curr, Like we did in notes, to find that we will find that possible val and find it
        // in the map
        int temp = arr[i] - difference;
        int templen = 0;
        // if it is present , we will store the len that it stores like in notes when we reaches 5 we 
        // were trying to find 5 - (-2) = 7 in the left of 5, that we found and 7 had a val of 1 stored
        if(dp.count(temp)){
            templen = dp[temp]; // templen will store that 1 val of 7
        }
        // if the val is not present in the map we will init it will 1+0 like in the notes
        dp[arr[i]] = 1+templen; // templen will be zero if not found 

        // and we will find the max val of the current and the ans.
        ans = max(ans,dp[arr[i]]);
    }
    return ans;
}

int main(){
    vector<int> arr = {1,3,5,7};
    int diff = 1;
    cout<<longestSubsequence(arr,diff);
return 0;
}