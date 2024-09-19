#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 

Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.

*/

/*also we can use Rabin Karp String and knuth-Morris-Pratt*/

/*My Apporach:
O(n*m)
*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();

        // If needle is empty, return 0 as per the problem's convention.
        if (m == 0) return 0;

        // If haystack is shorter than needle, it's impossible to find it.
        if (n < m) return -1;

        int k = 0;    // To track position in the needle
        int ans = -1; // To store the starting position of the match

        for (int i = 0; i < n; i++) {
            if (haystack[i] == needle[k]) {
                if (k == 0) {
                    // Start of a new possible match, record the position
                    ans = i;
                }

                if (k == m - 1) {
                    // Entire needle is matched
                    return ans;
                }

                k++; // Move to the next character in the needle
            } else {
                if (k > 0) {
                    // Reset ans and k to start the match again from the next character in haystack
                    i = i - k; // Move i back to the next position after the last matched character
                }
                ans = -1; // Reset the starting index of the match
                k = 0;    // Reset the needle index
            }
        }

        // If no match was found, return -1
        return -1;
    }
};


/*Second Apporch:*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();

        // If the needle is empty, we return 0
        if (m == 0) return 0;

        // If the haystack is shorter than the needle, it's impossible to find it
        if (n < m) return -1;

        // Loop through the haystack up to the point where the remaining characters 
        // are enough to match the needle
        for (int i = 0; i <= n - m; i++) {
            int j = 0;
            // Check if the substring matches the needle
            while (j < m && haystack[i + j] == needle[j]) {
                j++;
            }
            // If we've matched the entire needle, return the starting index
            if (j == m) {
                return i;
            }
        }
        // If the needle is not found, return -1
        return -1;
    }
};


int main(){

return 0;
}