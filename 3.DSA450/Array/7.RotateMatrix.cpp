#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. 
DO NOT allocate another 2D matrix and do the rotation.
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]

Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
*/

/*
Here we are going to find the transpose of the matrix and rever each row of the transposed matrix.
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        // Finding the transpose
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < m; j++) {
                if (i != j) {
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
        }

        // Reversing each row
        for(int i = 0; i<n; i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};

int main(){

return 0;
}