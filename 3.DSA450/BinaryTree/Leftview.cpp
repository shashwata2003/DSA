#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Given a Binary Tree, return Left view of it. Left view of a Binary Tree is set of nodes visible when tree 
is visited from Left side. The task is to complete the function leftView(), which accepts root of the tree as 
argument. If no left view is possible, return an empty tree.

Left view of following tree is 1 2 4 8.

          1
       /     \
     2        3
   /     \    /    \
  4     5   6    7
   \
     8   

Examples :

Input:
   1
 /  \
3    2
Output: 1 3
 */


void solve(Node* root, int lvl, vector<int> &ans) {
    // If the current node is NULL, return
    if (root == NULL) {
        return;
    }
    
    // If the current level is equal to the size of the ans vector,
    // it means this is the first node of this level that we're visiting
    if (lvl == ans.size()) {
        ans.push_back(root->data);  // Add the current node's data to the ans vector
    }
    
    // Recursively visit the left subtree first, then the right subtree
    solve(root->left, lvl + 1, ans);  // Visit the left subtree with incremented level
    solve(root->right, lvl + 1, ans); // Visit the right subtree with incremented level
}

vector<int> leftView(Node *root)
{
    vector<int> ans;
    int lvl = 0;
    //Lvl is send to keep track where we are at in the left tree
    // if the left tree becomes null but there is a right node in the veiw then we will push that in ans.
    solve(root,lvl,ans);
    return ans;
}

/* right view */
void solve(Node* root, int lvl, vector<int> &ans) {
    // If the current node is NULL, return
    if (root == NULL) {
        return;
    }
    
    // If the current level is equal to the size of the ans vector,
    // it means this is the first node of this level that we're visiting
    if (lvl == ans.size()) {
        ans.push_back(root->data);  // Add the current node's data to the ans vector
    }
    
    // Recursively visit the left subtree first, then the right subtree
    solve(root->right, lvl + 1, ans); // Visit the right subtree with incremented level
    solve(root->left, lvl + 1, ans);  // Visit the left subtree with incremented level
}

vector<int> RightView(Node *root)
{
    vector<int> ans;
    int lvl = 0;
    //Lvl is send to keep track where we are at in the left tree
    // if the right tree becomes null but there is a right node in the veiw then we will push that in ans.
    solve(root,lvl,ans);
    return ans;
}

int main(){

return 0;
}