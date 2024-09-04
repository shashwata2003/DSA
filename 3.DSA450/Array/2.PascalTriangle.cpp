#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
Example 2:

Input: numRows = 1
Output: [[1]]
 */

void solve(int i, int numrows, vector<vector<int>> &ans) {
    if (i == 1) {
        ans.push_back({1});
        return;
    }
    if (i == 2) {
        ans.push_back({1, 1});
        return;
    }

    // Ensure we have the previous row
    vector<int> prevRow = ans.back();
    vector<int> temp;
    temp.push_back(1); // Start with the first element which is always 1

    // Fill the middle elements
    for (int j = 1; j < i - 1; j++) {
        temp.push_back(prevRow[j - 1] + prevRow[j]);
    }

    temp.push_back(1); // End with the last element which is always 1
    ans.push_back(temp);
}

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;
    for (int i = 1; i <= numRows; i++) {
        solve(i, numRows, ans);
    }
    return ans;
}

int main(){

return 0;
}