#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Find the Longest Substring Containing Vowels in Even Counts:

Given the string s, return the size of the longest substring containing each vowel an even number of times. That is, 'a', 'e', 'i', 'o', and 'u' must appear an even number of times.

Example 1:

Input: s = "eleetminicoworoep"
Output: 13
Explanation: The longest substring is "leetminicowor" which contains two each of the vowels: e, i and o and zero of the vowels: a and u.
Example 2:

Input: s = "leetcodeisgreat"
Output: 5
Explanation: The longest substring is "leetc" which contains two e's.
Example 3:

Input: s = "bcbcbc"
Output: 6
Explanation: In this case, the given string "bcbcbc" is the longest because all vowels: a, e, i, o and u appear zero times.
 */

/*Apporach 2: Using BitWise operation
1. Here we create a curr state which maps the occurance of a vowel in the string like if a comes it will be like 00001
2. now for each of the current state we mantain a occurance vector which stores the index at with this currstate has occured 
3. now will we are traversing we find a similar occurace in the first occuracence vector that mean we have string with even no. of vowels 
4. hence we update the maxlength.
https://algo.monster/liteproblems/1371
*/

class Solution {
public:
    int findTheLongestSubstring(string s) {
        // Initialize a vector to keep track of the first occurrence of all states.
        vector<int> firstOccurrence(32, INT_MAX);
        // Setting the base condition that for state '0', the first occurrence is at -1
        firstOccurrence[0] = -1;
      
        // Define a string of vowels for easy indexing.
        string vowels = "aeiou";
      
        // This will keep track of the current state of vowels encountered.
        int currentState = 0;
      
        // The result variable to store the length of the longest substring.
        int longestSubstringLength = 0;
      
        // Iterate over the characters of the string.
        for (int i = 0; i < s.size(); ++i) {
            // Check if the current character is a vowel and update the state accordingly.
            for (int j = 0; j < 5; ++j) { // There are 5 vowels.
                if (s[i] == vowels[j]) {
                    // Toggle the j-th bit of the state to represent the occurrence of vowel.
                    currentState ^= (1 << j);
                }
            }
            // Calculate the length if the current state has occurred before
            // The length of the valid string would be difference of indices.
            longestSubstringLength = max(longestSubstringLength, i - firstOccurrence[currentState]);
            // Update the occurrence of current state if it's the first time.
            firstOccurrence[currentState] = min(firstOccurrence[currentState], i);
        }
      
        // Return the length of the longest valid substring found.
        return longestSubstringLength;
    }
};





/*Apporach 1: TLE 
*/
class Solution {
private:
    bool isevenvowel(string &s) {
        unordered_map<char, int> mp;
        for (char i : s) {
            if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u') {
                mp[i]++;  // Increment the correct vowel count
            }
        }
        // Check if all vowels have an even count
        for (auto i : mp) {
            if (i.second % 2 != 0) {
                return false;  // If any vowel count is odd, return false
            }
        }
        return true;
    }

public:
    int findTheLongestSubstring(string s) {
        int n = s.length();
        int maxlen = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {  // j starts from i to explore substrings
                string sub = s.substr(i, j - i + 1);  // Correct substring extraction
                if (isevenvowel(sub)) {
                    maxlen = max((int)sub.length(), maxlen);  // Update max length
                }
            }
        }
        return maxlen;
    }
};


int main(){

return 0;
}