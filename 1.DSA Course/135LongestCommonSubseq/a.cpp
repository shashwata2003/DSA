#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Longest Common Subsequence:
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no 
common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none)
deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

Example 1:
Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.

Example 2:
Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.

Example 3:
Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
 */

int solveusingrecursion(string t1, string t2, int i , int j){
    if(i == t1.length()){
        return 0;
    }
    if(j == t2.length()){
        return 0;
    }
    int ans = 0;
    if(t1[i] == t2[j]){
        ans = 1+ solveusingrecursion(t1,t2,i+1,j+1);
    }else{
        ans = max(solveusingrecursion(t1,t2,i+1,j),solveusingrecursion(t1,t2,i,j+1));
    }
    return ans;
}

int solveusingmemorization(string t1, string t2, int i , int j, vector<vector<int>> dp){
    if(i == t1.length()){
        return 0;
    }
    if(j == t2.length()){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int ans = 0;
    if(t1[i] == t2[j]){
        ans = 1+ solveusingmemorization(t1,t2,i+1,j+1,dp);
    }else{
        ans = max(solveusingmemorization(t1,t2,i+1,j,dp),solveusingmemorization(t1,t2,i,j+1,dp));
    }
    return dp[i][j] = ans;
}

int solveusingtabulation(string t1, string t2){
    int n = t1.length();
    int m = t2.length();
    vector<vector<int>> dp(n+2,vector<int>(m+2,0));
    for (int i = n-1; i >= 0; i--)
    {
        for (int j = m-1; j >= 0; j--)
        {
            int ans = 0;
            if(t1[i] == t2[j]){
                ans = 1+ dp[i+1][j+1];
            }else{
                ans = max(dp[i+1][j],dp[i][j+1]);
            }
            dp[i][j] = ans;
        }
        
    }
    return dp[0][0];
}

//Sp: O(m) TS: O(m*n)
int solveusingspaceoptimization(string t1, string t2){
    int n = t1.length();
    int m = t2.length();
    vector<int> curr(m+1,0); //i
    vector<int> next(m+1,0); //i+1
    for (int i = n-1; i >= 0; i--)
    {
        for (int j = m-1; j >= 0; j--)
        {
            int ans = 0;
            if(t1[i] == t2[j]){
                ans = 1+ next[j+1];
            }else{
                ans = max(next[j],curr[j+1]);
            }
            curr[j] = ans;
        }
        next = curr;
    }
    return curr[0];
}

int longestCommonSubsequence(string text1, string text2) {
    int i = 0, j = 0;
    int n = text1.length();
    int m = text2.length();
    //Using recursion:
    // int ans = solveusingrecursion(text1,text2,i,j);

    //using memorization:
    // vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    // int ans = solveusingmemorization(text1,text2,i , j, dp);

    //using buttom up apporach: tabulation:
    // int ans = solveusingtabulation(text1,text2);

    //Using Space optimization:
    int ans = solveusingspaceoptimization(text1,text2);
    return ans;
}

int main(){
    string s1 = "abcde" ,s2 = "ace";
    cout<<longestCommonSubsequence(s1,s2);
return 0;
}