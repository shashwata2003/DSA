#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* Construct Binary Search Tree from Preorder Traversal:

Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), 
construct the tree and return its root.

It is guaranteed that there is always possible to find a binary search tree with the given requirements 
for the given test cases.

A binary search tree is a binary tree where for every node, any descendant of Node.left has a value 
strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.

A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, 
then traverses Node.right.

Input: preorder = [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]
Example 2:

Input: preorder = [1,3]
Output: [1,null,3]
 
 */

class Solution {
public:
    // Recursive function to insert a new value into the BST
    TreeNode* solve(TreeNode* root, int data) {
        // Base case: if the current node is NULL, create a new node with the data
        if (root == nullptr) {
            return new TreeNode(data);
        }
        
        // If the data is greater than the current node's value, go to the right subtree
        if (root->val < data) {
            root->right = solve(root->right, data);
        }
        // If the data is less than or equal to the current node's value, go to the left subtree
        else {
            root->left = solve(root->left, data);
        }
        
        // Return the root after insertion
        return root;
    }

    // Function to construct a BST from preorder traversal
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // Create the root of the BST with the first element of the preorder array
        TreeNode* root = new TreeNode(preorder[0]);
        
        // Iterate through the rest of the preorder array and insert each element into the BST
        int n = preorder.size();
        for (int i = 1; i < n; i++) {
            solve(root, preorder[i]);
        }
        
        // Return the root of the constructed BST
        return root;
    }
};


int main(){

return 0;
}