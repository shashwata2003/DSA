#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*
Convert BST to Min Heap:
Given a binary search tree which is also a complete binary tree. The problem is to convert the given BST into 
a Min Heap with the condition that all the values in the left subtree of a node should be less than all the 
values in the right subtree of the node. This condition is applied to all the nodes, in the resultant converted
 Min Heap.
 Input:       4
                /   \
              2     6
            /  \   /  \
          1   3  5    7  
Output:  1
               /   \
             2     5
           /  \   /  \
         3   4  6    7    


Solution:
As given tree is already CBT hence there will no change in the structure just we need to arrage the node.
Here we use the inorder and preorder traversal method to find the ans
steps:
1.Create an array arr[] of size N, where N is the number of nodes in the given BST.
2.Perform the inorder traversal of the BST and copy the node values in the arr[] in sorted order.
3.Now perform the preorder traversal of the tree.
4.While traversing the root during the preorder traversal, one by one copy the values from the array arr[] 
to the nodes of the BST.
*/
int main(){

return 0;
}