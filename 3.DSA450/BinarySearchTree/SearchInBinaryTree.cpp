#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
You are given the root of a binary search tree (BST) and an integer val.

Find the node in the BST that the node's value equals val and return the subtree rooted with that node. 
If such a node does not exist, return null.

Input: root = [4,2,7,1,3], val = 2
Output: [2,1,3]
 */

class Solution {
public:
    // Function to search for a node with the given value in a BST
    TreeNode* searchBST(TreeNode* root, int val) {
        // Base case: if the tree is empty, return NULL
        if (root == NULL) {
            return NULL;
        }
        
        // Queue for level-order traversal (BFS)
        queue<TreeNode*> q;
        q.push(root);
        
        // While there are nodes to process in the queue
        while (!q.empty()) {
            // Get the front node of the queue
            TreeNode* temp = q.front();
            q.pop();
            
            // If the current node has the target value, return the node
            if (temp->val == val) {
                return temp;
            }
            
            // Push the left child into the queue if it exists
            if (temp->left) {
                q.push(temp->left);
            }
            
            // Push the right child into the queue if it exists
            if (temp->right) {
                q.push(temp->right);
            }
        }
        
        // If the value is not found in the tree, return NULL
        return NULL;
    }
};


int main(){

return 0;
}