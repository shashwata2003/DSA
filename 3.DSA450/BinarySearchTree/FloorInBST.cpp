#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*
You are given a BST (Binary search tree) with’ N’ number of nodes and a value ‘X’. Your task is to
find the greatest value node of the BST which is smaller than or equal to ‘X’.

Note :‘X’ is not smaller than the smallest node of BST .

For example:
In the above example, For the given BST  and X = 7, the greatest value node of the BST  which is smaller
than or equal to  7 is 6.

Steps:
Start at the root Node
If root->data == key, the floor of the key is equal to the root.
Else if root->data > key, then the floor of the key must lie in the left subtree.
Else floor may lie in the right subtree but only if there is a value lesser than or equal to the key.
If not, then the root is the key.

 */
class TreeNode
{
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};
int floorInBST(TreeNode<int> *root, int X)
{
    if (root == NULL)
    {
        return INT_MAX;
    }

    if (root->val == X){
        return root->val;
    }

    if(root->val > X){
        return floorInBST(root->left,X);
    }

    int floorval = floorInBST(root->right,X);

    if(floorval <= X){
        return floorval;
    }
    else{
        return root->val;
    }
}

int main()
{

    return 0;
}