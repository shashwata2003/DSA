#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Left Traversal and right terversal:
Here we are given a binary tree , and we need to print the left veiw of it.

Sol:
We can solve using Level order or recursion:
1. level order:
similar to the top veiw method
Here we are going to print the first element of that particular level,
hence we will use the map function btw level and node.

2. Recursive Optimized:
here we push that data in the ans when we reach a new level.
and we check that by checking if the size of the ans  is === to the current level.
Here, we check if the current level (lvl) is equal to the size of the ans vector.
This condition is true only for the first node encountered at each level during the traversal.
If the condition is true, it means that the current node is the first node at this level that we are 
encountering from the right side view, so we add its data to the ans vector.

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

void solve(Node* root, vector<int>&ans , int level){
    //basecase:
    if(root==NULL){
        return;
    }
    //
    if(level == ans.size()){
        ans.push_back(root->data);
    }
    // This order determines that we are doing a left veiw or right veiw.
    solve(root->left,ans,level+1);
    solve(root->right,ans,level+1);
}

vector<int> leftveiw(Node* root){
    vector<int> ans;
    solve(root,ans,0);
    return ans;
}

void solve1(Node* root, vector<int>&ans , int level){
    //basecase:
    if(root==NULL){
        return;
    }

    if(level == ans.size()){
        ans.push_back(root->data);
    }
    // This order determines that we are doing a left veiw or right veiw.
    solve(root->right,ans,level+1);
    solve(root->left,ans,level+1);
}

vector<int> rightveiw(Node* root){
    vector<int> ans;
    solve1(root,ans,0);
    return ans;
}

int main(){

return 0;
}