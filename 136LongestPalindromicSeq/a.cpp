#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Longest Palindromic Subsequence:
Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without 
changing the order of the remaining elements.

 

Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
Example 2:

Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
 */

int findlongestcommonsubseq(string s1, string s2){
    int n = s1.length();
    int m = s2.length();
    vector<int> curr(m+1,0);
    vector<int> next(m+1,0);

    for (int i = n-1; i >= 0; i--)
    {
        for (int j = m-1; j >= 0; j--)
        {
            int ans = 0;
            if(s1[i] == s2[j]){
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

int longestPalindromeSubseq(string s) {
    string reversestring = s;
    reverse(reversestring.begin(),reversestring.end());
    int ans = findlongestcommonsubseq(s,reversestring);

    return ans;
}

int main(){
    string s = "bbbab";
    cout<<longestPalindromeSubseq(s);
return 0;
}