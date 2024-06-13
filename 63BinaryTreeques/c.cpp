#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Check for Balanced Tree:
We need to check weather the following tree is balanced or not. 
Balance meaning that (height(left subtree) - height(right subtree) <= 1).
These should be for all the nodes. 
Solution: 
Apporach 1: Brute force:
Here we are going to use both recursion and the height function to find the difference at of the heights

Apporach 2:
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

int maxheight(Node* root){
    if (root == NULL)
    {
        return 0;
    }
    int op1 = maxheight(root->left);
    int op2 = maxheight(root->right);
    int ans = max(op1,op2) +1;
    return ans;
    
}

bool isbalaced1(Node* root){
    if(root == NULL){
        return true;
    }
    bool left = isbalaced1(root->left);
    bool right = isbalaced1(root->right);

    bool diff  = abs(maxheight(root->left)-maxheight(root->right)) <= 1;

    if(left && right && diff){
        return true;
    }else{
        return false;
    }
}

pair<bool,int> findbalancedfast(Node* root){
    if(root == NULL){
        pair<bool,int> p = make_pair(true,0);
        return p;
    }
    pair<bool,int> left = findbalancedfast(root->left);
    pair<bool,int> right = findbalancedfast(root->right);
    bool diff = abs(left.second - right.second) <= 1;
    pair<bool,int> ans;
    if(left.first && right.first && diff){
        ans.first = true;
    }else{
        ans.first = false;
    }
    ans.second = max(left.second , right.second) + 1;
    return ans;
}

bool isbalanced2(Node* root){
    return findbalancedfast(root).first;
}

int main(){
    Node* root = NULL;
    root = buildTree(root);
    cout<<"First"<<isbalaced1(root)<<endl;
    cout<<"second"<<isbalanced2(root)<<endl;
return 0;
}