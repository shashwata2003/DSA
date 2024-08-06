#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
K sum path:
Given a Binary tree and value of int K:
we need to find the no. of paths having the sum equal to k.
The path can start form any where in the tree. but only in downwards direction.
eg: 1 2 3 k = 3
ans : 2 
first path will be 1 and 2
second will be 3 only

Sol:
Here we will traverse the entire tree with a vector which will store data of each node it followed
Which means we will find all the paths and store its data in the vector and when we find the match == K 
we will increment the value of count.

TS: 
SC:
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

void solve(Node* root, int k , int &count, vector<int> paths){
    //base case
    if (root == NULL)
    {
        return;
    }
    // push the current node in the paths:
    paths.push_back(root->data);

    // move to left subtree and then right subtree:
    solve(root->left,k,count,paths);
    solve(root->right,k,count,paths);

    // Update the count:
        // we will start from the back of the vector as we are backtracking(moving from buttom to top) in the recur
        // sive tree.
    int size = paths.size();
    int sum = 0;
    for (int i = size-1; i >=0 ; i--)
    {
        sum = sum+paths[i];
        if(sum == k){
            count++;
        }
    }
    // remove the element form the paths as we move up and return the element
    paths.pop_back();
}

int sumk(Node* root, int k){
    int count =0;
    // Stores all the paths followed till the current node
    vector<int> paths;
    solve(root,k,count,paths);
    return count;
}

int main(){
    Node* root = NULL;
    root = buildTree(root);
    cout<<sumk(root,3);
return 0;
}