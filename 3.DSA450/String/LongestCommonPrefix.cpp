#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 */

/*
1. first Sort the string arr by the letter (lexilogical order)
2. then just compare the last and the first word as rest will be same in the order hence the are close to the
start index in sorted arr
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int n = strs.size();
        string a = strs[0];
        string b = strs[n-1];
        string ans = "";
        for(int i = 0; i<a.length(); i++){
            if(a[i] == b[i]){
                ans += a[i];
            }else{
                break;
            }
        }
        return ans;
    }
};

int main(){

return 0;
}