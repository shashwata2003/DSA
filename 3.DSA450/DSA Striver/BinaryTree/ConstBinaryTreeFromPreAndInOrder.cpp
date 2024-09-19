#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Construct Binary Tree from Preorder and Inorder Traversal:
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary 
tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: preorder = [-1], inorder = [-1]
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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int prestart, int instart, 
                    int inend, int n, unordered_map<int, int>& mp) {
        // Base case: If the prestart index exceeds the size of preorder or instart exceeds inend
        if (prestart >= n || instart > inend) {
            return nullptr;
        }

        // Get the current root node from preorder traversal
        int node = preorder[prestart];
        TreeNode* root = new TreeNode(node);

        // Find the position of the current node in inorder traversal
        int pos = mp[node];

        // Recursively construct the left subtree
        root->left = solve(preorder, inorder, prestart + 1, instart, pos - 1, n, mp);

        // Recursively construct the right subtree
        // The new prestart for the right subtree will be prestart + (pos - instart) + 1
        // This moves the prestart index forward by the size of the left subtree
        root->right = solve(preorder, inorder, prestart + (pos - instart) + 1, pos + 1, inend, n, mp);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();

        // Create a hashmap to store the index of each value in inorder traversal
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }

        // Initial call to the recursive function
        return solve(preorder, inorder, 0, 0, n - 1, n, mp);
    }
};


int main(){

return 0;
}