#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* Shortest Palindrome
You are given a string s. You can convert s to a 
palindrome
 by adding characters in front of it.

Return the shortest palindrome you can find by performing this transformation.

 

Example 1:

Input: s = "aacecaaa"
Output: "aaacecaaa"
Example 2:

Input: s = "abcd"
Output: "dcbabcd"
 
 */
/*Apporach 1: TLE
1. Reverse the given string
2. now compare the rev string with the original string and find the non match char and add to the original and 
return the string
3. like s = abaez  rev = zeaba so here will create the substr to compare like remove from back in original and remove from front in the rev 
*/
class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(),rev.end()); 
        int n = s.length();
        for(int i = 0; i<n; i++){ //this to state that we are moveing i chars
            if(s.substr(0,n-i) == rev.substr(i)){
                return rev.substr(0,i)+s;
            }
        }
        return rev+s;
    }
};

/*Apporach 2:
Using KPM*/

class Solution {
private:
    // Function to compute the Longest Prefix Suffix (LPS) array for the given string.
    // The LPS array is used to store the length of the longest proper prefix which is also a suffix
    // for the substring ending at each index of the string `s`.
    void computeLPS(string s, vector<int> &lps) {
        int i = 1;      // Start from the second character (index 1).
        int len = 0;    // `len` keeps track of the current longest prefix suffix.
        lps[0] = 0;     // The first character has no proper prefix or suffix, so LPS[0] is 0.
        int m = s.length();  // Length of the string `s`.
        
        // Process the string from index 1 to the end.
        while (i < m) {
            // If characters at `i` and `len` match, increment `len` and set LPS[i].
            if (s[len] == s[i]) {
                len++;          // Increase the length of the matching prefix suffix.
                lps[i] = len;   // Store the length in the LPS array.
                i++;            // Move to the next character.
            } else {
                // If there's a mismatch after some matches.
                if (len != 0) {
                    // Instead of starting from scratch, reduce `len` to the previous LPS value.
                    len = lps[len - 1];
                } else {
                    // If `len` is already 0, just move to the next character.
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
    
public:
    // Function to find the shortest palindrome by adding characters to the beginning of the string `s`.
    string shortestPalindrome(string s) {
        // Create the reverse of the string `s`.
        string rev = s;
        reverse(rev.begin(), rev.end());
        
        // Concatenate `s`, a separator (e.g., '-'), and the reversed string `rev` to form the pattern.
        // This helps in finding the longest prefix of `s` that is a palindrome using the LPS array.
        string pattern = s + "-" + rev;
        
        // Create an LPS array for the concatenated string `pattern`.
        vector<int> LPS(pattern.length(), 0);
        
        // Compute the LPS array for the pattern.
        computeLPS(pattern, LPS);
        
        // The last value in the LPS array represents the length of the longest palindromic prefix in `s`.
        int longestLPS = LPS[pattern.length() - 1];
        
        // Identify the substring from the reverse that needs to be added in front of `s` to make it a palindrome.
        string culprit = rev.substr(0, s.length() - longestLPS);
        
        // Return the palindrome by prepending the necessary characters from `rev` to `s`.
        return culprit + s;
    }
};


int main(){

return 0;
}