#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  Longest Repeating Character Replacement:
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

 

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.
 */

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int l = 0, r = 0;
        unordered_map<char, int> mp;
        int maxfreq = 0;
        int maxlen = 0;

        while (r < n) {
            mp[s[r]]++;  // Add the current character to the map
            maxfreq = max(maxfreq, mp[s[r]]);  // Update the most frequent character's frequency
            
            int currlen = r - l + 1;  // Current window length

            // Check if the current window is valid (i.e., the number of replacements needed <= k)
            if (currlen - maxfreq <= k) {
                maxlen = max(maxlen, currlen);  // Update the maximum length if the window is valid
            } else {
                // If not valid, shrink the window from the left
                mp[s[l]]--;
                l++;
            }
            r++;  // Move the right pointer to expand the window
        }

        return maxlen;
    }
};


int main(){

return 0;
}