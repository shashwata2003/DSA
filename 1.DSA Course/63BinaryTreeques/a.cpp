#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  
Height of Tree:
We need to find the maximum distance between the root node and the leaf node.
Apporach:
Here we are going to use the recursion.
base case: if the node is null return 0;
Now we will find the height of the left side of the node and the height of the right side of the node.
next we will find the max of them 
and plus one in it as it will add the root node height too in it.
return the ans.

time Complexity: O(n)
Space Complexity: O(height)
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

Node* BuildTree(Node* root){
    int data;
    cout<<"enter Data"<<endl;
    cin>> data;
    root = new Node(data);
    if(data == -1){
        return NULL;
    }
    cout<<"enter the data for the left node"<<data<<endl;
    root->left=BuildTree(root->left);
    cout<<"enter the data for the right node"<<data<<endl;
    root->right=BuildTree(root->right);
    return root;
}

int maxheight(Node* node){
    //base case:
    if (node==NULL)
    {
        return 0;
    }
    int h1 = maxheight(node->left);
    int h2 = maxheight(node->right);
    int ans = max(h1,h2)+1;
    return ans;
    
}

int main(){
    Node* root = NULL;
    root = BuildTree(root);
    int h = maxheight(root);
    cout<<h<<endl;
return 0;
}