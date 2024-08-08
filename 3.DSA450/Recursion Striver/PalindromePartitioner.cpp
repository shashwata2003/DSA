#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Palindrome Partitioning
Given a string s, partition s such that every 
substring of the partition is a palindrome
Return all possible palindrome partitioning of s.

Example 1:
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]

https://takeuforward.org/data-structure/palindrome-partitioning/
 */

bool ispalindrome(string s, int start, int end){
    while (start <= end)
    {
        if(s[start] != s[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}

void solve(string s, vector<vector<string>> &ans, vector<string> &temp, int index){
    if(index == s.size()){
        ans.push_back(temp);
        return;
    }
    //Loop all the elements after index to make substrings of it 
    for (int i = index; i < s.length(); i++)
    {
        if(ispalindrome(s,index,i)){
            temp.push_back(s.substr(index,i-index+1));
            solve(s,ans,temp,i+1);
            temp.pop_back();
        }
    }
    
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> temp;
    int i = 0;
    solve(s,ans,temp,i);
    return ans;
}

int main(){

return 0;
}