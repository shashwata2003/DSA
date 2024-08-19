#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Construct Full Binary Tree from given preorder and postorder traversals
Given two arrays that represent preorder and postorder traversals of a full binary tree, construct 
the binary tree. Full Binary Tree is a binary tree where every node has either 0 or 2 children.

pre[] = {1, 2, 4, 8, 9, 5, 3, 6, 7} and post[] = {8, 9, 4, 5, 2, 6, 7, 3, 1}; 

 */

class TreeNode {
public:
    int data;
    node* left;
    node* right;
};

TreeNode* solve(vector<int>& preorder, vector<int>& postorder, int ps, int l, int h, ,int n){
    if(ps >= n){
        return NULL;
    }
    if(l>h){
        return NULL;
    }

    TreeNode* root = new TreeNode(preorder[ps]);
    ps++;
    if(l == h){
        return root;
    }
    //find the current val in postorder arr:
    int i;
    for (i = l; i <= h; i++)
    {
        if(preorder[ps] == post[i]){
            break;
        }
    }

    if(i<=h){
        root->left = solve(preorder,postorder,ps,l,i-1,n);
        root->right = solve(preorder,postorder,ps,i+1,h-1,n);
    }
    
    return root;
}

TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
    int prestart = 0;
    int n = preorder.size();
    int l = 0;
    int h = n-1;
    TreeNode* ans = solve(preorder,postorder,prestart,l,h,n);

    return ans;        
}

int main(){

return 0;
}