#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search 
tree (BST):

BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is given as 
part of the constructor. The pointer should be initialized to a non-existent number smaller than any element 
in the BST.
boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise 
returns false.
int next() Moves the pointer to the right, then returns the number at the pointer.
Notice that by initializing the pointer to a non-existent smallest number, the first call to next() will 
return the smallest element in the BST.

You may assume that next() calls will always be valid. That is, there will be at least a next number in 
the in-order traversal when next() is called.
*/

class BSTIterator {
private:
    // Stack to store the nodes for in-order traversal
    stack<TreeNode*> st;

    // Helper function to push all the left nodes of the current subtree
    // onto the stack. This ensures that the smallest elements are on top.
    void pushall(TreeNode* root) {
        TreeNode* temp = root;
        // Traverse the left subtree and push all nodes onto the stack
        while (temp) {
            st.push(temp);
            temp = temp->left;
        }
    }

public:
    // Constructor initializes the iterator with the root of the BST.
    // It pushes all the left nodes starting from the root.
    BSTIterator(TreeNode* root) {
        pushall(root);
    }
    
    // Return the next smallest element in the BST.
    int next() {
        // The top element of the stack is the current smallest element.
        TreeNode* top = st.top();
        st.pop();
        
        // If the current node has a right child, push all the left nodes
        // of the right subtree onto the stack.
        if (top->right) {
            pushall(top->right);
        }

        // Return the value of the current node.
        return top->val;
    }
    
    // Return true if there are still nodes left to visit in the BST.
    bool hasNext() {
        // The stack is not empty if there are more elements to visit.
        return !st.empty();
    }
};


int main(){

return 0;
}