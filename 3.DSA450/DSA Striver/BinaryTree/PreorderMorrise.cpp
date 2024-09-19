#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  */

vector<int> getPreOrderTraversal(TreeNode *root) {
    TreeNode* curr = root;
    vector<int> ans;
    while (curr != NULL) {
        if (curr->left == NULL) {
            ans.push_back(curr->data);
            curr = curr->right;
        } else {
            TreeNode* pred = curr->left;
            while (pred->right != NULL && pred->right != curr) {
                pred = pred->right;
            }

            if (pred->right == NULL) {
                //We push the val here unlike in inorder
                pred->right = curr;
                ans.push_back(curr->data);
                curr = curr->left;
            } else {
                pred->right = NULL;
                curr = curr->right;
            }
        }
    }
    return ans;
}

int main(){

return 0;
}