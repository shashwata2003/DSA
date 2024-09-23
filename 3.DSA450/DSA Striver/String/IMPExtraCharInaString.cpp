#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Extra Characters in a String:
You are given a 0-indexed string s and a dictionary of words dictionary. You have to break s into one or more non-overlapping substrings such that each substring is present in dictionary. There may be some extra characters in s which are not present in any of the substrings.

Return the minimum number of extra characters left over if you break up s optimally.

 

Example 1:

Input: s = "leetscode", dictionary = ["leet","code","leetcode"]
Output: 1
Explanation: We can break s in two substrings: "leet" from index 0 to 3 and "code" from index 5 to 8. There is only 1 unused character (at index 4), so we return 1.

Example 2:

Input: s = "sayhelloworld", dictionary = ["hello","world"]
Output: 3
Explanation: We can break s in two substrings: "hello" from index 3 to 7 and "world" from index 8 to 12. The characters at indices 0, 1, 2 are not used in any substring and thus are considered as extra characters. Hence, we return 3.
 */

class Solution {
private:
    int solve(int i, int n, unordered_set<string> &st, string s,vector<int> &dp){
        if(i >= n){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        //Exclude first char
        int result = 1+solve(i+1,n,st,s,dp);
        //Include the first char and find the string in the dict
        for(int j = i; j<n; j++){
            string str = s.substr(i,j-i+1);
            if(st.count(str)){
                result = min(result,solve(j+1,n,st,s,dp));
            }
        }
        return dp[i] = result;
    }
public:
    int minExtraChar(string s, vector<string>& dict) {
        int n = s.length();
        unordered_set<string> st(dict.begin(),dict.end());
        vector<int> dp(n+1,-1);
        return solve(0,n,st,s,dp);
    }
};

int main(){

return 0;
}