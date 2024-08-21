#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Flatten Binary Tree to Linked List:
Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node 
in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.

Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [0]
Output: [0]
 */

/*Steps:
we implement theis solution using morrise traversal
*/

class Solution {
public:
    // Function to flatten the binary tree into a linked list in-place
    void flatten(TreeNode* root) {
        TreeNode* curr = root;  // Start from the root of the tree
        
        // Iterate through the tree while 'curr' is not null
        while (curr) {
            // If the current node has a left child
            if (curr->left != NULL) {
                TreeNode* pred = curr->left;  // Find the left child (predecessor)
                
                // Traverse to the rightmost node of the left subtree
                while (pred->right != NULL) {
                    pred = pred->right;
                }
                
                // Connect the rightmost node's right pointer to the current node's right subtree
                pred->right = curr->right;
                
                // Move the entire left subtree to the right
                curr->right = curr->left;
                
                // Set the left pointer of the current node to null
                curr->left = NULL;
            }
            // Move to the right child of the current node
            curr = curr->right;
        }
    }
};
int main(){

return 0;
}