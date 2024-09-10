#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
You are given two integers m and n, which represent the dimensions of a matrix.

You are also given the head of a linked list of integers.

Generate an m x n matrix that contains the integers in the linked list presented in spiral order (clockwise), 
starting from the top-left of the matrix. If there are remaining empty spaces, fill them with -1.

Return the generated matrix.

Input: m = 3, n = 5, head = [3,0,2,6,8,1,7,9,4,2,5,5,0]
Output: [[3,0,2,6,8],[5,0,-1,-1,1],[5,2,4,9,7]]
Explanation: The diagram above shows how the values are printed in the matrix.
Note that the remaining spaces in the matrix are filled with -1.

Input: m = 1, n = 4, head = [0,1,2]
Output: [[0,1,2,-1]]
Explanation: The diagram above shows how the values are printed from left to right in the matrix.
The last space in the matrix is set to -1.

 */

/*
1. Similar to spiral print
*/

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m,vector<int>(n,-1));
        int firstrow = 0;
        int lastcol = n-1;
        int lastrow = m-1;
        int firstcol = 0;
        while(head){
            for(int i = firstcol; i <= lastcol && head; i++){
                ans[firstrow][i] = head->val;
                head = head->next;
            }
            firstrow++;
            for(int i = firstrow; i <= lastrow && head; i++){
                ans[i][lastcol] = head->val;
                head = head->next;
            }
            lastcol--;
            for(int i = lastcol; i >= firstcol && head; i--){
                ans[lastrow][i] = head->val;
                head = head->next;
            }
            lastrow--;
            for(int i = lastrow; i >= firstrow && head; i--){
                ans[i][firstcol] = head->val;
                head = head->next;
            }
            firstcol++;
        }
        return ans;
    }
};

int main(){

return 0;
}