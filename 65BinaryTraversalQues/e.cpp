#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*
Max sum of non adjacent nodes:
Given a Binary tree we need to select a set of nodes which will give use the max sum. but the condition is that
no two selected nodes should be connected to each other.

Solution:
Apporach:
Here we are going to take a pair of two int value.
a = this is the val including the current node
b = this is the val of sum excluding the current node

We will find this pair val for each node till the root ans the max val b/w  a & b at the root will be the ans.

now to cal. the val of the a and b:
a = curr->val+ rightsubtree.BVal + leftsubtree.Bval; // including the current node hence cannot include its child node
b = max(right a and b) + max( left a and b) // as the current node is not included we can use both the child vals


Ts: O(n)
SC: o(height)
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

pair<int,int> solve(Node* root){
    //base case
    if(root == NULL){
        pair<int,int> p = make_pair(0,0);
        return p;
    }
    // checking the left and right subtree:
    pair<int,int> left = solve(root->left);
    pair<int,int> right = solve(root->right);

    pair<int,int> res;
    // including the current node
    res.first = root->data + left.second +right.second;
    res.second = max(left.first , left.second) + max(right.first,right.second);

    return res;

}

int maxsum(Node *root)
{
    pair<int,int> ans;
    ans = solve(root);
    return max(ans.first,ans.second);
}

int main()
{
    Node* root = NULL;
    root = buildTree(root);
    cout<<maxsum(root);
    return 0;
}