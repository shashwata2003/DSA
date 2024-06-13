#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Sum of Longest BloodLine(IMP):
Here we are given a Binary tree, we need to find the sum of the longest path from the root to the leaf node. 
And return the sum.

Apporach:
we are going to use recursion here.
here the will maintain two variables called maxlen and maxsum keeping track of both the sum and the length at each
node.
Now the base case for the recursion will be when we hit a leaf node we check out max sum and current len val and 
update it accordingly.

TC: O(n)
SC: O(height of the tree)
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
    //2 3 1 -1 -1 2 -1 -1 4 5 -1 -1 6 -1 7 -1 -1
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

void solve(Node* root, int sum, int &maxsum, int len, int &maxlen){
    //base case:
    if (root == NULL)
    {
        // if the current len is greater the previously stored len and update maxlen and maxsum.
        if(len>maxlen){
            maxlen = len;
            maxsum = sum;
        }
        // if the len is same as some other leaf node then we store the max sum out of those two
        else if(len == maxlen){
            maxsum = max(sum,maxsum);
        }
        return;
    }

    sum = sum+root->data;

    solve(root->left,sum,maxsum,len+1,maxlen);
    solve(root->right,sum,maxsum,len+1,maxlen);
    
}

int longestbloodline(Node* root){
    int sum = 0;
    int maxsum = -999;
    int len = 0;
    int maxlen= 0;
    solve(root,sum,maxsum,len,maxlen);
    return maxsum;
}

int main(){
    Node* root = NULL;
    root = buildTree(root);
    cout<<longestbloodline(root)<<endl;
return 0;
}