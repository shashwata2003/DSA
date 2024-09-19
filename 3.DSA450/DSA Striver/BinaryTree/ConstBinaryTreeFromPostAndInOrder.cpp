#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
 Construct Binary Tree from Inorder and Postorder Traversal
Given two integer arrays inorder and postorder where inorder is the inorder traversal of a 
binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: inorder = [-1], postorder = [-1]
Output: [-1]
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    // Recursive function to build the tree
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int instart,
                    int inend, int poststart, unordered_map<int, int>& mp) {
        // Base case: if the indices are out of valid range
        if (instart > inend || poststart < 0) {
            return nullptr;
        }

        // Get the current root node from postorder traversal
        int node = postorder[poststart];
        TreeNode* root = new TreeNode(node);

        // Find the position of the current node in inorder traversal
        int pos = mp[node];

        // Recursively construct the right subtree first (since postorder processes right subtree last)
        root->right = solve(inorder, postorder, pos + 1, inend, poststart - 1, mp);
        
        // Recursively construct the left subtree
        root->left = solve(inorder, postorder, instart, pos - 1, poststart - (inend - pos + 1), mp);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        
        // Create a hashmap to store the index of each value in inorder traversal
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }

        // Initial call to the recursive function
        return solve(inorder, postorder, 0, n - 1, n - 1, mp);
    }
};

int main(){

return 0;
}