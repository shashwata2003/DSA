#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Kth Ancestor of a Tree Node:

Here we can solve this same question in two way:

IN leetcode we need to solve  like:
we need to create acsector vector for the given node and 
we will print the kth node for that vector, 

Other way is to find the the node and move back by reducing the k pointer


 */

class Node{
     public:
     int data;
     Node* left;
     Node* right;
     Node(int data){
          this->data = data;
          this->left = NULL;
          this->right = NULL;
     }
};
/*
Method 2:
Find the node 
we will track back form that node by k --
*/

Node* solve(Node* root, int k, int node){
     if(root == NULL){
          return root;
     }
     if(root->data == node){
          return root;
     }
     Node* left = solve(root->left,k,node);
     Node* right = solve(root->right,k,node);

     if(left != NULL || right != NULL){
          // we have found the node:
          k--;
          if(k == 0){
               return root;
          }
          if(left){
               return left;
          }else{
               return right;
          }
     }
     return NULL;
}

int kthAncestor(Node* root, int k, int node) {
     Node* ans = solve(root,k,node);
     if(ans){
          return ans->data;
     }else{
          return -1;
     }
}

/*
Method 2:
Here we will find the all the acestors first and then find the kth value form the list
*/

void findAncestor(Node* root, vector<int>& anc) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);
    anc[root->data] = -1; // Root node has no ancestor

    while (!q.empty()) {
        Node* top = q.front();
        q.pop();
        if (top->left) {
            anc[top->left->data] = top->data;
            q.push(top->left);
        }
        if (top->right) {
            anc[top->right->data] = top->data;
            q.push(top->right);
        }
    }
}

int kthAncestor(Node* root, int k, int node, int n) {
    vector<int> ancestor(n + 1, -1); // Initialize with -1
    findAncestor(root, ancestor);

    while (node != -1) {
        node = ancestor[node];
        k--;
        if (k == 0) {
            break;
        }
    }
    return node;
}


int main(){

return 0;
}