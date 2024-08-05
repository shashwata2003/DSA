#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  */

int maxheight(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int left = maxheight(root->left);
        int right = maxheight(root->right);
        return 1+max(left,right);
}

pair<int, int> maxheightanddiameter(TreeNode* root) {
    if (root == NULL) {
        // height and diameter
        return make_pair(0, 0);
    }

    // Get height and diameter of left and right subtrees
    pair<int, int> left = maxheightanddiameter(root->left);
    pair<int, int> right = maxheightanddiameter(root->right);

    pair<int, int> ans;
    ans.first = max(left.first, right.first) + 1;  // Height of the current node
    ans.second = max({left.second, right.second, left.first + right.first});  // Diameter

    return ans;
}


int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int left = diameterOfBinaryTree(root->left);
        int right = diameterOfBinaryTree(root->right);
        int bothheight =  maxheight(root->left) + maxheight(root->right);
        int ans =  max(bothheight,max(right,left));
        return ans;
}

int main(){

return 0;
}