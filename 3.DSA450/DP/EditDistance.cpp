#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Edit Distance:
Given two strings str1 and str2. Return the minimum number of operations required to convert str1 to str2.
The possible operations are permitted:

Insert a character at any position of the string.
Remove any character from the string.
Replace any character from the string with any other character.
Examples:

Input: str1 = "geek", srt2 = "gesek"
Output: 1
Explanation: One operation is required, inserting 's' between two 'e'.
Input : str1 = "gfg", str2 = "gfg"
Output: 0
Explanation: Both strings are same.
 */

    int solve(string s1, string s2, int i, int j) {
        if (i == 0) {
            return j;
        }
        if (j == 0) {
            return i;
        }
        if (s1[i - 1] == s2[j - 1]) {
            return solve(s1, s2, i - 1, j - 1);
        }
        int insert = 1 + solve(s1, s2, i, j - 1);
        int deleted = 1 + solve(s1, s2, i - 1, j);
        int replace = 1 + solve(s1, s2, i - 1, j - 1);
        return min(insert, min(deleted, replace));
    }

    int editDistance(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        return solve(str1, str2, n, m);
    }

int main(){
    string str1 = "geek";
    string str2 = "gesek";
    cout<<editDistance(str1,str2);
return 0;
}