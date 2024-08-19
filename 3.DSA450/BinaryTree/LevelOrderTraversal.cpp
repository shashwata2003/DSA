#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;

        // Using a map to store nodes at each level
        map<int, vector<int>> mp;
        // Using a queue for level order traversal
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        
        while (!q.empty()) {
            pair<TreeNode*, int> front = q.front();
            q.pop(); // Remove the front element
            int lvl = front.second;
            TreeNode* node = front.first;
            mp[lvl].push_back(node->val);

            // Add the left child to the queue with the next level
            if (node->left) {
                q.push({node->left, lvl + 1});
            }
            // Add the right child to the queue with the next level
            if (node->right) {
                q.push({node->right, lvl + 1});
            }
        }

        // Collect the result from the map
        for (auto i : mp) {
            ans.push_back(i.second);
        }
        return ans;
    }
};

int main(){

return 0;
}