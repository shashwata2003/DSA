#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Creating a binary tree:
1. To implement the following 
2. Level Order Traversal/ Breadth first search(BFS)
3. Reverse Order Traversal
4. Inorder/ preorder / postorder
5. build from level order
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

void levelordertraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node* temp = q.front();
        if(temp == NULL){
            cout<<endl;
            if(!q.empty());
            q.push(NULL);
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
    
}

void inorder(node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    inorder(root->left);
    cout << root-> data << " ";
    inorder(root->right);

}

void preorder(node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    cout << root-> data << " ";
    preorder(root->left);
    preorder(root->right);

}

void postorder(node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root-> data << " ";

}

void buildFromLevelOrder(node* &root) {
    queue<node*> q;

    cout << "Enter data for root" << endl;
    int data ;
    cin >> data;
    root = new node(data);
    
    q.push(root);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        cout << "Enter left node for: " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if(leftData != -1) {
            temp -> left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right node for: " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if(rightData != -1) {
            temp -> right = new node(rightData);
            q.push(temp->right);
        }
    }
 }


int main(){
    Node* root = NULL;
    root = buildTree(root);
    levelordertraversal(root);
return 0;
}