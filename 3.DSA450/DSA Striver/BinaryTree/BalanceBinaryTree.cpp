#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  */

class Solution {
private:
    pair<int,bool> solve(TreeNode* root) {
        if (root == nullptr) {
            return {0, true};
        }

        pair<int,bool> left = solve(root->left);
        pair<int,bool> right = solve(root->right);

        pair<int,bool> ans;
        ans.first = 1 + max(left.first, right.first);
        ans.second = left.second && right.second && abs(left.first - right.first) <= 1;

        return ans;
    }
public:
    bool isBalanced(TreeNode* root) {
        return solve(root).second;
    }
};

int main(){

return 0;
}