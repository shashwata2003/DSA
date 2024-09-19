#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Given a string s, return the longest 
palindromic
 
substring
 in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"

 */

/*
Steps:
1. Here we traverse each char in the string and treat each element as the middle of a palindrome
2. now we expand from the middle to compare the right and left element of that center element for the odd 
palindromes
3. Calculate the length of the current palindrome as r - l + 1.
4. For even length palindrome Set the center: For an even-length palindrome, set l to i and r to i + 1 (centered between two characters).
Expand Around the Center: Similar to the odd-length case, expand while s[l] is equal to s[r] and both l and r are within bounds.
*/

class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        int len = 0;
        int n = s.length();
        
        for(int i = 0; i<n; i++){
            int l = i;
            int r = i;
            //odd length palindrom:
            while(l >= 0 && r < n && s[l] == s[r]){
                int newlen = r-l+1;
                if(newlen > len){
                    len = newlen;
                    ans = s.substr(l,newlen);
                }
                l--;
                r++;
            }

            l = i;
            r = i+1;
            while(l >= 0 && r < n && s[l] == s[r]){
                int newlen = r-l+1;
                if(newlen > len){
                    len = newlen;
                    ans = s.substr(l,newlen);
                }
                l--;
                r++;
            }
        }
        return ans;
    }
};

int main(){

return 0;
}