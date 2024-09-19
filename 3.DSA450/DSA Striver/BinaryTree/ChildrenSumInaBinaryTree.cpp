#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Given a binary tree having n nodes. Check whether all of its nodes have the value equal to the sum of their 
child nodes. Return 1 if all the nodes in the tree satisfy the given properties, else it return 0.

For every node, data value must be equal to the sum of data values in left and right children. Consider data 
value as 0 for NULL child.  Also, leaves are considered to follow the property.

Example 1:

Input:
Binary tree
       35
      /   \
     20  15
    /  \  /  \
   15 5 10 5
Output: 
1
Explanation: 
Here, every node is sum of its left and right child.
Example 2:

Input:
Binary tree
       1
     /   \
    4    3
   /  
  5    
Output: 
0
Explanation: 
Here, 1 is the root node and 4, 3 are its child nodes. 4 + 3 = 7 which is not equal to the value of root node. 
Hence, this tree does not satisfy the given condition.
 */

class Solution {
public:
    // Helper function that returns a pair containing:
    // 1. The value of the current node (or sum of its subtree).
    // 2. A boolean indicating if the subtree rooted at 'root' satisfies the sum property.
    pair<int, bool> solve(Node* root) {
        // Base case: If the node is null, return 0 as the sum and true as the boolean.
        if (root == NULL) {
            return {0, true};
        }
        
        // Base case: If the node is a leaf, it automatically satisfies the sum property.
        if (root->left == NULL && root->right == NULL) {
            return {root->data, true};
        }
        
        // Recursively check the left and right subtrees.
        pair<int, bool> left = solve(root->left);
        pair<int, bool> right = solve(root->right);
        
        // Initialize the answer for the current node.
        pair<int, bool> ans;
        ans.first = root->data;  // Store the value of the current node.
        
        // Check if the current node's value equals the sum of its children's values
        // and ensure that both left and right subtrees satisfy the sum property.
        ans.second = (root->data == (left.first + right.first)) && left.second && right.second;
        
        return ans;
    }
    
    // Main function to check the sum property for the entire tree.
    int isSumProperty(Node *root) {
        pair<int, bool> ans = solve(root);  // Call the helper function for the root.
        return ans.second;  // Return whether the tree satisfies the sum property.
    }
};


int main(){

return 0;
}