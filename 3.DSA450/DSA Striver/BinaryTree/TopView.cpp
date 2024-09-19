#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Top View of Binary Tree
Example 1:

Input:
      1
   /    \
  2      3
Output: 2 1 3
Example 2:

Input:
       10
    /      \
  20        30
 /   \    /    \
40   60  90    100
Output: 40 20 10 30 100
 */

class Solution {
public:
    // Function to return a list of nodes visible from the top view 
    // from left to right in Binary Tree.
    vector<int> topView(Node* root) {
        vector<int> ans;
        if (root == NULL) {
            return ans;
        }
        
        map<int, int> mp; // To maintain the order of horizontal distances ans to sort them
        queue<pair<Node*, int>> q;
        
        q.push({root, 0});
        
        while (!q.empty()) {
            pair<Node*, int> front = q.front();
            q.pop();
            Node* node = front.first;
            int hd = front.second;
            
            // Only insert the node if this horizontal distance is not seen before
            if (mp.find(hd) == mp.end()) {
                mp[hd] = node->data;
            }
            
            if (node->left) {
                q.push({node->left, hd - 1});
            }
            if (node->right) {
                q.push({node->right, hd + 1});
            }
        }
        
        // Extracting the values from the map and storing them in the answer vector
        for (auto it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};

int main(){

return 0;
}