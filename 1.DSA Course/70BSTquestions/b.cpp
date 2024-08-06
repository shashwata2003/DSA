#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
 Find K-th smallest Element in BST
Given a binary search tree and an integer ‘K’. Your task is to find the ‘K-th’
smallest element in the given BST( binary search tree).

Draw the recursive tree for the ans.


Apporach 1:
Here we are using inorder traversal which will give us a sorted array. Here we use a index variable which 
we will increment when we complete a traversal of a node.
TS: o(n)
Sp: o(height)

Apprach 2:
Do it using morrise traversal.
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

int solve(Node* root, int k, int &i){
    if(root == NULL){
        return -1;
    }
    // we will traverse the tree in inorder fashion.
    //first the left part 
    int left = solve(root->left , k, i);
    if(left != -1){
        return left;
    }
    //Processing the root
    i++;
    if(i == k){
        return root->data;
    }

    // now the right side:
    return solve(root->right,k,i );
}

int ksmallestelement(Node* root, int k){
    // it is the counter which keeps the track ki kitna elements traverse kar liya 
    int i = 0;
    return solve(root,k,i);
}

int main(){
    Node* root = NULL;
    root = buildBSTtree(root);
    cout<<ksmallestelement(root, 2);
return 0;
}