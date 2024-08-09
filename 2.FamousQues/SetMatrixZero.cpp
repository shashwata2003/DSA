#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Set Matrix Zeroes
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
 */

void replacerowandcol(vector<vector<int>>& matrix, int row, int col){
    int x = row;
    int y = col;
    while(y >= 0){
        matrix[row][y] = 0;
        y--;
    }
    y = col;
    while(y < matrix[0].size()){
        matrix[row][y] = 0;
        y++;
    }

    while(x >= 0){
        matrix[x][col] = 0;
        x--;
    }

    while(x < matrix.size()){
        matrix[x][col] = 0;
        x++;
    }
}

void setZeroes(vector<vector<int>>& matrix) {
    for(int i = 0; i<matrix.size(); i++){
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if(matrix[i][j] == 0){
                replacerowandcol(matrix,i,j);
            }
        }
        
    }        
}
int main(){

return 0;
}