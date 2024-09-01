#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.
 */

class Solution {
public:
    void inordertraversal(TreeNode* root, vector<int> &inorder){
        if(root == NULL){
            return;
        }
        inordertraversal(root->left,inorder);
        inorder.push_back(root->val);
        inordertraversal(root->right,inorder);

    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        inordertraversal(root,inorder);

        int i = 0;
        int j = inorder.size()-1;
        while(i<j){
            if(inorder[i]+inorder[j] == k){
                return true;
            }
            else if(inorder[i]+inorder[j] > k){
                j--;
            }
            else{
                i++;
            }
        }
        return false;
    }
};

int main(){

return 0;
}