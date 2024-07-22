#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
 LCA of Two Nodes In A BST
You are given a binary search tree of integers with N nodes. You are also given references to two nodes 
'P' and 'Q' from this BST.
Your task is to find the lowest common ancestor(LCA) of these two given nodes.
The lowest common ancestor for two nodes P and Q is defined as the lowest node that has both P and Q as 
descendants (where we allow a node to be a descendant of itself)

eg: 
Sample Input 1 :
3 5
2 1 3 -1 -1 -1 5 -1 -1
Sample Output 1:
3
Solution:
Apporach:
we are gong to use recursion here 
base case if the root == NULL return NULL
if the root data is less than both p and q then move to the right subtree to find it 
else move to the right subtree.
TS: O(n)
SP: o(1)

Apporach 2:
Using iterative method:
TS: O(1)
Sp O(1)
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

Node* findLCA1(Node* root , int p , int q){
   while (root != NULL)
   {
    if(root->data > p && root->data > q){
        root = root -> left;
    }
    if(root->data < p && root->data < q){
        root = root -> right;
    }else{
        return root;
    }
   }
}

Node* findLCA(Node* root , int p , int q){
    if(root == NULL){
        return NULL;
    }
    if(root->data > p && root->data > q){
        return findLCA(root->left,p,q);
    }
    if(root->data < p && root->data < q){
        return findLCA(root->right,p,q);
    }
    return root;
}

int main(){
    Node* root = NULL;
    root = buildBSTtree(root);
    Node* ans = findLCA1(root, 3,5);
    cout<<ans->data;
return 0;
}