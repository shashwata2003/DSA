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
or 
we can use vector<int> and use teh val and create node of each val in the vector.
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

************************************************************/
void inorderTraversal(TreeNode<int>* root, vector<int>& ino) {
    if(root == NULL) {
        return;
    }
    inorderTraversal(root->left, ino);
    ino.push_back(root->data);
    inorderTraversal(root->right, ino);
}

TreeNode<int>* flatten(TreeNode<int>* root) {
    vector<int> ino;
    inorderTraversal(root, ino);
    int n = ino.size();
    TreeNode<int>* newRoot = new TreeNode<int>(ino[0]);
    TreeNode<int>* curr = newRoot;
    for(int i = 1; i < n; i++) {
        TreeNode<int>* temp = new TreeNode<int>(ino[i]);
        curr->right = temp;
        curr->left = NULL;
        curr = curr->right;
    }
    
    return newRoot;
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