#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Reverse Word In a String:
Given a string, the task is to reverse the order of the words in the given string. 

Examples:

Input: s = “i love programming very much” 
Output: s = “much very programming love i” 

Input: s = ” geeks for all” 
Output: s = “all for geeks”
We need to remove all the extra spaces in the output
 */

/*steps:
1. create a temp strings of each words which are separated by the " ";
2. push them in the stack also reset the temp word to ""
3. pop them and add them to the ans
4. if there is still word in stack then push a " "

*/
class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        int n = s.length();
        string word = "";
        
        for (int i = 0; i < n; i++) {
            if (s[i] != ' ') {
                word += s[i];
            } else if (!word.empty()) {
                st.push(word);
                word = "";
            }
        }
        
        // Don't forget to push the last word, if any
        if (!word.empty()) {
            st.push(word);
        }
        
        string ans;
        
        while (!st.empty()) {
            ans += st.top();
            st.pop();
            if (!st.empty()) {
                ans += " ";
            }
        }
        
        return ans;
    }
};

int main(){

return 0;
}