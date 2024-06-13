#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*
Vertical order traversal:
Given a Binary tree we need to do a vertical order traversal from left to right.
If there are multiple nodes passing from a single vertical we need to print then as the appear.

Solution:
See the node book once for visual undersatnding.
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

Node *buildTree(Node *root)
{
    int data;
    cin >> data;
    root = new Node(data);
    if (data == -1)
    {
        return NULL;
    }
    cout << "left Node" << data << endl;
    root->left = buildTree(root->left);
    cout << "right node" << data << endl;
    root->right = buildTree(root->right);
    return root;
}

vector<int> verticalordertraversal(Node *root)
{
    vector<int> ans;
    // consists of horizontal dist, level and the nodes data
    map<int, map<int, vector<int>>> nodes;
    // consists of the current node, HD, level
    queue<pair<Node *, pair<int, int>>> q;
    //NULL check
    if (root == NULL)
    {
        return ans;
    }
    // Push the root node and root has both level = 0 and horizontal dist = 0
    q.push(make_pair(root, make_pair(0, 0)));
    // check till the queue is empty or not 
    while (!q.empty())
    {
        // check thr front of the queue and pop it out.
        pair<Node *, pair<int, int>> front = q.front();
        q.pop();
        // store the nessary info 
        Node *frontnode = front.first;
        int hd = front.second.first;
        int lvl = front.second.second;

        // Store the nessary info in the map of nodes
        nodes[hd][lvl].push_back(frontnode->data);
        // check for left and right of the current node
        if (frontnode->left)
        {
            q.push(make_pair(frontnode->left, make_pair(hd - 1, lvl + 1)));
        }
        if (frontnode->right)
        {
            q.push(make_pair(frontnode->right, make_pair(hd + 1, lvl + 1)));
        }
    }

    // now store the val in the vector in the ans vector using multiple loops
    for(auto i: nodes){
        for(auto j:i.second){
            for(auto k: j.second){
                ans.push_back(k);
            }
        }
    }
    return ans;
}

int main()
{
    Node* root = NULL;
    root = buildTree(root);
    vector<int> ans = verticalordertraversal(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
    return 0;
}