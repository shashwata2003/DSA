#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
K largest Element of the BST.

Appporach 1:
Here we can create a sorted array using the inorder traversal and we can traverse the inorder array form 
the back end to find the k largest element


Apporach 2:
Similar to ksmallest just that we will first search the right side of the tree first.
or we can use the formula: (n-k)+1 th smallest element will be the k largest element 
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

int findsize(Node* root){
    if(root == NULL){
        return 0;
    }
    int left = findsize(root->left);
    int right = findsize(root->right);
    return left+right+1;
}

int ksmallest(Node* root, int k , int &i){
    if(root == NULL){
        return -1;
    }
    //left tree:
    int left = ksmallest(root->left, k, i);
    if(left != -1){
        return left;
    }
    
    //Process root;
    i++;
    if(i == k){
        return root->data;
    }

    //right tree:
    int right = ksmallest(root->right,k,i);
    return right;
}

int klargest(Node* root, int k){
    int i = 0;
    int size = findsize(root);
    int newk = (size - k)+1;
    int ans = ksmallest(root, newk, i);

    return ans;
}
int main(){
    Node* root = NULL;
    root = buildBSTtree(root);
    cout<<klargest(root,3);
return 0;
}