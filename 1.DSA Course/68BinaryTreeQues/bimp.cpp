#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Flatten a tree into Linked List
Given a binary tree, flatten it in to a linked list in place in preorder traversal method.
The final tree should have all the left pointer null and each right pointers should have the data.

Time com: O(n);
space: o(1)

Sol:
Apporach 1:
Using any traversal method,
We can traverse the tree one node at a time and create the linked list along sie of it

But that wont be in place of in SC O(1)

Apporach 2:
Using recursion:
create the right subtree in LL and then the left sub tree in Linked list then then point the left of root to null 
and right of root to first node of the left subtree and the last node of the left subtree to the first of the right 
subtree 

the problem with this apporach is it is in SC: O(n)

Apporach 3:
Using morrise traversal:
Algo: Do a dry run
curr = root 
while(root!=NULL){
    if current left exits{
        // find predicessor:
        pred = curr -> left
        while(pred->right != NULL){
            pred = prev -> right
        }
        // linking the left to the right
        pred-> right = curr->left;
        linking the root to the left subtrr
        curr-> right = curr-> left 
    }
    curr= curr->right;
}
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
        cout<<"enter data"<<endl;
        int data;
        cin>>data;
        root = new Node(data);

        if(data == -1){
            return NULL;
        }
        cout<<"Enter data for left child "<<data<<endl;
        root->left = buildTree(root->left);
        cout<<"Enter data for the right child"<<data<<endl;
        root->right = buildTree(root->right);
        return root;
}

void flatten(Node* root){
    Node* curr = root;
    while (curr!=NULL)
    {
        if(curr->left){
            Node* pred = curr->left;
            while (pred->right!=NULL)
            {
                pred = pred->right;
            }
            // this is done because we need to do a preorder traversal
            pred->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        //imp
        curr = curr->right;
    }
}

void preorderprint(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorderprint(root->left);
    preorderprint(root->right);
}

int main(){
    Node* root = NULL;
    root = buildTree(root);
    flatten(root);
    preorderprint(root);
return 0;
}