#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p 
and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant 
of itself).”

Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.

Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
 */


/*
1.if both the values are less then the root then we move the curr to left side 
2.else to the right tree.
3. if values are different then then the curr node is the ans.
*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: if the root is null, return null
        if (root == nullptr) {
            return nullptr;
        }

        // Iterative approach to find the LCA
        while (root != nullptr) {
            // If both p and q are less than root, LCA lies in the left subtree
            if (root->val > p->val && root->val > q->val) {
                root = root->left;
            }
            // If both p and q are greater than root, LCA lies in the right subtree
            else if (root->val < p->val && root->val < q->val) {
                root = root->right;
            }
            // If p and q lie on opposite sides, or one of them equals root, root is the LCA
            else {
                return root;
            }
        }

        // Return null if no LCA is found (although in a valid BST this should never happen)
        return nullptr;
    }
};

/* recursion:*/
Node* findLCA(Node* root , int p , int q){
    if(root == NULL){
        return NULL;
    }
    if(root->data > p && root->data > q){
        return findLCA(root->left,p,q);
    }
    if(root->data < p && root->data < q){
        return findLCA(root->right,p,q);
    }
    return root;
}

int main(){

return 0;
}