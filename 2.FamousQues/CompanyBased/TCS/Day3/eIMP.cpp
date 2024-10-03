/*

Q5:
Problem Statement
Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.
Example 1:

Input: s = "bcabc"

Output: "abc"



Example 2:

Input: s = "cbacdcbc"

Output: "acdb"

Input format :
The first line of input consists of a string s, representing the input string.

The second line consists of an integer n, indicating the number of words in the dictionary.

The next line consists of n space-separated strings representing the words of the dictionary.

Output format :
If the input string can be segmented into words from the dictionary, output "true".

If the input string cannot be segmented into words from the dictionary, output "false".



Refer to the sample output for the formatting specifications.

Code constraints :
1 ≤ s.length ≤ 100

s consists of only lowercase English letters.

Sample test cases :
Input 1 :
bcabc
Output 1 :
abc
Input 2 :
cbacdcbc
Output 2 :
acdb
*/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

/* Function to find the smallest lexicographically ordered substring 
   that contains each character only once. */
string findsmallestsubstr(string str) {
    // 'vis' keeps track of whether a character is already in the result string
    unordered_map<char, bool> vis;
    
    // 'cnt' stores the count of each character in the input string
    unordered_map<char, int> cnt;

    // Step 1: Count occurrences of each character in the input string
    for (char c : str) {
        cnt[c]++;
    }

    string res = "";  // The result string that will store the smallest substring

    // Step 2: Iterate through each character in the input string
    for (char c : str) {
        cnt[c]--;  // Decrement the count of the current character since we are processing it

        // Step 3: If the character is already included in the result, skip it
        if (!vis[c]) {
            // Step 4: Check if the last character in the result is larger than the current character,
            // and if it appears later in the string (cnt[res.back()] > 0), 
            // we can remove it from the result to maintain the lexicographical order
            while (res.length() > 0 && res.back() > c && cnt[res.back()] > 0) {
                vis[res.back()] = false;  // Mark the last character as not included
                res.pop_back();  // Remove the last character from the result
            }

            // Step 5: Add the current character to the result string and mark it as included
            res += c;
            vis[c] = true;
        }
    }

    // Step 6: Return the final result which is the lexicographically smallest string
    return res;
}

int main() {
    string str;
    getline(cin, str);  // Input the string from the user
    cout << findsmallestsubstr(str);  // Output the result
    return 0;
}
