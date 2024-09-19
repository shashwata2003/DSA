#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
Example 2:

Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
 */

/* 
1. first reverse the given string 
2. and find the longest common subsequence with the original string and reversed one.
 */


class Solution {
private:
    int findlongestsubsequence(string& t1, string& t2) {
        int n = t1.length();
        int m = t2.length();
        vector<vector<int>> dp(n + 2, vector<int>(m + 2, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int ans = 0;
                if (t1[i] == t2[j]) {
                    ans = 1 + dp[i + 1][j + 1];
                } else {
                    ans = max(dp[i + 1][j], dp[i][j + 1]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }

public:
    int longestPalindromeSubseq(string s) {
        string rev = s; 
        reverse(rev.begin(), rev.end());
        int ans = findlongestsubsequence(s, rev);
        return ans;
    }
};

int main(){

return 0;
}