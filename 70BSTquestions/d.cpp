#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
 Predecessor And Successor In BST
You have been given a binary search tree of integers with ‘N’ nodes. You are also given 'KEY' which represents 
data of a node of this tree.
Your task is to return the predecessor and successor of the given node in the BST.

1. The predecessor of a node in BST is that node that will be visited just before the given node in the inorder
 traversal of the tree. If the given node is visited first in the inorder traversal, then its predecessor is 
 NULL.

2. The successor of a node in BST is that node that will be visited immediately after the given node in the 
inorder traversal of the tree. If the given node is visited last in the inorder traversal, then its successor 
is NULL.

Sample Input 1:
15 10 20 8 12 16 25 -1 -1 -1 -1 -1 -1 -1 -1
10
Sample output 1:
8 12

Solution:
Apporach 1:
Here we do a inorder traversal of the entire tree and store the output in an array, Now we wil traverse that 
array to find the key val and print the successor and the predeccesor.
ts: o(n)
sp: o(n) as we are going to use an array
Apporach 2:
Steps:
1. Find the key val in the tree.
2. the pred will be the max val of the left subtree 
3. and succ will be the min val of the right subtree.


TS: O(n)
SP: O(1)
 */


class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildBSTtree(Node* root) {
    int data;
    cin >> data;
    if (data == -1) {
        return NULL;
    }
    root = new Node(data);
    cout << "Enter left of " << data << endl;
    root->left = buildBSTtree(root->left);
    cout << "Enter right of " << data << endl;
    root->right = buildBSTtree(root->right);
    return root;
}

pair<int,int> findpredandsucc(Node* root, int k){
    // find the val of key:
    Node* temp = root;
    int pred = -1 , succ = -1;
    // store the pred and the succ val as the temp
    while (temp->data != k)
    {
        if(temp->data > k){
            pred = temp->data;
            temp = temp->left;
        }
        else{
            succ = temp->data;
            temp = temp->right;
        }
    }
    // after this temp have reached the key val

    // follow the step 2 & 3
    Node* lefttree = temp->left;
    while (lefttree!=NULL)
    {
        pred = lefttree->data;
        lefttree=lefttree->right;
    }

    Node* righttree = temp->right;
    while (righttree!=NULL)
    {
        succ = righttree->data;
        righttree = righttree->left;
    }

    return {pred, succ};
}


int main(){
    Node * root = NULL;
    root = buildBSTtree(root);
    pair<int,int> ans = findpredandsucc(root,10);
    cout<<ans.first<<" "<<ans.second<<endl;

return 0;
}