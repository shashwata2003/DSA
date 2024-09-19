#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*
Binary Tree Postorder Traversal:
Given the root of a binary tree, return the postorder traversal of its nodes' values.

Input: root = [1,null,2,3]
Output: [3,2,1]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
 

 */

void solve(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    solve(root->left, ans);
    solve(root->right, ans);
    ans.push_back(root->val);
}

vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> ans;
    solve(root, ans);
    return ans;
}

int main()
{

    return 0;
}