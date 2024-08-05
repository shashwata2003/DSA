#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Bottom veiw:
Given a binary tree print the element which can be veiwed from the buttom angle.

sol:
Here we are going to do the same as the top veiw the only difference will be that we will update the val of 
each HD till end and only take the last val of the node.
So only here we will check the if condition if it is empty or not we will just update the val in the nodes 
till the end and consider the last val.

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

vector<int> buttomview(Node* root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    // mapping the horizontal distance with the node val
    map<int,int> nodes;
    //pair of node and the HD 
    queue<pair<Node*,int>> q;
    q.push(make_pair(root,0));
    while (!q.empty())
    {
        pair<Node*,int> front = q.front();
        q.pop();
        int hd = front.second;
        Node* frontNode = front.first;
        // no need to check weather the hd spot is empty or not, just update it until the last instance and 
        // here we constantly update the val in the map till the end
        // use the last calculated val.
            nodes[hd] = frontNode->data;
        
        if(frontNode -> left){
            q.push(make_pair(frontNode->left,hd-1));
        }
        if(frontNode -> right){
            q.push(make_pair(frontNode->right,hd+1));
        }
    }
    for(auto i: nodes){
        ans.push_back(i.second);
    }

    return ans;
    
}

int main(){
    Node* root = NULL;
    root = buildTree(root);
    vector<int> ans = buttomview(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
return 0;
}