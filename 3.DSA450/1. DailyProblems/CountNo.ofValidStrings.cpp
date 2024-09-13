#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
You are given a string allowed consisting of distinct characters and an array of strings words. A string is consistent if all characters in the string appear in the string allowed.

Return the number of consistent strings in the array words.

 

Example 1:

Input: allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
Output: 2
Explanation: Strings "aaab" and "baa" are consistent since they only contain characters 'a' and 'b'.
Example 2:

Input: allowed = "abc", words = ["a","b","c","ab","ac","bc","abc"]
Output: 7
Explanation: All strings are consistent.
Example 3:

Input: allowed = "cad", words = ["cc","acd","b","ba","bac","bad","ac","d"]
Output: 4
Explanation: Strings "cc", "acd", "ac", and "d" are consistent.
 */

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> s;
        for(char i : allowed){
            s.insert(i);
        }
        int cnt = 0;
        for(string i : words){
            int n = i.length();
            for(char c : i){
                if(s.find(c) == s.end()){
                    break;
                }
                else{
                    n--;
                }
            }
            if(n == 0){
                cnt++;
            }
        }
        return cnt;
    }
};

int main(){

return 0;
}