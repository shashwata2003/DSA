#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p 
and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant 
of itself).”

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
Example 2:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.


 */

class Solution {
public:
    // Function to find the lowest common ancestor of two given nodes in a binary tree
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: if the current node is NULL, return NULL (no ancestor found)
        if (root == nullptr) {
            return nullptr;
        }
        
        // If the current node matches either p or q, return the current node
        // This indicates that we have found one of the nodes (p or q)
        if (root->val == p->val || root->val == q->val) {
            return root;
        }
        
        // Recursively search for p and q in the left and right subtrees
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        // If both left and right are non-null, it means p and q are found in
        // different subtrees, so the current node is their lowest common ancestor
        if (left != nullptr && right != nullptr) {
            return root;
        }
        
        // If one of the subtrees returns a non-null value, it means both p and q
        // are found in that subtree, so return that non-null value
        if (left != nullptr && right == NULL) {
            return left;
        }
        
        if (right != nullptr && left == NULL) {
            return right;
        }
        else{
            // If neither subtree contains p or q, return NULL
            return nullptr;
        }

        
    }
};


int main(){

return 0;
}