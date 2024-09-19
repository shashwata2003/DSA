#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) 
of all the values of the nodes in the tree.
Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3
 */

/*Apporach 1:
Steps:
As we know the smallest elements are present on the left subtree
1. move to the left till u reach the leaf
2. now start returning the leaf and incrementing a pointer called i 
3. if we right k with i then that is the kth smallest ans
4. if it is not in the left side do the same for the right subtree
*/
class Solution {
private:
    int solve(TreeNode* root, int k, int &i){
        if(root == NULL){
            return -1;
        }

        int left = solve(root->left,k,i);
        if(left != -1){
            return left;
        }

        i++;
        if(i == k){
            return root->val;
        }

        return solve(root->right,k,i);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int  i = 0;
        return solve(root,k,i);
    }
};

/*
Apporach 2:
we will traverse the tree inorder and print the k th element from the front.
*/

int main(){

return 0;
}