#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Given a binary tree root and a linked list with head as the first node. 

Return True if all the elements in the linked list starting from the head correspond to some downward 
path connected in the binary tree otherwise return False.

In this context downward path means a path that starts at some node and goes downwards.

Input: head = [4,2,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
Output: true
Explanation: Nodes in blue form a subpath in the binary Tree.  
 */

/*
Steps:
Base Cases:

If the head of the linked list is NULL, you return true because you’ve reached the end of the linked list, 
which means you’ve successfully found a matching path.
If the root of the binary tree is NULL but the linked list is not empty, return false since the tree path has 
ended before the linked list was fully matched.
Checking Values:

If the current head->val matches root->val, you move to the next node in the linked list.
Recursive Calls:

You recursively check the left and right subtrees by calling the solve function on root->left and root->right. 
If either returns true, the result is true because only one valid path needs to be found.
Final Check in isSubPath:
The isSubPath function starts the recursive checking from the root of the tree.
*/

class Solution {
private: 
    bool solve(ListNode* head, TreeNode* root){
        if(head == NULL){
            return true;  // Successfully matched entire list
        }
        if(root == NULL){
            return false;  // Tree path ended, no match
        }
        if(head->val == root->val){
            // Move to the next node in the list if the current value matches
            return solve(head->next, root->left) || solve(head->next, root->right);
        }
        return false;
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(root == NULL) {
            return false;  // Tree is empty, no possible match
        }
        // Check if the path starts from the current root or from any of its children
        return solve(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};

int main(){

return 0;
}