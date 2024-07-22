#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Zigzag Traversal or spiral Traversal:
Here we are given a binary tree and we need to print it in  a zigzag manner. ie first print left to right than right
to left then follow this till the buttom of the tree.

Apporach:
Using a queue to terverse the tree.
1. we need to check weather the root is null or not if yes then return the empty vector.
2. we will create a queue of type node and push the root node in it.
3. now we will check the queue till it is empty.
4. we also need a int vector called ans which will store the order of the ans weather it is LtoR or RtoL
5. We will use a flag to check which motion we need to take.
6. now if the flag is true then we will push the val in ans right to left that is starting from i 
or else we will push it left to right that means size - i -1
7. now push both the left and the right child of the current node in the queue 
8. after that change the direction of the flow by negating the flag.
9. now push the ans in the result vector for the current node.
TS: o(n)
Sp: o(n)
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

vector<int> zigzagtraversal(Node* root){
    vector<int> result;
    //NULL check
    if(root == NULL){
        return result;
    }
    queue<Node*> q;
    // Push the first node
    q.push(root);
    // flag to desice the flow of the traversal weather RTL or LtoR
    bool righttoleft = false;
    while (!q.empty())
    {
        int size = q.size(); 
        // vector to store the ans according to the flow
        vector<int> ans(size);
        for (int i = 0; i < size; i++)
        {
            Node* front = q.front();
            q.pop();
            //acc to the flag setting the index val.
            int index = righttoleft ? size-i+1 : i;
            ans[index] = front->data;
            //pushing the left and right child if they are present.
            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }
        }
        // changing the direction for the next iteration
        righttoleft = !righttoleft;
        // pushing the ans in the final result.
        for (auto i :ans )
        {
            result.push_back(i);
        }
        
    }
        return result;
    
}

int main(){
    Node* root = NULL;
    root = buildTree(root);
    vector<int> ans = zigzagtraversal(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
return 0;
}