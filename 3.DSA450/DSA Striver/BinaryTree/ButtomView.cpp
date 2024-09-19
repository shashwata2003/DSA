#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Bottom View of Binary Tree:
Input:
       1
     /   \
    3     2
Output: 3 1 2
Explanation: First case represents a tree with 3 nodes and 2 edges where root is 1, 
left child of 1 is 3 and right child of 1 is 2.
 */

/*
Steps:
1. Create a map to map the horizontal distance with the node
2. here will will update the nodes till the end as we have to find the buttom view
3. we need to use a queue to keep traversing the element.
*/

class Solution {
public:
    vector<int> bottomView(Node* root) {
        vector<int> ans;
        // Map of horizontal distance to node value as the ans should be in sorted based on HD
        map<int, int> mp;
        queue<pair<Node*, int>> q;

        if (root == NULL) {
            return ans;
        }

        q.push({root, 0});
        while (!q.empty()) {
            pair<Node*, int> front = q.front();
            q.pop();
            Node* node = front.first;
            int hd = front.second;
            // Update the value at each horizontal distance to the bottommost node
            mp[hd] = node->data;

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