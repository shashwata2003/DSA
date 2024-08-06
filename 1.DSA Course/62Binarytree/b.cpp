#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
You are given a Binary tree. You have to count and return the number of leaf nodes present in it.

A binary tree is a tree data structure in which each node has at most two children, which are referred to as 
the left child and the right child

A node is a leaf node if both left and right child nodes of it are NULL.

Solution:
Here we are going to terverse the entire tree using any one of the treversing 
method. if the right and left of the 
root is null hence it is a leaf node. increament the count.
 */


void inorder(BinaryTreeNode<int> * root, int &count) {
    //base case
    if(root == NULL) {
        return ;
    }

    inorder(root->left, count);
   	
    //leaf node
    if(root->left == NULL && root->right == NULL) {
        count++;
    }
    
    inorder(root->right, count);

}


int noOfLeafNodes(BinaryTreeNode<int> *root){
    int cnt = 0;
    inorder(root, cnt);
    return cnt;
}

int main(){

return 0;
}