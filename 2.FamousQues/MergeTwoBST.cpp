#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*
Merge two BST 's:
Given two BSTs, return elements of merged BSTs in sorted form.

Sol:
Apporach 1:
We can convert both the list to Double linked list and  then merge both the linked list and print that

apporach 2:
will be using DFS : this may not work as it need to be done in a stored order:

Apporch 3: 
Using stacks:

 */
class Node
{
public:
    int data;
    Node *right;
    Node *left;
    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
void BSTtoDLL(Node *root, Node *&head)
{
    if (root == NULL)
    {
        return;
    }
    BSTtoDLL(root->right, head);

    root->right = head;

    if (head)
    {
        head->left = root;
    }
    head = root;

    BSTtoDLL(root->left, head);
}

vector<int> mergeDLL(Node *head1, Node *head2)
{
    vector<int> ans;
    if (head1 == NULL && head2 == NULL)
    {
        return ans;
    }
    if (head1 == NULL)
    {
        while (head2)
        {
            ans.push_back(head2->data);
            head2 = head2->right;
        }
        return ans;
    }
    if (head2 == NULL)
    {
        while (head1)
        {
            ans.push_back(head1->data);
            head1 = head1->right;
        }
        return ans;
    }

    while (head1 && head2)
    {
        if (head1->data < head2->data)
        {
            ans.push_back(head1->data);
            head1 = head1->right;
        }
        else
        {
            ans.push_back(head2->data);
            head2 = head2->right;
        }
    }
    while (head1)
    {
        ans.push_back(head1->data);
        head1 = head1->right;
    }
    while (head2)
    {
        ans.push_back(head2->data);
        head2 = head2->right;
    }
    return ans;
}

vector<int> merge(Node *root1, Node *root2)
{
    Node *head1 = NULL;
    BSTtoDLL(root1, head1);
    Node *head2 = NULL;
    BSTtoDLL(root2, head2);

    vector<int> ans = mergeDLL(head1, head2);
    return ans;
}

/*
Using stacks:
Consider two stacks s1 and s2 which stores the elements of the two trees.
Store the left view value of a tree1 in s1 and of tree2 in s2.
Compare the top values present in the stack and push the value accordingly in the result vector.
*/
 
vector<int> mergeTwoBST(Node* root1, Node* root2)
{
    vector<int> res;
    stack<Node*> s1, s2;
    while (root1 || root2 || !s1.empty() || !s2.empty()) {
        while (root1) {
            s1.push(root1);
            root1 = root1->left;
        }
        while (root2) {
            s2.push(root2);
            root2 = root2->left;
        }
        // Step 3 Case 1:-
        if (s2.empty()|| (!s1.empty()
                && s1.top()->val <= s2.top()->val)) {
            root1 = s1.top();
            s1.pop();
            res.push_back(root1->val);
            root1 = root1->right;
        }
        // Step 3 case 2 :-
        else {
            root2 = s2.top();
            s2.pop();
            res.push_back(root2->val);
            root2 = root2->right;
        }
    }
    return res;
}

int main()
{

    return 0;
}