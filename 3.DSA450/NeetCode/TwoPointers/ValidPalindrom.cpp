#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

 

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
 */

class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.length() - 1;

        // Loop while left index is less than right index
        while (l < r) {
            // Move the left pointer if the current character is not alphanumeric
            if (!isalnum(s[l])) {
                l++;
                continue;  // Skip the rest of the loop
            }

            // Move the right pointer if the current character is not alphanumeric
            if (!isalnum(s[r])) {
                r--;
                continue;  // Skip the rest of the loop
            }

            // Compare the characters at l and r, ignoring case
            if (tolower(s[l]) != tolower(s[r])) {
                return false;
            }

            // Move both pointers inward
            l++;
            r--;
        }

        // If no mismatches are found, the string is a palindrome
        return true;
    }
};


int main(){

return 0;
}