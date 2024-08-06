#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Spiral Print:
Given an m x n matrix, return all elements of the matrix in spiral order.

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

 */

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int row = matrix.size();
    int col = matrix[0].size();

    vector<int> ans;

    if(row == 0 || col == 0){
        return ans;
    }

    int firstrow = 0;
    int lastrow = row -1;
    int firstcol = 0;
    int lastcol = col -1;

    int count = 0;
    int total = row*col;

    while (count<total)
    {
        //first row:
        for (int i = firstcol; count<total && i <= lastcol; i++)
        {
            ans.push_back(matrix[firstrow][i]);
            count++;
        }
        firstrow++;
        
        //last col:
        for (int i = firstrow; count<total && i <= lastrow; i++)
        {
            ans.push_back(matrix[i][lastcol]);
            count++;
        }
        lastcol--;
        
        //last row:
        for (int i = lastcol; count<total && i >= firstcol; i--)
        {
            ans.push_back(matrix[lastrow][i]);
            count++;
        }
        lastrow--;

        //first col:
        for (int i = lastrow; count<total && i >= firstrow; i--)
        {
            ans.push_back(matrix[i][firstcol]);
            count++;
        }
        firstcol++;
    }
    return ans;
}

int main(){
    vector<vector<int>> arr = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> ans = spiralOrder(arr);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
return 0;
}