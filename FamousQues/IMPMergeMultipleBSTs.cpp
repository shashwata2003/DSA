#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
You are given n BST (binary search tree) root nodes for n separate BSTs stored in an array trees (0-indexed). 
Each BST in trees has at most 3 nodes, and no two roots have the same value. In one operation, you can:

Select two distinct indices i and j such that the value stored at one of the leaves of trees[i] is equal 
to the root value of trees[j].
Replace the leaf node in trees[i] with trees[j].
Remove trees[j] from trees.
Return the root of the resulting BST if it is possible to form a valid BST after performing n - 1 operations, 
or null if it is impossible to create a valid BST.

A BST (binary search tree) is a binary tree where each node satisfies the following property:

Every node in the node's left subtree has a value strictly less than the node's value.
Every node in the node's right subtree has a value strictly greater than the node's value.
A leaf is a node that has no children.


Create two hash tables: valToNode to store each root node indexed by its value and count to store the 
frequencies of each value.
Iterate through the input trees, updating the hash tables.
For each tree in trees, check if the count of the tree's root value is 1. If it is, try to build a BST 
using a helper function isValidBST. If the resulting BST is valid and valToNode has at most one remaining entry, return the tree's root.
If no valid BST can be created, return null.

https://algo.monster/liteproblems/1932
 */

class TreeNode{
    public:
    int val;
    TreeNode* right;
    TreeNode* left;

    TreeNode(int d){
        this->val = d;
        this->left = NULL;
        this->right = NULL;
    }
};

bool isvalid(TreeNode* curr, TreeNode* maxnode, TreeNode* minnode, unordered_map<int,TreeNode*> &valtonode){
    if(curr == NULL){
        //if it is leaf node
        return true;
    }
    if ((maxnode && curr->val >= maxnode->val) || (minnode && curr->val <= minnode->val)) {
        return false;
    }
    if(curr->left == NULL && curr->right == NULL && valtonode.count(curr->val)){
        //For leaf nodes
        //for the leaf node of one tree and checking weather id  that same leaf is a node in other tree:
        //if there is then map that other nodes child with this ones 
        int val = curr->val;
        curr->left = valtonode[val]->left;
        curr->right = valtonode[val]->right;
        valtonode.erase(val);
    }
    return isvalid(curr->left, curr, minnode,valtonode) && isvalid(curr->right, maxnode,curr,valtonode);
}


TreeNode* canMerge(vector<TreeNode*>& trees) {
    if(trees.size == 0){
        return NULL;
    }
    unordered_map<int,TreeNode*> valtonode; // map to store the node with its val
    unordered_map<int,int> count;    // to store the node val with the count:
    // The root will the one whose count is 1:

    for(TreeNode* root : trees){
        valtonode[root->val] = root;
        ++count[root->val];
        if(root->left){
            ++count[root->left->val];
        }
        if(root->right){
            ++count[root->right->val];
        }
    }

    for(TreeNode* tree : trees){
        if(count[tree->val] == 1){
            TreeNode* maxnode = NULL, minnode = NULL;
            //After running is valid if a single node is left then the ans will be that node.
            //Is valid will merge the trees
            if(isvalid(tree,maxnode,minnode,valtonode) && valtonode.size() <= 1){
                return tree;
            }
            return NULL;
        }
    }
    return NULL;
}

int main(){

return 0;
}