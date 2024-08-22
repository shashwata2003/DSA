#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*
Populating Next Right Pointers in Each Node:
You are given a perfect binary tree where all leaves are on the same level, and every parent has two children.
The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer
should be set to NULL.

Initially, all next pointers are set to NULL.
 */



class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

/*
Steps:
1. Do a breath first search of all the nodes using a queue
2. we will keep track of the horizontally previous element
3. if the prev exist then we will point the next to the curr
4. if not then point to null
*/

class Solution {
public:
    // Function to connect nodes at the same level
    Node* connect(Node* root) {
        // Base case: if the tree is empty, return NULL
        if (root == NULL) {
            return NULL;
        }
        
        // Queue for level-order traversal (BFS)
        queue<Node*> q;
        q.push(root);
        
        // While there are nodes to process in the queue
        while (!q.empty()) {
            // Get the number of nodes at the current level
            int size = q.size();
            // Initialize previous node pointer to NULL for the current level
            Node* prev = NULL;
            
            // Iterate through all nodes at the current level
            while (size--) {
                // Get the front node of the queue
                Node* temp = q.front();
                q.pop();
                
                // Push left and right children of the current node into the queue
                if (temp->left) {
                    q.push(temp->left);
                }
                if (temp->right) {
                    q.push(temp->right);
                }
                
                // If there's a previous node, connect its next pointer to the current node
                if (prev != NULL) {
                    prev->next = temp;
                }
                
                // Update the previous node to the current node
                prev = temp;
            }
            // After processing all nodes at this level, set the next pointer of the last node to NULL
            prev->next = NULL;
        }
        
        // Return the root of the tree after connecting nodes
        return root;
    }
};

int main()
{

    return 0;
}