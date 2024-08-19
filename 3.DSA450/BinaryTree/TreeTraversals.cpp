#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Problem statement
You have been given a Binary Tree of 'N'

nodes, where the nodes have integer values.



Your task is to return the ln-Order, Pre-Order, and Post-Order traversals of the given binary tree.

Sample Input 1 :
1 2 3 -1 -1 -1  6 -1 -1
Sample Output 1 :
2 1 3 6 
1 2 3 6 
2 6 3 1
Inorder traversal of given tree = [2, 1, 3, 6]
Preorder traversal of given tree = [1, 2, 3, 6]
Postorder traversal of given tree = [2, 6, 3, 1]

Sample Input 2 :
1 2 4 5 3 -1 -1 -1 -1 -1 -1
Sample Output 2 :
5 2 3 1 4 
1 2 5 3 4 
5 3 2 4 1
 */


void inordertraversal(TreeNode* root, vector<int> &temp){
    if(root == NULL){
        return;
    }
    inordertraversal(root->left, temp);
    temp.push_back(root->data);
    inordertraversal(root->right, temp);
}

void postordertraversal(TreeNode* root, vector<int> &temp){
    if(root == NULL){
        return;
    }
    postordertraversal(root->left, temp);
    postordertraversal(root->right, temp);
    temp.push_back(root->data);
}

void preordertraversal(TreeNode* root, vector<int> &temp){
    if(root == NULL){
        return;
    }
    temp.push_back(root->data);
    preordertraversal(root->left, temp);
    preordertraversal(root->right, temp);
}

vector<vector<int>> getTreeTraversal(TreeNode *root){
    vector<vector<int>> ans;
    vector<int> temp;
    inordertraversal(root,temp);
    ans.push_back(temp);
    temp.clear();
    preordertraversal(root,temp);
    ans.push_back(temp);
    temp.clear();
    postordertraversal(root,temp);
    ans.push_back(temp);
    temp.clear();
    
    return ans;
}

int main(){

return 0;
}