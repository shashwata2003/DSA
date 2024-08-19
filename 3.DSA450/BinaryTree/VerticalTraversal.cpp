#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  
Verticle Order Traversal:

*/

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) {
            return ans;
        }

        // Map of horizontal distance to map of level to vector of node values
        //to sort the values using HD 
        map<int, map<int, vector<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> q;

        q.push({root, {0, 0}});

        while (!q.empty()) {
            pair<TreeNode*, pair<int, int>> front = q.front();
            q.pop();
            TreeNode* node = front.first;
            int hd = front.second.first;
            int lvl = front.second.second;

            nodes[hd][lvl].push_back(node->val);

            if (node->left) {
                q.push({node->left, {hd - 1, lvl + 1}});
            }
            if (node->right) {
                q.push({node->right, {hd + 1, lvl + 1}});
            }
        }

        // Extracting the values from the map and storing them in the answer vector
        for (auto& hd_map : nodes) {
            vector<int> column;
            for (auto& lvl_map : hd_map.second) {
                sort(lvl_map.second.begin(), lvl_map.second.end());
                column.insert(column.end(), lvl_map.second.begin(), lvl_map.second.end());
            }
            ans.push_back(column);
        }

        return ans;
    }
};

int main(){

return 0;
}