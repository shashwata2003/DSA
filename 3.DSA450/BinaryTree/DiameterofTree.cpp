#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  
Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. 
This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.
*/

class Solution {
public:
    // Helper function to find both the height and diameter of the binary tree
    pair<int, int> findheightanddiameter(TreeNode* root) {
        // Base case: if the node is null, both height and diameter are 0
        if (root == NULL) {
            return {0, 0};
        }

        // Recursively find the height and diameter of the left subtree
        pair<int, int> left = findheightanddiameter(root->left);
        // Recursively find the height and diameter of the right subtree
        pair<int, int> right = findheightanddiameter(root->right);

        // Initialize the answer pair
        pair<int, int> ans;
        // The height of the current node is 1 + the maximum height of the left and right subtrees
        ans.first = 1 + max(left.first, right.first);
        // The diameter of the current node is the maximum of:
        // 1. The diameter of the left subtree
        // 2. The diameter of the right subtree
        // 3. The sum of the heights of the left and right subtrees
        ans.second = max(left.second, max(right.second, left.first + right.first));
        
        return ans;
    }

    // Function to find the diameter of the binary tree
    int diameterOfBinaryTree(TreeNode* root) {
        // The diameter of the tree is the second element of the pair returned by findheightanddiameter
        int ans = findheightanddiameter(root).second;
        return ans;
    }
};

int main(){

return 0;
}