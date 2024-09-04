#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
You must do it in place.

Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
*/

class Solution {
private:
    void setrowzero(vector<vector<int>>& matrix, int row, vector<vector<bool>> &visited){
        int n = matrix[0].size();
        for(int i = 0; i<n; i++){
            if(matrix[row][i] != 0){
                matrix[row][i] = 0;
                visited[row][i] = true;
            }
        }
    }
    void setcolzero(vector<vector<int>>& matrix, int col, vector<vector<bool>> &visited){
        int n = matrix.size();
        for(int i = 0; i<n; i++){
            if(matrix[i][col] != 0){
                matrix[i][col] = 0;
                visited[i][col] = true;
            }
        }
    }
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(visited[i][j] == false){
                    if(matrix[i][j] == 0){
                        setrowzero(matrix,i,visited);
                        setcolzero(matrix,j,visited);
                    }
                }
            }
        }
    }
};

int main(){

return 0;
}