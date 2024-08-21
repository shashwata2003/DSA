#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Given a Binary Tree, convert it into its mirror.
Examples:

Input:
      1
    /  \
   2    3
Output: 3 1 2
Explanation: The tree is
   1    (mirror)  1
 /  \    =>      /  \
2    3          3    2
The inorder of mirror is 3 1 2
Input:
      10
     /  \
    20   30
   /  \
  40  60
Output: 30 10 60 20 40
Explanation: The tree is
      10               10
    /    \  (mirror) /    \
   20    30    =>   30    20
  /  \                   /   \
 40  60                 60   40
The inroder traversal of mirror is
30 10 60 20 40.
 */
class Solution {
public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        // Base case: If the tree is empty, return.
        if (node == NULL) {
            return;
        }

        // Create a queue to perform level-order traversal (BFS).
        queue<Node*> q;

        // Push the root node into the queue.
        q.push(node);

        // Continue until the queue is empty.
        while (!q.empty()) {
            // Get the front node from the queue.
            Node* front = q.front();
            q.pop();

            // Swap the left and right children of the current node.
            swap(front->left, front->right);

            // If the left child exists, push it to the queue.
            if (front->left) {
                q.push(front->left);
            }

            // If the right child exists, push it to the queue.
            if (front->right) {
                q.push(front->right);
            }
        }
    }
};
int main(){

return 0;
}