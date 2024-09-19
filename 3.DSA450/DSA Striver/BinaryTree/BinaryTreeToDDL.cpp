#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  
Convert Binary Tree to Doubly Linked List by keeping track of visited node:

https://www.geeksforgeeks.org/convert-binary-tree-to-doubly-linked-list-by-keeping-track-of-visited-node/

Using Morrise traversal:

*/

// Function to convert binary tree to doubly linked list
Node* bToDLL(Node* root) {
    // Initialization
    Node* curr = root;
    Node* prev = nullptr; // Used to keep track of prev node
    Node* final_head = nullptr; // Used to return the final head

    // Traverse the tree
    while (curr) {
        // If no left child
        if (!curr->left) {
            // If final_head is not set, set it to current node
            if (!final_head) {
                prev = curr;
                final_head = curr;
            } else {
                // Set next of prev as curr and prev of curr as prev
                prev->right = curr;
                curr->left = prev;
            }
            // Set the new prev node
            prev = curr;
            curr = curr->right;
        } else {
            // If left child exists
            Node* pre = curr->left;
            while (pre->right && pre->right != curr) {
                pre = pre->right;
            }
            if (!pre->right) {
                pre->right = curr;
                curr = curr->left;
            } else {
                curr = pre->right;
                // Set next of prev as curr and prev of curr as prev
                prev->right = curr;
                curr->left = prev;
                // Set the new prev node
                prev = curr;
                curr = curr->right;
            }
        }
    }

    return final_head; // Return the final head of the linked list
}

int main(){

return 0;
}