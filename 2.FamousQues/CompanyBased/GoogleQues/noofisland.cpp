#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
No. of Island:
given n*m matrix of 0 and 1 , we need to find the no. of island possible with the given matrix
island is consider when there are consigutive 1 in the arr
 */

void removezeros(vector<vector<int>> &arr, int n , int m, int row, int col){
    if(row<0 || row > n-1 || col < 0 || col > m-1 || arr[row][col] == 0){
        return;
    }
    arr[row][col] = 0;
    removezeros(arr,n,m,row-1,col);
    removezeros(arr,n,m,row+1,col);
    removezeros(arr,n,m,row,col+1);
    removezeros(arr,n,m,row,col-1);
}

int countisland(vector<vector<int>> arr, int n , int m){
    int count = 0;
    for(int i = 0 ; i<n; i++){
        for (int j = 0; j < m; j++)
        {
            if(arr[i][j] == 1){
                count++;
                removezeros(arr,n,m,i,j);
            }
        }
        
    }
    return count;
}

int main(){
    vector<vector<int>> arr = {{1,1,0,0,0},{1,1,0,0,0},{0,0,1,0,0},{0,0,0,1,1}};
    int n = 2, m = 5;
    cout<<countisland(arr,n,m);
    return 0;
}