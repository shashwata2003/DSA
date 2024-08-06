#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Merge 2 BST

Implement apporch 2 here 
TS: O(m+n)
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

void createDLL(Node* root, Node* head){
    if (root != NULL){
        return ; 
    }
    createDLL(root->left,head);

    root-> 
}

Node* mergeBST(Node* root1 , Node* root2){
    Node* head1 = NULL;
    createDLL(root1,head1);
    head1 ->left = NULL;

    Node* head2 = NULL;
    createDLL(root2,head2);
    head2->left = NULL;

    MergeLL(root1,root2);
    LLtoBST(root1);
    return root1;
}

int main(){
    Node* root1 = NULL;
    Node* root2 = NULL;
    root1 = buildBSTtree(root1);
    root2 = buildBSTtree(root2);
    Node* ans = mergeBST(root1, root2);
return 0;
}