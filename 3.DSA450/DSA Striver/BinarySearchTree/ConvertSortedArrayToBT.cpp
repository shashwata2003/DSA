#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Convert Sorted Array to Binary Search Tree:
Given an integer array nums where the elements are sorted in ascending order, convert it to a 
height-balanced binary search tree.
Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted
 */

 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };


/*
Steps:
Find the mid and create a node of it 
call the recursive function for the left and right
*/

class Solution {
public:
    // Recursive function to build a BST from a sorted array
    TreeNode* solve(vector<int>& nums, int s, int e) {
        // Base case: if the start index exceeds the end index, return NULL
        if (s > e) {
            return NULL;
        }
        
        // Calculate the middle index to get the root of the current subtree
        int mid = s + (e - s) / 2;
        
        // Create a new TreeNode with the middle element
        TreeNode* ans = new TreeNode(nums[mid]);
        
        // Recursively build the left and right subtrees
        ans->left = solve(nums, s, mid - 1);
        ans->right = solve(nums, mid + 1, e);
        
        // Return the root of the subtree
        return ans;
    }

    // Function to convert a sorted array into a height-balanced BST
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // Call the recursive solve function with the entire range of the array
        return solve(nums, 0, nums.size() - 1);
    }
};

int main(){

return 0;
}