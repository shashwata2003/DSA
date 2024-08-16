#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  
Problem statement
Given an integer ‘N’ representing the number of pairs of parentheses, Find all the possible combinations of 
balanced parentheses with the given number of pairs of parentheses.

Note :

Conditions for valid parentheses:
1. All open brackets must be closed by the closing brackets.

2. Open brackets must be closed in the correct order.
For Example :

()()()() is a valid parentheses.
)()()( is not a valid parentheses.
*/

void solve(vector<string> &ans, string &curr, int open, int close) {
    if (open == 0 && close == 0) {
        ans.push_back(curr);
        return;
    }
    if (open > 0) {
        curr.push_back('(');
        solve(ans, curr, open - 1, close);
        curr.pop_back();
    }
    if (close > open) {  // Corrected condition
        curr.push_back(')');
        solve(ans, curr, open, close - 1);
        curr.pop_back();
    }
}

vector<string> balancedParantheses(int n) {
    vector<string> ans;
    string curr = "";
    int open = n, close = n;
    solve(ans, curr, open, close);
    return ans;
}

int main(){

return 0;
}