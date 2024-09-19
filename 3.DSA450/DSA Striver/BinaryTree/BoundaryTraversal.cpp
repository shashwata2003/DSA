#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Boundary Traversal of a Binary Tree:
Problem Statement: Given a Binary Tree, perform the boundary traversal of the tree. 
The boundary traversal is the process of visiting the boundary nodes of the binary tree in the 
anticlockwise direction, starting from the root.
Example 1:
Input:Binary Tree: 1 2 7 3 -1 -1 8 -1 4 9 -1 5 6 10 11
Output: Boundary Traversal: [1, 2, 3, 4, 5, 6, 10, 11, 9, 8, 7]
Explanation: The boundary traversal of a binary tree involves visiting its boundary nodes in an anticlockwise direction:
				
Starting from the root, we traverse from: 1
The left side traversal includes the nodes: 2, 3, 4
The bottom traversal include the leaf nodes: 5, 6, 10, 11
The right side traversal includes the nodes: 9, 8, 7
We return to the  root and the boundary traversal is complete.
 */

class Node {
public:
    int data;
    Node* left;
    Node* right;
};

// Function to handle the left boundary traversal, excluding the leaf nodes
void leftTraversal(Node* root, vector<int>& ans) {
    if (root == nullptr) return;
    if (root->left == nullptr && root->right == nullptr) return; // Exclude leaf nodes
    
    ans.push_back(root->data); // Add current node to the boundary
    
    if (root->left) {
        leftTraversal(root->left, ans); // Recur on the left child
    } else if (root->right) {
        leftTraversal(root->right, ans); // If left child is absent, recur on the right child
    }
}

// Function to handle the right boundary traversal, excluding the leaf nodes
void rightTraversal(Node* root, vector<int>& ans) {
    if (root == nullptr) return;
    if (root->left == nullptr && root->right == nullptr) return; // Exclude leaf nodes
    
    if (root->right) {
        rightTraversal(root->right, ans); // Recur on the right child
    } else if (root->left) {
        rightTraversal(root->left, ans); // If right child is absent, recur on the left child
    }
    
    ans.push_back(root->data); // Add current node to the boundary after the recursive calls
}

// Function to handle the traversal of all leaf nodes
void leafTraversal(Node* root, vector<int>& ans) {
    if (root == nullptr) return;
    
    if (root->left == nullptr && root->right == nullptr) {
        ans.push_back(root->data); // Add leaf node
        return;
    }
    
    leafTraversal(root->left, ans);  // Recur on the left subtree
    leafTraversal(root->right, ans); // Recur on the right subtree
}

// Function to perform the boundary traversal of a binary tree
vector<int> BoundaryTraversal(Node* root) {
    vector<int> ans;
    
    if (root == nullptr) return ans; // Handle empty tree
    
    ans.push_back(root->data); // Add root node to the boundary
    
    // Traverse the left boundary, excluding the leaf nodes
    if (root->left) {
        leftTraversal(root->left, ans);
    }
    
    // Traverse all the leaf nodes (left subtree + right subtree)
    leafTraversal(root->left, ans);
    leafTraversal(root->right, ans);
    
    // Traverse the right boundary, excluding the leaf nodes
    if (root->right) {
        rightTraversal(root->right, ans);
    }
    
    return ans;
}


int main(){

return 0;
}