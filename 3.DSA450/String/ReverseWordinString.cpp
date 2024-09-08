#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Reverse Words in a String:
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string 
should only have a single space separating the words. Do not include any extra spaces.

 

Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 */


class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string temp = "";
        
        // Traverse the string and push words into the stack
        for(char i : s) {
            if(i != ' ') {
                temp += i; // Build the current word
            } else {
                if (!temp.empty()) {
                    st.push(temp); // Push non-empty words into the stack
                    temp = ""; // Reset temp for the next word
                }
            }
        }
        
        // Push the last word if the string doesn't end with a space
        if (!temp.empty()) {
            st.push(temp);
        }

        string ans = "";
        // Pop words from the stack and build the reversed string
        while(!st.empty()) {
            ans += st.top(); // Append the word
            st.pop();
            if(!st.empty()) {
                ans += " "; // Add a space between words
            }
        }
        
        return ans;
    }
};


int main(){

return 0;
}