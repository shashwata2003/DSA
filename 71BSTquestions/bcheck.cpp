#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
 Flatten BST To A Sorted List
Given a BST convert that BST into a sorted linked list
eg:
2
5 3 7 -1 -1 6 8 -1 -1 -1 -1
2 1 -1 -1 -1
Sample output 2
3 -1 5 -1 6 -1 7 -1 8 -1 -1
1 -1 2 -1 -1

Sol:
Here first we will do a inorder traversal of the BST as we know the inorder traversal of the BST will return 
a sorted array as the ans.
we will store that in the vector<node*> and we will point the left of each node to null and the right to the
next node in the vector
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

void inorder(Node* root, vector<int> &in){
    if(root == NULL){
        return;  // Fix to return immediately if root is NULL
    }
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

Node* flattenbst(Node* root){
    vector<int> in;
    inorder(root, in);
    int n = in.size();
    Node* newroot =  new Node(in[0]);
    Node* curr = newroot;
    for (int i = 0; i < n; i++) {
        Node* temp = new Node(in[i]);
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }
    return newroot;
}

// Helper function to print the flattened tree
void printFlattenedTree(Node* root) {
    if(root == NULL){
        return ;
    }
    printFlattenedTree(root->left);
    cout<<root->data<<" ";
    printFlattenedTree(root->right);
}

int main() {
    Node* root = NULL;
    root = buildBSTtree(root);
    root = flattenbst(root);
    printFlattenedTree(root);

    return 0;
}