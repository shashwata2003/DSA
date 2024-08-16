#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Spiral Print:
 */

vector<int> spiralPathMatrix(vector<vector<int>> matrix, int n, int m) 
{
    int firstrow = 0;
    int lastrow = n-1;
    int firstcol = 0;
    int lastcol = m-1;
    int total = n*m;
    int count = 0;
    vector<int> ans;

    while(count < total){
        //first row
        for(int i = firstcol; i <= lastcol ; i++){
            if(count<total){
                ans.push_back(matrix[firstrow][i]);
                count++;
            }
        }
        firstrow++;
        //lastcol
        for (int i = firstrow; i <= lastrow; i++)
        {
            if(count<total){
                ans.push_back(matrix[i][lastcol]);
                count++;
            }
        }
        lastcol--;
        //last row
        for (int i = lastcol; i >= firstcol; i--)
        {
            if(count<total){
                ans.push_back(matrix[lastrow][i]);
                count++;
            }
        }
        lastrow--;
        //first col;
        for (int i = lastrow; i >= firstrow; i--)
        {
            if(count<total){
                ans.push_back(matrix[i][firstcol]);
                count++;
            }
        }
        firstcol++;
    }
    return ans;
}

int main(){

return 0;
}