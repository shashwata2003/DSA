#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Normal BST to Balanced BST
Given a Normal BST convert it into a balanced BST
A Balanced BST is defined as a BST, in which the height of two subtrees of every node differs no more than 1.
eg:
Sol:
Apporach 1:(using recursion)
Here we will store the inorder BST in a array and we know we will have it in ascending order. 
Now find the mid of that in the array, that makes it as the root and the right part makes the right subtree using 
recursion and the left will make the left subtree, 

Base case:
If start > end return NULL

TS: O(n)
Sp: O(n)

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

void inorderarray(Node* root, vector<int> &in){
    if(root == NULL){
        return ; 
    }
    inorderarray(root->left,in);
    in.push_back(root->data);
    inorderarray(root->right,in);
}

Node* inordertobalance(vector<int> &In, int s, int e){
    if(s > e){
        return NULL;
    }
    int mid = (s + e) / 2;
    Node* root = new Node(In[mid]);
    root->left = inordertobalance(In, s, mid - 1);
    root->right = inordertobalance(In, mid + 1, e);
    return root;
}

Node* BalanceTree(Node* root){
    vector<int> In;
    inorderarray(root, In);
    return inordertobalance(In, 0, In.size() - 1);
}

void printBST(Node* root){
    if(root == NULL){
        return ;
    }
    printBST(root->left);
    cout << root->data << " ";
    printBST(root->right);
}

int main(){
    Node* root = NULL;
    root = buildBSTtree(root);
    Node* balancedRoot = BalanceTree(root);
    printBST(balancedRoot);
    return 0;
}