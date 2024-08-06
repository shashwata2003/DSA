#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
K - Ancestor:
Given a Binary tree and the value of k and value of node.
we need to find the kth ancestor of that node.

Sol:
Apporach 1:
We can find the entire path from the root to the n node and store each value in vector and we can treverse the 
vector from the back k times and we can find the kth ancestor.

Apporach 2:
using recursion:
First we will start by finding the node 
To do so we will use Left and right subtree method as used in the prev question.
Hence will doing so we will have two cond 
1. Not the required node hence send NULL
2. if root == NULL return NULL
3. if left != NULL and right == NULL hence we fount the node hence k--
do this till k == 0 when k == 0 return that node.


Here we need to take in consideration a edge case in which n == root node , in such cases we need to return -1
as k cannot be 0 (given in the question)
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

Node* solve(Node* root, int &k, int n){
    //base case:
    if(root == NULL){
        return NULL;
    }
    if(root->data == n){
        return root;
    }
    // checking the left and the right subtree using recursion.
    Node* left = solve(root->left,k,n);
    Node* right = solve(root->right,k,n);
    
    // Now if any one of the subtree has the node value we will start counting back aby decrementing the val of k
    if(left != NULL && right == NULL ){
        // left subtree has the node 
        k--;
        
        // also sometimes the k can go in -ve val.
        if(k<=0){
            // This is done to lock the value of k , such that we cannot have any more iterations.
            k = 9999;
            return root;
        }else{
            return left;
        }
    }
    else if(left == NULL && right != NULL ){
        k--;
        // Right subtree has the node 
        if(k<=0){
            k = 9999;
            return root;
        }else{
            return right;
        }
    }
    return NULL;
    
}

int kancestor(Node* root, int k, int n){
    Node* ans = solve(root,k,n);
    // running a null check
    if(ans == NULL || root->data == n){
        return -1;
    }else{
    return ans->data;}
}

int main(){
    Node* root = NULL;
    root = buildTree(root);
    cout<<kancestor(root, 2, 5);
return 0;
}