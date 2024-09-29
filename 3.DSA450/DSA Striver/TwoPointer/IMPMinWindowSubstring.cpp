#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 76. Minimum Window Substring
Given two strings s and t of lengths m and n respectively, return the minimum window 
substring
of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".
The testcases will be generated such that the answer is unique.

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
 */

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        for (char i : t) {
            mp[i]++;  // Store the frequency of characters in t
        }

        int l = 0, r = 0;
        int n = s.length();
        int minlen = INT_MAX;
        int index = -1;
        int cnt = 0;  // Initialize count for matching characters

        while (r < n) {
            // Decrease the frequency of the current character
            mp[s[r]]--;

            // If the character is part of t and its count is zero or less, it is fully matched
            if (mp[s[r]] >= 0) {
                cnt++;
            }

            // Try to shrink the window when all characters of t are matched
            while (cnt == t.length()) {
                // Update the minimum length and index
                if (r - l + 1 < minlen) {
                    minlen = r - l + 1;
                    index = l;
                }

                // Expand the left side of the window
                mp[s[l]]++;
                
                // If the current character is part of t and its count becomes positive, reduce the matched count
                if (mp[s[l]] > 0) {
                    cnt--;
                }

                l++;
            }

            // Expand the right side of the window
            r++;
        }

        // If no valid window was found, return an empty string
        if (index == -1) {
            return "";
        }

        // Return the minimum window substring
        return s.substr(index, minlen);
    }
};


int main(){

return 0;
}