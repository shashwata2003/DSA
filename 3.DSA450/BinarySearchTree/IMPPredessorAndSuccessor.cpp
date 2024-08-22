#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
There is BST given with the root node with the key part as an integer only. You need to find the in-order 
successor and predecessor of a given key. If either predecessor or successor is not found, then set it to NULL.

Note:- In an inorder traversal the number just smaller than the target is the predecessor and the number 
just greater than the target is the successor. 

Here we need to find the inorder predessor and succesor not the pred and secc on the tree.
 */

/*steps:
1. find the element in the tree
2. at the node the max val in the left subtree will be the pred
3. and the min val in the right sub will be the succ
*/

class Solution
{
    private:
        // Helper function to find the maximum value node in the left subtree
        Node* maxinsub(Node* root) {
            while (root && root->right != nullptr) {
                root = root->right;
            }
            return root;
        }

        // Helper function to find the minimum value node in the right subtree
        Node* mininsub(Node* root) {
            while (root && root->left != nullptr) {
                root = root->left;
            }
            return root;
        }

    public:
        // Function to find predecessor and successor
        void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
            if (root == nullptr) {
                return;
            }

            Node* temp = root;
            while (temp != nullptr) {
                // If key is found, break out of the loop
                if (temp->key == key) {
                    break;
                }
                
                // If key is smaller, update successor and move left
                if (temp->key > key) {
                    suc = temp;
                    temp = temp->left;
                }
                // If key is larger, update predecessor and move right
                else {
                    pre = temp;
                    temp = temp->right;
                }
            }

            // If key is found, check left and right subtrees for predecessor and successor
            if (temp != nullptr) {
                if (temp->left != nullptr) {
                    pre = maxinsub(temp->left);
                }
                if (temp->right != nullptr) {
                    suc = mininsub(temp->right);
                }
            }
        }
};


int main(){

return 0;
}