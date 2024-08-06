#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Identical Tree:
Given two binary tree, tell weather both the trees are identical or not.

Sol:
Here we are going to use recursion
we need to check multiple base case before again calling the function.
1. if r1 == r2 == NULL return true
2. if r1 == NULL and r2 != NULL return false or vise versa
3. now run the same function for the left and the right subtree.
4. now check the recursive function which set val to true if val of r1 == val of r2
5. if all left right and val are true return true else return false.

Time complexity: o(n)
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

bool checkidentical(Node* r1, Node* r2){
    if(r1 == NULL && r2 == NULL){
        return true;
    }
    if(r1 != NULL && r2 == NULL){
        return false;
    }
    if(r2 != NULL && r1 == NULL){
        return false;
    }

    bool left = checkidentical(r1->left,r2->left);
    bool right = checkidentical(r1->right,r2->right);

    bool val = r1->data == r2->data;
    if(left && right && val){
        return true;
    }
    else{
        return false;
    }

}

int main(){
    Node* r1 = NULL;
    Node* r2 = NULL;
    r1 = buildTree(r1);
    r2 = buildTree(r2);
    cout<<checkidentical(r1,r2)<<endl;

return 0;
}