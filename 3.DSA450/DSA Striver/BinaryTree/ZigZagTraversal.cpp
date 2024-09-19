#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. 
(i.e., from left to right, then right to left for the next level and alternate between).
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 */

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        // If the tree is empty, return an empty result
        if (root == nullptr) {
            return ans;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        bool rightToLeft = false;
        
        // Standard level-order traversal using a queue
        while (!q.empty()) {
            int size = q.size();
            vector<int> temp(size); // To store nodes at the current level
            
            for (int i = 0; i < size; i++) {
                TreeNode* front = q.front();
                q.pop();
                
                // Determine the index for placing the node's value
                int index = rightToLeft ? size - i - 1 : i;
                temp[index] = front->val;
                
                // Enqueue left and right children of the current node
                if (front->left) {
                    q.push(front->left);
                }
                if (front->right) {
                    q.push(front->right);
                }
            }
            
            // Toggle the direction for the next level
            rightToLeft = !rightToLeft;
            
            // Add the current level's nodes to the final answer
            ans.push_back(temp);
        }
        
        return ans;
    }
};


int main(){

return 0;
}