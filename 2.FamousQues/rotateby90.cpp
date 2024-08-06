#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Rotate Image:
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. 
DO NOT allocate another 2D matrix and do the rotation.

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]

Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

Sol:
First transpose the matrix
the rotate each row of the matrix 
we will get the final rotated matrix:
 */

void rotate(vector<vector<int>>& arr) {
    //Transpose:
    int row = arr.size();
    int col = arr[0].size();
    for (int i = 0; i < row; i++)
    {
        for (int j = i+1; j < col; j++)
        {
            if(i!=j){
                swap(arr[i][j],arr[j][i]);
            }
        }
    }

    //Reverse each row:
    for (int i = 0; i < row; i++)
    {
        int k = 0;
        int j = col - 1;
        while(k<j){
            swap(arr[i][k],arr[i][j]);
            k++;
            j--;
        }
    }
}

int main(){
 vector<vector<int>> arr = {{1,2,3},{4,5,6},{7,8,9}};
    rotate(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            cout<<arr[i][j]<<" ";
        }
        
    }
    
return 0;
}