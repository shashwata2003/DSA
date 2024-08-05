#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Given a string S of distinct character of size N and their corresponding frequency f[ ] i.e. character S[i] 
has f[i] frequency. Your task is to build the Huffman tree print all the huffman codes in preorder traversal 
of the tree.
Note: While merging if two nodes have the same value, then the node which occurs at first will be taken on the 
left of Binary Tree and the other one to the right, otherwise Node with less value will be taken on the left 
of the subtree and other one to the right.

Example 1:

S = "abcdef"
f[] = {5, 9, 12, 13, 16, 45}
Output: 
0 100 101 1100 1101 111

Sol:
here to make the huffan tree we need to use the min heap, we will first find the two nodes with least freq
and combine them to push it back in the heap

TS:O(nlog n)
SP:O(n)
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

class cmp{
    public:
    bool operator()(Node* a, Node* b){
        return a->data > b->data;
    }
};

void treverse(Node* root, vector<string> &ans, string temp){
    if(root->left == NULL && root->right == NULL){
        ans.push_back(temp);
        return;
    }

    treverse(root->left,ans,temp+'0');
    treverse(root->right,ans,temp+'1');
}

vector<string> huffmanCodes(string S,vector<int> f,int N)
{
	priority_queue<Node*,vector<Node*>,cmp> pq;
    for (int i = 0; i < N; i++)
    {
        Node* temp = new Node(f[i]);
        pq.push(temp);
    }

    while (pq.size()>1)
    {
        Node* first = pq.top();
        pq.pop();
        Node* second = pq.top();
        pq.pop();

        Node* newnode = new Node(first->data + second->data);
        newnode->right = second;
        newnode->left = first;
        pq.push(newnode);
    }
    Node* root = pq.top();
    vector<string> ans;
    string temp = "";
    treverse(root,ans,temp);
    return ans;
    
}

int main(){
string S = "abcdef";
vector<int> f = {5, 9, 12, 13, 16, 45};
int n = 6;
vector<string> ans = huffmanCodes(S,f,n);
for (int i = 0; i < ans.size(); i++)
{
    cout<<ans[i]<<" ";
}

return 0;
}