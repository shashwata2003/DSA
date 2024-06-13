#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* Validate Subtree:
Given a binary tree with N number of nodes, check if that input tree is Partial BST (Binary Search Tree) or
not. If yes, return true, return false otherwise.
Eg:
Sample Input 1:
2
3 1 5 -1 2 -1 -1 -1 -1
3 2 5 1 4 -1 -1 -1 -1 -1 -1
Sample Output 1:
 true
 false

Sol:
Apporach 1:
Simple apporach will to print the entire tree in inorder mode and checking printed array weather it is sorted
or not.

Apporach 2:
Using recursion:
Base case if root == NULL return true
 here we assume that each node has a range attached to it
eg the root node should be in the range of - infinity to + infinity
the left of the root should be in the range fo - infinity to root->data
and the right of the root should be in the range of root->data to +inifinity

Similarily each node will have some range and each node should be in that range and if so then the BSt
is validated.

TS: o(N)
SP: o(height)

 */

class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildBSTtree(Node* root) {
    int data;
    cin >> data;
    if (data == -1) {
        return NULL;
    }
    root = new Node(data);
    cout << "Enter left of " << data << endl;
    root->left = buildBSTtree(root->left);
    cout << "Enter right of " << data << endl;
    root->right = buildBSTtree(root->right);
    return root;
}

bool solve(Node* root, int max, int min) {
    if (root == NULL) {
        return true;
    }
    if (root->data > min && root->data < max) {
        bool left = solve(root->left, root->data, min);
        bool right = solve(root->right, max, root->data);
        return left && right;
    } else {
        return false;
    }
}

bool isvalidated(Node* root) {
    return solve(root, INT_MAX, INT_MIN);
}

int main() {
    Node* root = NULL;
    root = buildBSTtree(root);
    if (isvalidated(root)) {
        cout << "The tree is a valid BST" << endl;
    } else {
        cout << "The tree is not a valid BST" << endl;
    }
    return 0;
}