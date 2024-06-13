#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Top view of a binary tree:
Given a binary tree find the top veiw of the tree. 

SOl:
Here we are going to use the same maping technique we used in the vertical treversal.
But the only difference will be for every horizontal distance we will have only one.

We cannot directly print the left and right subtree as that will start form the root and move down, but we want 
start from the leaf and move towards the root.

 */

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *buildTree(Node *root)
{
    int data;
    cin >> data;
    root = new Node(data);
    if (data == -1)
    {
        return NULL;
    }
    cout << "left Node" << data << endl;
    root->left = buildTree(root->left);
    cout << "right node" << data << endl;
    root->right = buildTree(root->right);
    return root;
}

vector<int> topview(Node* root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    // mapping the horizontal distance with the node val
    map<int,int> nodes;
    //pair of node and the HD 
    queue<pair<Node*,int>> q;
    q.push(make_pair(root,0));
    while (!q.empty())
    {
        pair<Node*,int> front = q.front();
        q.pop();
        int hd = front.second;
        Node* frontNode = front.first;
        // this tries to find any val stored in hd position in the map, if it is empty it return the end val of the
        //map this a property of the map.
        if(nodes.find(hd) == nodes.end()){
            nodes[hd] = frontNode->data;
        }
        if(frontNode -> left){
            q.push(make_pair(frontNode->left,hd-1));
        }
        if(frontNode -> right){
            q.push(make_pair(frontNode->right,hd+1));
        }
    }
    for(auto i: nodes){
        ans.push_back(i.second);
    }

    return ans;
    
}

int main(){
    Node* root = NULL;
    root = buildTree(root);
    vector<int> ans = topview(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    

return 0;
}