#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  
Given a BST and a target value. we need to find a pair in the BST who sum will be equal to the target value.
Eg:


Solution:
Apporach 1:
Brute Force:
First take the root node and find target - root , and try to find this val in the tree.
if found return true else move to the next node till u have traversed all the node.
TS: O(n2)

Apporach 2:
Here we will use two pointer. 
1. First we will have the inorder traversal of the BST, in a arr form.
2. Use i and j to point at the both ends of thr arr. hence i is the smallest no. and j is the largest no.
3. check if i+j == targer or not if yes return true
4. else if i+j > target we move j to a smaller val to reduce the out
5. else if i+j< target we will move i to a higher val to increase the out and match it with targer.

TS: O(N)
SP: O(height)
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

void Inordertra(Node* root,vector<int> &ans){
    
    if(root == NULL){
        return ;
    }
    Inordertra(root->left,ans);
    ans.push_back(root->data);
    Inordertra(root->right,ans);
}

bool twosum(Node* root, int target){
    vector<int> inorder;
    Inordertra( root , inorder);
    int i = 0, j = inorder.size() - 1;
    while (i<j)
    {
        if(inorder[i] + inorder[j] == target){
            return true;
        }
        else if(inorder[i] + inorder[j] > target){
            j--;
        }
        else if(inorder[i] + inorder[j] < target){
            i++;
        }
    }
    return false;
    
}

int main(){
    Node* root = NULL;
    root = buildBSTtree(root);
    cout<<twosum(root,20);
return 0;
}