#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Given a binary tree root, return the maximum sum of all keys of any sub-tree which is also a Binary 
Search Tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 */
class Solution {
private:
    // Helper class to store information about the current subtree
    class info {
    public:
        int maxi;  // Maximum value in the subtree
        int mini;  // Minimum value in the subtree
        int sum;   // Sum of all node values in the subtree
        bool isBST; // Indicates if the subtree is a valid BST
    };

    // Recursive function to solve the problem for each subtree
    info solve(TreeNode* root, int &maxsum) {
        // Base case: If the node is NULL, return extreme values and mark as non-BST
        if (root == nullptr) {
            return {INT_MIN, INT_MAX, 0, true}; // Updated the sum to 0 for empty trees
        }

        // If the node is a leaf, it is a valid BST by itself
        if (root->left == nullptr && root->right == nullptr) {
            maxsum = max(maxsum, root->val);
            return {root->val, root->val, root->val, true};
        }

        // Recursively solve for left and right subtrees
        info left = solve(root->left, maxsum);
        info right = solve(root->right, maxsum);
        
        // Initialize the current node's info
        info ans;
        
        // Check if the current subtree rooted at `root` is a valid BST
        if (left.isBST && right.isBST && root->val > left.maxi && root->val < right.mini) {
            ans.isBST = true;
            ans.maxi = max(max(right.maxi, left.maxi), root->val);
            ans.mini = min(min(right.mini, left.mini), root->val);
            ans.sum = left.sum + right.sum + root->val;
            maxsum = max(maxsum, ans.sum); // Update the maximum sum if this subtree is a valid BST
        } else {
            // If it's not a BST, mark it as false and accumulate the sum
            ans.isBST = false;
            ans.sum = left.sum + right.sum + root->val;
        }

        return ans;
    }

public:
    // Function to find the maximum sum of a valid BST within the binary tree
    int maxSumBST(TreeNode* root) {
        int maxsum = 0;  // Initialize maxsum as 0 to handle the case where no valid BST exists
        solve(root, maxsum); // Call the recursive function to start solving the problem
        return maxsum;  // Return the maximum sum found
    }
};
int main(){

return 0;
}