#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Maximum Depth of Binary Tree:

Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the
farthest leaf node.
 */

int solve(TreeNode* root){
    if(root == NULL){
         return 0;
    }
    int left = solve(root->left);
    int right = solve(root->right);
    return 1+ max(left,right);
}
int maxDepth(TreeNode* root) {
    int count = solve(root);;
    
    return count;
}
int main(){

return 0;
}