#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*
Construct a BT from Inorder/PostOrder traversal:
Given Two int arrays of inorder and postorder traversal val. we need to build a tree using both the array values.
and we need to print the post order(left right root) of the built tree.
eg: Inorder(Left root right):[3 1 4 0 5 2]
postorder(left right root): [0 1 3 4 2 5]
out: 3 4 1 5 2 0

Sol:
we will do the same like the previous question just we need to start from the end of the post array and need to
build the right subtree first.

 */

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
// TS: o(nlogn)

// Function to return a tree created from postorder and inoreder traversals.

int findpos(int node, int in[], int n, int ins, int ine)
{
    for (int i = ins; i <= ine; i++)
    {
        if (in[i] == node)
        {
            return i;
        }
    }
    return -1;
}

Node *solve(int in[], int post[], int n, int ins, int ine, int &ps)
{
    if (ps < 0 || ins > ine)
    {
        return NULL;
    }

    int front = post[ps];
    ps--;
    Node *root = new Node(front);
    int pos = findpos(front, in, n, ins, ine);

    // right before left:
    root->right = solve(in, post, n, pos + 1, ine, ps);
    root->left = solve(in, post, n, ins, pos - 1, ps);

    return root;
}

Node *buildTree(int n, int in[], int post[])
{
    int instart = 0;
    int inend = n - 1;
    int poststart = n - 1;
    Node *ans = solve(in, post, n, instart, inend, poststart);
    return ans;
}

void postorderprint(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorderprint(root->left);
    postorderprint(root->right);
    cout << root->data << " ";
}

int main()
{
    Node *root = NULL;
    int n = 6;
    int in[n] = {3, 1, 4, 0, 5, 2};
    int post[n] = {0, 1, 3, 4, 2, 5};
    root = buildTree(post, in, n);
    postorderprint(root);
    return 0;
}