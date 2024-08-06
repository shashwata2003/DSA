#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Search 2D matrix II:
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. 
This matrix has the following properties:
Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom. 
Sol:
we cannot use mid concept as the overall array is not sorted. So we need to start from the right most corner 
of the matrix because if that is > target then the ans will be in our first row and if other wise then in other
rows or column.
so then it is > targer we move in col-- else row++
*/
int main(){
    vector<vector<int>> arr = {{1,4,7,11,15}, {2,5,8,12,19}, {3,6,9,16,22}, {10,13,14,17,24},{18,21,23,26,30}};
    int rows = arr.size();
    int cols = arr[0].size();
    int target = 31;

    int rowindex = 0;
    int colindex = cols-1;
    while (rowindex<rows && colindex>=0)
    {
        int element = arr[rowindex][colindex];
        if(element == target){
            cout<<"found"<<endl;
        }
        if(element>target){
            colindex--;
        }
        else{
            rowindex++;
        }
    }
    cout<<"not found"<<endl;
    
return 0;
}