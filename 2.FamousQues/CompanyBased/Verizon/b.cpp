#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Given an input string and a substring. Find the frequency of occurrences of a substring in a given string.
Examples: 
Input : man (pattern)
        dhimanman (string)
Output : 2

Input : nn (pattern)
        Banana (String)
Output : 0

Input : man (pattern)
        dhimanman (string)
Output : 2

Input : aa (pattern)
        aaaaa (String)
Output : 4
 */

int solve(string pattern, string str) {
    int n = pattern.length();
    int cnt = 0;
    for (int i = 0; i <= str.length() - n; i++) {  // Iterate till str.length() - n
        string s = str.substr(i, n);
        if (s == pattern) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    string pattern;
    getline(cin, pattern);
    string str;
    getline(cin, str);
    cout << solve(pattern, str);  // Fix: Added missing <<
    return 0;
}