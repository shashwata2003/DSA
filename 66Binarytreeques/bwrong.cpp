#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Construct a BT from Inorder/PostOrder traversal:
Given Two int arrays of inorder and postorder traversal val. we need to build a tree using both the array values.
and we need to print the post order(left right root) of the built tree.
eg: Inorder(Left root right):[3 1 4 0 5 2]
postorder(left right root): [0 1 3 4 2 5]
out: 3 4 1 5 2 0

Sol:
we will do the same like the previous question just we need to start from the end of the post array and need to 
build the right subtree first.

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
// TS: o(nlogn)
void createmap(map<int,int> &mp, int in[], int n){
    for (int i = 0; i < n; i++)
    {
        mp[in[i]] = i;
    }
    
}

//Ts: O(n)
Node* solve(int post[], int in[], int n, int poststart, int instart, int inend, map<int,int> mp){
    //Base case :
    //< 0 because we are starting from the end of the post array
    if(poststart<0 || instart>inend){
        return NULL;
    }

     int root_val = post[poststart--];
    Node* root = new Node(root_val);
    int root_index = mp[root_val];

    // Recursively build the right subtree first, then the left subtree
    root->right = solve(post, in, n, poststart, root_index + 1, inend, mp);
    root->left = solve(post, in, n, poststart, instart, root_index - 1, mp);
    
    return root;

}

Node* buildTree(int post[], int in[], int n){
    int poststart = n-1;
    int instart = 0;
    int inend = n-1;
    map<int,int> mp;
    createmap(mp,in,n);
    Node* ans = solve(post,in,n,poststart,instart,inend,mp);
    return ans;
}

void postorderprint(Node* root){
    if(root == NULL){
        return;
    }
    postorderprint(root->left);
    postorderprint(root->right);
    cout<<root->data<<" ";
}

int main(){
    Node* root = NULL;
    int n = 6;
    int in[n] = {3, 1, 4, 0, 5, 2};
    int post[n] = {0, 1, 3, 4, 2, 5};
    root = buildTree(post,in,n);
    postorderprint(root);
    return 0;
}