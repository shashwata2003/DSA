#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Serialization is the process of converting a data structure or object into a sequence of bits so that it 
can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed 
later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your 
serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be 
serialized to a string and this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not 
necessarily need to follow this format, so please be creative and come up with different approaches yourself.

Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]
 */
class Codec {
public:
    // Serializes a binary tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root, out);  // Helper function to perform the serialization
        return out.str();
    }

    // Deserializes a string to reconstruct the binary tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);  // Helper function to perform the deserialization
    }

private:
    // Helper function to serialize the tree using pre-order traversal
    void serialize(TreeNode* root, ostringstream& out) {
        if (root) {
            out << root->val << ' ';  // Add the current node's value followed by a space
            serialize(root->left, out);  // Recur on the left child
            serialize(root->right, out);  // Recur on the right child
        } else {
            out << "# ";  // Use '#' to represent a null node
        }
    }

    // Helper function to deserialize the string and reconstruct the tree
    TreeNode* deserialize(istringstream& in) {
        string val;
        in >> val;  // Read the next value from the stream
        if (val == "#") {
            return nullptr;  // If the value is '#', it represents a null node
        }
        TreeNode* root = new TreeNode(stoi(val));  // Convert the value to an integer and create a new node
        root->left = deserialize(in);  // Recur to construct the left subtree
        root->right = deserialize(in);  // Recur to construct the right subtree
        return root;
    }
};


int main(){

return 0;
}