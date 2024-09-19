#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  */

vector<int> inorderTraversal(TreeNode *root)
{
    TreeNode *curr = root;
    vector<int> ans;

    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            // If there is no left subtree, visit the current node and move to the right subtree
            ans.push_back(curr->val);
            curr = curr->right;
        }
        else
        {
            // Find the inorder predecessor of the current node
            TreeNode *pred = curr->left;
            while (pred->right != NULL && pred->right != curr)
            {
                pred = pred->right;
            }

            // If the right child of the predecessor is NULL, link it to the current node
            if (pred->right == NULL)
            {
                pred->right = curr;
                curr = curr->left;
            }
            else
            {
                // If the right child of the predecessor is already linked to the current node,
                // break the link, visit the current node, and move to the right subtree
                pred->right = NULL;
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
    }

    return ans;
}

int main()
{

    return 0;
}