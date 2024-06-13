#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Sum Tree:
Given a binary, we need to tell weather the sum of left subtree and right sun tree for any node is equal to the 
Node x. like
3 2 1 : 2+1 = 3 root node.

Apporach:
we are going to use the recursion with pair method. 
we are going to use a bool and int val : bool will tell weather the folling node is sum tree or not and store the
val if the sum.

Time complexity : O(n)
Space : O(height of the tree)

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

pair<bool,int> sumtreefast(Node* root){
    if(root == NULL){
        pair<bool,int> p = make_pair(true, 0);
    }
    if(root->left == NULL && root->right == NULL){
        pair<bool,int> p = make_pair(true, 0);
        return p;
    }
    pair<bool,int> left = sumtreefast(root->left);
    pair<bool,int> right = sumtreefast(root->right);
    bool val = left.second + right.second == root->data;

    pair<bool,int> ans;
    if(val && left.first && right.first){
        ans.first = true;
        ans.second = left.second + right.second;
    }
    else{
        ans.first = false;
    }
    return ans;


}

bool issumtree(Node* root){
    return sumtreefast(root).first;
}

int main(){
    Node* root= NULL;
    root = buildTree(root);
    cout<<issumtree<<endl;
return 0;
}