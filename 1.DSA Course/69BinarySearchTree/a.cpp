#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Implementing Binary search tree
1. Inserting elements TS: O(log n) 
2. searching a node in b.cpp
3. min and max val
4. Deleting a node  o(n) sp: o(h)
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

// Insert data in the BST

Node* insertintree(Node* root, int data) {
    if (root == NULL) {
        root = new Node(data);
        return root;
    }
    if (data > root->data) {
        // Insert at the right subtree
        root->right = insertintree(root->right, data);
    } else {
        // Insert at the left subtree
        root->left = insertintree(root->left, data);
    }
    return root;
}

void takeinput(Node*& root) {
    int data;
    cin >> data;
    while (data != -1) {
        root = insertintree(root, data);
        cin >> data;
    }
}

void LevelOrderTraversal(Node* root) {
    if (root == NULL) return;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        Node* front = q.front();
        q.pop();
        if (front == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << front->data << " ";
            if (front->left) {
                q.push(front->left);
            }
            if (front->right) {
                q.push(front->right);
            }
        }
    }
}


// Max min in BST:
Node* minval(Node* root){
    Node* temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
    
} 

Node* Maxval(Node* root){
    Node* temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
    
} 

//Deletion of BST node:
Node* deleteNode(Node* root, int val){
    //base case:
    if(root == NULL){
        return NULL;
    }
    if(root->data == val){
        // no child
        if(root->left == NULL && root->right == NULL){
            delete(root);
            return NULL;
        }
        // one child
            // right child 
        if(root->right != NULL && root->left == NULL){
            Node* temp = root->right;
            delete(root);
            return temp;
        }
            // left child
        if(root->right == NULL && root->left != NULL){
            Node* temp = root->left;
            delete(root);
            return temp;
        }
        // two child
        if(root->right != NULL && root->left != NULL){
            /*Here we have two option(this node need to be deleted and has both childs)
                1. replace the root with the max val of the left subtree and delete that node from the left subtree
                2. replace with the min val of the right subtree and delete it */
            int mini =  minval(root->right)->data;
            root->data = mini;
            root->right = deleteNode(root->right,mini);
            return root;
        }

    }
    if(root->data > val){
        root -> left = deleteNode(root->left,val);
    }else{
        root->right = deleteNode(root->right,val)
    }
}


int main(){
    Node* root = NULL;
    takeinput(root);
    cout<<minval(root)->data<<endl;
    cout<<Maxval(root)->data<<endl;
    LevelOrderTraversal(root);
return 0;
}