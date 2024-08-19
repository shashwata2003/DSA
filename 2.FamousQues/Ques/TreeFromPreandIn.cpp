#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Construct Tree from Inorder & Preorder:
Given 2 Arrays of Inorder and preorder traversal. The tree can contain duplicate elements. 
Construct a tree and print the Postorder traversal. 

Example 1:

Input:
N = 4
inorder[] = {1 6 8 7}
preorder[] = {1 6 7 8}
Output: 8 7 6 1
Example 2:

Input:
N = 6
inorder[] = {3 1 4 0 5 2}
preorder[] = {0 1 3 4 2 5}
Output: 3 4 1 5 2 0
Explanation: The tree will look like
       0
    /     \
   1       2
 /   \    /
3    4   5
 */
class Solution {
public:
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int pres, int ins, int ine, int n, unordered_map<int,int>& mp) {
        if (pres >= n || ins > ine) {
            return NULL;
        }
        int first = preorder[pres];
        TreeNode* root = new TreeNode(first);
        int pos = mp[first];
        root->left = solve(preorder, inorder, pres + 1, ins, pos - 1, n, mp);
        root->right = solve(preorder, inorder, pres + (pos - ins) + 1, pos + 1, ine, n, mp); // Adjusted the preorder index
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }
        return solve(preorder, inorder, 0, 0, n - 1, n, mp);
    }
};
int main(){

return 0;
}