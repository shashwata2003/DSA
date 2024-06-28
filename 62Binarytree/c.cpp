#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Reverse level order traversal.
Given a Binary tree we need to print the from the root to the top.

Apporach 1:
Here we will print each level but we will start from the back 
which mean we need to find the height of the tree and run a loop from h to root,
TS: O(n2)
SP: O(n)

Apporach 2:
Using queue and stack,
We start storing the nodes in the queue and then push it in the stack, Pop each element form the stack will 
print in the reverse order
TS: O(N)
SP: O(n)
 */


class Node {
public:
    int data;
    Node* left;
    Node* right;
    
    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree(Node* root) {
    cout << "Enter data: " << endl;
    int data;
    cin >> data;
    root = new Node(data);

    if(data == -1) {
        return NULL;
    }
    cout << "Enter data for left child of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for the right child of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

// Apporach 1:
int heightBST(Node* root){
    if(root == NULL){
        return 0;
    }else{
        int left = heightBST(root->left);
        int right = heightBST(root->right);
        //return the larger one.
        if(left>right){
            return left+1;
        }
        else{
            return right+1;
        }
    }
}

void printthelevel(Node* root, int l){
    if(root == NULL){
        return;
    }
    if(l == 1){
        cout<<root->data<<" ";
    }
    else if(l>1){
        printthelevel(root->left,l-1);
        printthelevel(root->right,l-1);
    }
}

void reverseordertraversal1(Node* root){
    int h = heightBST(root);
    for (int i = h; i > 0; i--)
    {
        printthelevel(root,i);
    }
}

//Apporach 2:
void reverseOrder2(Node* root){
    stack<Node*> st;
    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
        root = q.front();
        q.pop();
        st.push(root);

        // first traverse the right and then the left.
        if(root->right){
            q.push(root->right);
        }
        if(root->left){
            q.push(root->left);
        }
        
    }
    while (!st.empty())
    {
        root= st.top();
        cout<<root->data<<" ";
        st.pop();
    }
    
    
}

int main(){
    Node* root = NULL;
    root = buildTree(root);
    reverseOrder2(root);
return 0;
}