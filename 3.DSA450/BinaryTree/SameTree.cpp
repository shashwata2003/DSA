#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

Input: p = [1,2,3], q = [1,2,3]
Output: true

Input: p = [1,2], q = [1,null,2]
Output: false
 */

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Base case: If both nodes are null, the trees are identical (at this level)
        if (p == nullptr && q == nullptr) {
            return true;
        }
        
        // If one is null and the other isn't, the trees are not identical
        if (p == nullptr || q == nullptr) {
            return false;
        }
        
        // If the values of the current nodes are different, the trees are not identical
        if (p->val != q->val) {
            return false;
        }
        
        // Recursively check the left and right subtrees
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};


int main(){

return 0;
}