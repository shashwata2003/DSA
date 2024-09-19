#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Given a Binary Tree of nodes, you need to find all the possible paths from the root node to all the leaf nodes 
of the binary tree.

Example 1:
Input:
       1
    /     \
   2       3
Output: 
1 2 
1 3 
Explanation: 
All possible paths:
1->2
1->3

Example 2:
Input:
         10
       /    \
      20    30
     /  \
    40   60
Output: 
10 20 40 
10 20 60 
10 30 
 */

class Solution {
private:
    void solve(Node* root, vector<vector<int>> &ans, vector<int> &temp) {
        if (root == NULL) {
            return;
        }
        temp.push_back(root->data);
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(temp);
        } else {
            if (root->left) {
                solve(root->left, ans, temp);
            }
            if (root->right) {
                solve(root->right, ans, temp);
            }
        }
        temp.pop_back();
    }

public:
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(root, ans, temp);
        return ans;
    }
};

int main(){

return 0;
}