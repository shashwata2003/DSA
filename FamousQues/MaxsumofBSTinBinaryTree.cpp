#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Given a binary tree root, return the maximum sum of all keys of any sub-tree which is also a Binary Search 
Tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class info{
    public:
    int maxi;
    int mini;
    bool isBST;
    int sum;
};

info solve(TreeNode* root, int &maxsum){
    if (root == NULL)
        return { INT_MIN, INT_MAX, true, 0 };

    if(root->left == NULL && root->right == NULL){
        maxsum = max(maxsum, root->val);
        return {root->val,root->val,true,root->val};
    }

    info left = solve(root->left,maxsum);
    info right = solve(root->right,maxsum);

    info ans;
    if(left.isBST && right.isBST && left.maxi < root->val && right.mini > root->val){
        ans.isBST = true;
        ans.maxi = max(max(left.maxi, right.maxi), root->val);
        ans.mini = min(min(left.mini, right.mini), root->val);
        int sum = root->val + left.sum + right.sum;
        maxsum = max(maxsum,sum);
        ans.sum = sum;
        return ans; 
    }
    else{
        ans.isBST=false;
        ans.sum =root->val + left.sum + right.sum;
    }
    return ans;
}


  int maxSumBST(TreeNode* root) {
        int maxsum = INT_MIN;
        info ans = solve(root, maxsum); // Pass maxsum by reference here
        return maxsum < 0 ? 0 : maxsum; // Return maxsum instead of ans.sum
    }

int main(){

return 0;
}