#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Symetric Tree:
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center). */


class Solution {
private:
    // Helper function to check if two subtrees are mirror images
    bool solve(TreeNode* r1, TreeNode* r2) {
        // If both nodes are null, they are symmetric
        if (r1 == nullptr || r2 == nullptr) {
            return r1 == r2;
        }

        // Check if current nodes are equal and subtrees are mirrors
        return (r1->val == r2->val) &&
               solve(r1->left, r2->right) &&
               solve(r1->right, r2->left);
    }

public:
    bool isSymmetric(TreeNode* root) {
        // An empty tree is symmetric
        if (root == nullptr) {
            return true;
        }
        
        // Check if left and right subtrees are symmetric
        return solve(root->left, root->right);
    }
};


int main(){

return 0;
}