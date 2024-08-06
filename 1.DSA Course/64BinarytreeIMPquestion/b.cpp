#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Boundary Traversal:
Here we need to print all the node which are in the boundary from left to right order.
solution:
Apporach: here we need to divide the problem in three parts:
1. print all the node of left subtree except the last node.
2. print all the leaf nodes.
3. Print all the node of the right subtree except the last node.


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

//left traversal:
void lefttraversal(Node* root , vector<int> &ans){
    if(root == NULL){
        return;
    }
    // we need to ignore the left node of the left traversal.
    if(root->right == NULL && root->left == NULL){
        return ;
    }

    ans.push_back(root->data);
    // run the left traversal of the left and right child of the root node.
    if (root->left) {
        lefttraversal(root->left, ans);
    } else if (root->right) {
        lefttraversal(root->right, ans);
    }
}

// traversing all the leaf nodes
void leaftraversal(Node* root, vector<int> &ans){
    if(root == NULL){
        return;
    }
    if(root->right == NULL && root->left == NULL){
        ans.push_back(root->data);
        return;
    }
    leaftraversal(root->left,ans);
    leaftraversal(root->right,ans);
}

//Traversal of the right subtree
void righttraveral(Node* root, vector<int> &ans){
    if(root == NULL){
        return;
    }
    if(root->right== NULL && root->left == NULL){
        return;
    }
    if(root->right){
        righttraveral(root->right,ans);
    }
    else if(root->left)
    {
        righttraveral(root->left,ans);
    }
    ans.push_back(root->data);
    
}

vector<int> boundaryTraversal(Node* root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    ans.push_back(root->data);
    lefttraversal(root,ans);
    leaftraversal(root->right,ans);
    leaftraversal(root->left,ans);
    righttraveral(root,ans);
    return ans;

}

int main(){
    Node* root = NULL;
    root = buildTree(root);
    vector<int> ans = boundaryTraversal(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
return 0;
}