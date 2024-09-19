#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an 
edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need 
to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.

Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.

Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.
 */

class Solution {
public:
    /*
    Steps:
    1. For each node, recursively find the maximum sum from the left and right subtrees.
    2. Update the global maximum path sum (maxi) by considering the sum of the current node value 
       plus the maximum sums from both left and right subtrees.
    3. Return the maximum path sum from either the left or right subtree plus the current node value,
       which represents the maximum path that can be extended to the parent node.
    */

    int solve(TreeNode* root, int &maxi) {
        // Base case: if the node is null, return 0 (no contribution to the path sum)
        if (root == nullptr) {
            return 0;
        }

        // Recursively find the maximum path sum from the left and right subtrees
        // We take max(0, ...) to avoid negative contributions to the path sum
        int left = max(0, solve(root->left, maxi));
        int right = max(0, solve(root->right, maxi));

        // Update the global maximum path sum if the current path through the root
        // (including both left and right subtrees) is greater than the current maximum
        maxi = max(maxi, right + left + root->val);

        // Return the maximum sum that can be extended to the parent node
        // Only one path (either left or right) can be taken upwards
        return max(left, right) + root->val;
    }

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN; // Initialize the maximum path sum to a very small value
        solve(root, maxi);  // Start the recursion from the root node
        return maxi;        // Return the final maximum path sum
    }
};


int main(){

return 0;
}