#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Longest Substring Without Repeating Characters
Given a string s, find the length of the longest 
substring
 without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */

/*
Steps:
using two pointers and sliding window
1. maintain a mp with the char and the index of that char 
2. now every time check weather that char has already arrived in the string or not
3. if yes the update the start of the string that is l
4. else move the right pointer ahead add the curr char in the map 
5. also here update the maxlength
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0;
        unordered_map<char,int> mp;
        int n = s.length();
        int l = 0;
        int r = 0;
        while(r<n){
            if(mp.find(s[r]) != mp.end() && mp[s[r]] >= l){
                l = mp[s[r]] + 1;
            }
            mp[s[r]] = r;
            maxlen = max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};

int main(){

return 0;
}