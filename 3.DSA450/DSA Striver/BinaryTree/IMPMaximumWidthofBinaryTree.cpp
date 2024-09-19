#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null 
nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending 
down to that level are also counted into the length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer.

Input: root = [1,3,2,5,3,null,9]
Output: 4
Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).

Input: root = [1,3,2,5,null,null,9,6,null,7]
Output: 7
Explanation: The maximum width exists in the fourth level with length 7 (6,null,null,null,null,null,7).

Example 3:
Input: root = [1,3,2,5]
Output: 2
Explanation: The maximum width exists in the second level with length 2 (3,2).
 */

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        // Initialize the answer to store the maximum width
        int ans = 0;
        // Use a queue to perform level order traversal
        queue<pair<TreeNode*, int>> q;
        // Start with the root node at index 0
        q.push({root, 0});

        // Continue until the queue is empty
        while (!q.empty()) {
            // Get the number of nodes at the current level
            int size = q.size();
            // Get the minimum index at the current level
            int mmin = q.front().second; // Minimum index at this level
            int first = 0, last = 0; // Variables to store the first and last indices at this level

            // Process all nodes at the current level
            for (int i = 0; i < size; i++) {
                // Get the current node's index normalized by subtracting mmin
                int curr_id = q.front().second - mmin;
                TreeNode* node = q.front().first;

                // Remove the processed node from the queue
                q.pop();
                // Update the first and last index for this level
                if (i == 0) {
                    first = curr_id; // The first node's index at this level
                }
                if (i == size - 1) {
                    last = curr_id; // The last node's index at this level
                }

                // Add the left child to the queue with its calculated index
                if (node->left) {
                    q.push({node->left, 2 * curr_id + 1});
                }
                // Add the right child to the queue with its calculated index
                if (node->right) {
                    q.push({node->right, 2 * curr_id + 2});
                }
            }
            // Calculate the width of this level and update the maximum width
            ans = max(ans, last - first + 1);
        }
        // Return the maximum width found
        return ans;
    }
};

int main(){

return 0;
}