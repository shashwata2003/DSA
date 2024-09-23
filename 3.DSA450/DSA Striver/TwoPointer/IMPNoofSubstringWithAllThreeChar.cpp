#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 1358. Number of Substrings Containing All Three Characters
Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.

 

Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
Example 2:

Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 
Example 3:

Input: s = "abc"
Output: 1
 
 */

class Solution {
private:
    // Function to check if all characters 'a', 'b', and 'c' have been found in the current window
    bool allfound(unordered_map<char,int> &mp) {
        return mp['a'] != -1 && mp['b'] != -1 && mp['c'] != -1;  // Returns true if 'a', 'b', and 'c' have non-negative indices
    }

    // Function to find the minimum index among the positions of 'a', 'b', and 'c' in the current window
    int findminindex(unordered_map<char,int> &mp) {
        int mini = INT_MAX;  // Initialize to a large value
        for (auto i : mp) {  // Iterate through the map to find the minimum index
            mini = min(mini, i.second);
        }
        return mini;  // Return the smallest index of 'a', 'b', or 'c'
    }

public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> mp;  // Map to store the latest index of 'a', 'b', and 'c'
        mp['a'] = -1;  // Initialize positions for 'a', 'b', and 'c' to -1 (not found yet)
        mp['b'] = -1;
        mp['c'] = -1;

        int r = 0;  // Right pointer to expand the window
        int n = s.length();  // Length of the input string
        int cnt = 0;  // To count the number of valid substrings

        // Iterate over the string with the right pointer
        while (r < n) {
            mp[s[r]] = r;  // Update the index of the current character in the map

            // If all characters 'a', 'b', and 'c' have been found in the current window
            if (allfound(mp)) {
                int minindex = findminindex(mp);  // Find the minimum index among 'a', 'b', and 'c'
                cnt += (minindex) + 1;  // Add the number of valid substrings ending at this position
            }

            r++;  // Move the right pointer to expand the window
        }

        return cnt;  // Return the total count of valid substrings
    }
};


int main(){

return 0;
}