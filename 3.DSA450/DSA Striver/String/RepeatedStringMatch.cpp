#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Given two strings a and b, return the minimum number of times you should repeat string a so that string b is a substring of it. If it is impossible for b​​​​​​ to be a substring of a after repeating it, return -1.

Notice: string "abc" repeated 0 times is "", repeated 1 time is "abc" and repeated 2 times is "abcabc".

 

Example 1:

Input: a = "abcd", b = "cdabcdab"
Output: 3
Explanation: We return 3 because by repeating a three times "abcdabcdabcd", b is a substring of it.
Example 2:

Input: a = "a", b = "aa"
Output: 2
 */

/*
Steps:
1. First check weather a == b return 1;
2. Now make the a such that it no more < b.length while doing so add the a in it and increment the ans
3. now check weather it b become a substring of it or not if not then add once more a to a 
4. if it still doesnot make b then return -1;
*/

class Solution {
    // Helper function to check if b is a substring of a
    bool check(string &a, string &b) {
        int len = b.length();
        for(int i = 0; i <= a.length() - len; i++) {  // Changed to i <= a.length() - len
            string temp = a.substr(i, len);
            if(temp == b) {
                return true;
            }
        }
        return false;
    }
    
public:
    int repeatedStringMatch(string a, string b) {
        if(a == b) {  // If a and b are the same, you need at least 1 repetition
            return 1;
        }
        
        int ans = 1;
        string temp = a;
        
        // Repeat a until its length is at least the length of b
        while(a.length() < b.length()) {
            a += temp;
            ans++;
        }
        
        // Check if b is now a substring of a
        if(check(a, b)) {
            return ans;
        }
        
        // Check one more repetition of a
        a += temp;
        if(check(a, b)) {
            return ans + 1;
        }
        
        // If b is still not a substring, return -1
        return -1;
    }
};


int main(){

return 0;
}