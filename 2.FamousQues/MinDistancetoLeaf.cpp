#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* Find the distance form k to the closest leaf node */



/*
steps:
1.from the current node find the k val nod and check which way is shorted
i vai parent or directly
2. to find distance through parent we need to find the k val node first in the left and then right 
3. after it return a val increase the lvl by 2 and find the leaf node in the opposite tree
like if k is found in left tree then find the leaf in the right and viceverse
*/

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Function to find the closest leaf node starting from a given node
void distfromdown(Node* root, int lvl, int &mindist) {
    if (root == NULL) {
        return;
    }

    // If the node is a leaf
    if (root->left == NULL && root->right == NULL) {
        if (lvl < mindist) {
            mindist = lvl;
        }
        return;
    }

    distfromdown(root->left, lvl + 1, mindist);
    distfromdown(root->right, lvl + 1, mindist);
}

// Function to find the minimum distance to a leaf node through parent nodes
int distthroughparent(Node* root, int k, int &mindist) {
    if (root == NULL) {
        return -1;
    }
    if (root->data == k) {
        return 0;
    }

    // Search in the left subtree
    int l = distthroughparent(root->left, k, mindist);

    // If the node is found in the left subtree
    if (l != -1) {
        distfromdown(root->right, l + 2, mindist);
        return l + 1;
    }

    // Search in the right subtree
    int r = distthroughparent(root->right, k, mindist);

    // If the node is found in the right subtree
    if (r != -1) {
        distfromdown(root->left, r + 2, mindist);
        return r + 1;
    }

    return -1;
}

// Main function to find the closest leaf to the node with value k
int ClosestLeaf(Node* root, int k) {
    int mindist = INT_MAX;
    distfromdown(root, 0, mindist); // Check the distance to leaves in the entire tree
    distthroughparent(root, k, mindist); // Adjust the distance considering the parent nodes
    return mindist;
}

// Test the function
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(8);

    int k = 2;
    cout << "The closest leaf to node " << k << " is at distance: " << ClosestLeaf(root, k) << endl;

    return 0;
}

