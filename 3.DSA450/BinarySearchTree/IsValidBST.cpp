#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  */
/*
Steps:
1. we will keep a range for each node as min and max if the nodes value is between that then we call it valid 
*/
class Solution {
public:
    // Helper function to recursively validate the BST
    bool solve(TreeNode* root, long maxi, long mini) {
        // Base case: if the node is NULL, it's valid
        if (root == nullptr) {
            return true;
        }
        
        // Check if the current node's value is within the valid range
        if (root->val <= mini || root->val >= maxi) {
            return false;
        }
        
        // Recursively validate the left and right subtrees with updated ranges
        bool left = solve(root->left, root->val, mini);
        bool right = solve(root->right, maxi, root->val);
        
        // The current subtree is valid if both left and right subtrees are valid
        return left && right;
    }
    
    // Main function to check if the tree is a valid BST
    bool isValidBST(TreeNode* root) {
        // Start with the full range of valid values for a BST
        return solve(root, LONG_MAX, LONG_MIN);
    }
};
int main(){

return 0;
}