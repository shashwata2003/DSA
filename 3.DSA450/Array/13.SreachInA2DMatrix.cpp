#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
 */

/*Using a simple logic*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int targetrow = -1;
        
        // Find the target row
        for (int i = 0; i < n; i++) {
            if (target >= matrix[i][0] && target <= matrix[i][m - 1]) {
                targetrow = i;
                break;  // Found the target row, no need to continue the loop
            }
        }
        
        // If no valid row is found, return false
        if (targetrow == -1) return false;
        
        // Search for the target in the identified row
        for (int i : matrix[targetrow]) {
            if (i == target) {
                return true;
            }
        }
        
        return false;
    }
};


/*USing Binary Search:*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=-1;
        for(int i=0;i<matrix.size();i++)
        {
            int n=matrix[0].size();
            if(matrix[i][0]<=target && target<=matrix[i][n-1])
            {
                int low=0;
                int high=matrix[0].size()-1;
                //Binary Search
                while(low<=high)
                {
                    int mid=low+(high-low)/2;
                    if(matrix[i][mid]==target)
                    {
                        return true;
                    }
                    else if(matrix[i][mid]>target)
                    {
                        high=mid-1;
                    }
                    else if(matrix[i][mid]<target)
                    {
                        low=mid+1;
                    }
                }
            }
        }
        return false;
    }
};

int main(){

return 0;
}