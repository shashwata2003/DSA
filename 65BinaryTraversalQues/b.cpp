#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Lowest Common Ancestor:
Given a binary tree and two node n1 and n2 . we need to find the lowest ancestor which is the lowest.
Lowest meaning jo sabsa phale aaya ho . when finding the common.

Sol:
Apporach 1:
We can store all the node that we pass when we go from the root to the end node.And then find the first common 
element.

Apporach 2:
using recursion
Here we will check each subtree one by one(both left and right);
Base case: if root == NULL return NULL
and if root == n1 or n2 return root
following are the conditions:
1. Both left and right subtree are null hence return NULL;
2. left = n1 or n2 then and right == NULL return left 
3. Vise verse of 2
4. both left = n1 and right = n2 or vise verse return that node that will be the final ans

TS: O(n)
SP: O(height)
 */

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;

            }
};

Node* buildTree(Node* root){
    int data;
    cin>>data;
    root = new Node(data);
    if(data == -1){
        return NULL;
    }
    cout<<"left Node"<<data<<endl;
    root->left  = buildTree(root->left);
    cout<<"right node"<<data<<endl;
    root->right = buildTree(root->right);
    return root;
}

Node* LCA(Node* root,int n1,int n2){
    // base case
    if(root == NULL){
        return NULL;
    }
    if(root->data == n1 || root->data == n2){
        return root;
    }

    Node* leftsubtree = LCA(root->left,n1,n2);
    Node* rightsubtree = LCA(root->right,n1,n2);
    // cond 1:
    if(leftsubtree!=NULL && rightsubtree!=NULL){
        return root;
    }
    //cond 2:
    else if(leftsubtree!=NULL && rightsubtree==NULL){
        return leftsubtree;
    }
    //cond 3:
    else if(leftsubtree==NULL && rightsubtree!=NULL){
        return rightsubtree;
    }
    //Cond 4:
    else{
        return NULL;
    }
}

int main(){
    Node* root = NULL;
    root = buildTree(root);
    Node* ans = LCA(root,7,5);
    cout<<ans->data<<endl;
return 0;
}