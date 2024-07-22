#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Word Break:
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated
sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

Example 1:
Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Example 2:
Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.

Example 3:
Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
 */

bool SolveRecursion(string s, vector<string>& wordDict) {
    //if the string is empty base case:
    if(s.empty()){
        return true;
    }

    // Creating substring of all the possible length 
    for (int i = 1; i <= s.length(); i++)
    {
        string prefix = s.substr(0,i); // substring formed
        if(find(wordDict.begin(), wordDict.end(),prefix) != wordDict.end()  // Checking weather that substring
        && SolveRecursion(s.substr(i),wordDict)){                           // exits in the dict or not
            return true;                                                    // if yes then check the rest of the
        }                                                                   // string
        
    }
    return false;
}

bool solveusingmemorization(string s, vector<string>& wordDict, map<string,bool>& dp) {
    if (s.empty()) {
        return true;
    }
    
    //Checking the given string in the dp array or not 
    if (dp.find(s) != dp.end()) {
        return dp[s];
    }
    
    bool ans = false;
    
    for (int i = 1; i <= s.length(); i++) {
        string prefix = s.substr(0, i);
        
        if (find(wordDict.begin(), wordDict.end(), prefix) != wordDict.end() 
            && solveusingmemorization(s.substr(i), wordDict, dp)) {
            ans = true;
        }
    }
    
    dp[s] = ans;
    return dp[s];
}


bool wordBreak(string s, vector<string>& wordDict) {
    //Using only recursion:
    // bool ans = SolveRecursion(s,wordDict);

    //Using memorization
    map<string,bool> dp;
    bool ans = solveusingmemorization(s,wordDict,dp);

    return ans;
}

int main(){
    string s = "applepenapple";
    vector<string> str = {"apple","pen"};
    cout<<wordBreak(s,str);
return 0;
}