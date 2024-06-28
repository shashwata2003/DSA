#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
BST from Preorder:
Given a preorder array convert that into a BST

Solu:
Apporach 1:
We can take the input in a single array and then convert it into a BST like we did in initial lecture in BST
implementation.
TS: O(n2)

Apporach 2:
Given the preorder, and by sorting that array we can create the inorder array 
using both inorder and preorder we can create the tree.
TS: O(nlogn)

Apporach 3.
Here we build the tree using the property of the preorder using range of each node.
Hence we will used recurion and assign a range of min and max for each node

Plus optimization: we can do it without the min val.

Base case:
If( we move out of the arr) return NULL
and if (it is not in the range ) return NULL
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

Node* solve(vector<int> &preorder, int min, int max, int &i){
    // Base cases:
    // i out of the preorder array,
    if (i >= preorder.size()) {
        return NULL;
    }
    // Out of range
    if (preorder[i] < min || preorder[i] > max) {
        return NULL;
    }
    Node *root = new Node(preorder[i++]);
    root->left = solve(preorder, min, root->data, i);
    root->right = solve(preorder, root->data, max, i);
    return root;
}

Node* preodertoBST(vector<int> &preorder) {
    int min = INT_MIN;
    int max = INT_MAX;
    int i = 0;
    return solve(preorder, min, max, i);
}

void printBST(Node* root) {
    if (root == NULL) {
        return;
    }
    printBST(root->left);
    cout << root->data << " ";
    printBST(root->right);
}

int main() {
    vector<int> arr = {10, 4, 3, 7, 40, 55};
    Node *ans = preodertoBST(arr);
    printBST(ans);
    return 0;
}