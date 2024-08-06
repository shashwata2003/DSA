#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Diagonal Traversal:


Sol:
Apporach 1:
The plan is to make use of a map. Different slope distances are used in the map as a key.
so when we are traversing the left child we will increament the diagonal distance by 1
and when we move right diagonal distance remains same.

Dry run a input to understand better

TS: O(nlog n)
SP: O(N)

Apporach 2: Using Queue:


TS: O(N)
SP: O(N)
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

void solve(Node* root,map<int,vector<int>> &mp, int d){
    if(root == NULL){
        return;
    }
    
    mp[d].push_back(root->data);
    if(root->left){
        solve(root->left,mp,d+1);
    }
    if(root->right){
        solve(root->right,mp,d);
    }
}

vector<int> diagonaltraversal(Node* root){
    vector<int> ans;
    int d = 0;
    // diagonal distance with vale
    map<int,vector<int>> mp;
    solve(root,mp,d);
    for(auto i : mp){
        for(auto j: i.second){
            ans.push_back(j);
        }
    }
    return ans;
}

vector<int> diagonaltraversal1(Node* root){
    vector<int> diagonalVals;
    if (!root)
        return diagonalVals;
 
    // The leftQueue will be a queue which will store all
    // left pointers while traversing the tree, and will be
    // utilized when at any point right pointer becomes NULL
 
    queue<Node*> q;
    Node* node = root;
 
    while (node) {
 
        // Add current node to output
        diagonalVals.push_back(node->data);
        // If left child available, add it to queue
        if (node->left)
            q.push(node->left);
 
        // if right child, transfer the node to right
        if (node->right)
            node = node->right;
 
        else {
            // If left child Queue is not empty, utilize it
            // to traverse further
            if (!q.empty()) {
                node = leftQueue.front();
                q.pop();
            }
            else {
                // All the right childs traversed and no
                // left child left
                node = NULL;
            }
        }
    }
    return diagonalVals;

}


int main(){
    Node* root = NULL;
    root = buildTree(root);
    vector<int> ans = diagonaltraversal(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
return 0;
}