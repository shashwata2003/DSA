#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
 Min time to BURN tree:
Given a Binary tree and a target we need to find the minimum time to burn the entire tree if we set fire on the 
target node.
Given that it takes 1 sec to burn a node and the fire get spread to the connecting nodes.

Solution:
Here we are going to use multiple data types to find the optimal ans
1. Map to link a child node to its parent, as node has a link to it left and right child but node with its parent a
and the fire can move to a parent.
2. Map to keep a track of the visited nodes
3. a queue no keep track of the nodes we are supposed to visited after visiting a node.

Steps:
1. create the parent child map
2. Find the targer node
3. Find the min time to burn the tree,

TS: o(n)
SC: O(n)
 */

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;

            }
};


Node* buildTree(Node* root){
        cout<<"enter data"<<endl;
        int data;
        cin>>data;
        root = new Node(data);

        if(data == -1){
            return NULL;
        }
        cout<<"Enter data for left child "<<data<<endl;
        root->left = buildTree(root->left);
        cout<<"Enter data for the right child"<<data<<endl;
        root->right = buildTree(root->right);
        return root;
}


// This Function create a map between the child and the parent node also return the target node of the fire
// we are using simple level order traversal method.
Node* createmap(Node* root, map<Node*,Node*> &childtoparent, int target){
    queue<Node*> q;
    q.push(root);
    childtoparent[root] = NULL;
    Node* res = NULL;
    while (!q.empty())
    {
        Node* front = q.front();
        q.pop();
        // if the target is found.
        if(front->data == target){
            res = front;
        }
        // Tarversing the left and the right subtree
        if(front->left){
            childtoparent[front->left] = front;
            q.push(front->left);
        }
        if(front->right){
            childtoparent[front->right] = front;
            q.push(front->right);
        }
    }
    return res;
    
}

int buringtree(Node* root, map<Node*,Node*> mp){
    // 1. create a visited and queue 
    // 2. push the target node and make the visited map true for target
    map<Node*,bool> visited;
    queue<Node*> q;
    q.push(root);
    visited[root] = true;
    int ans = 0;
    while (!q.empty())
    {
        int size= q.size();
        bool flag = 0;
        
        for (int i = 0; i < size; i++)
        {
            Node* front = q.front();
            q.pop();
            // check right,left and the parent of the current node also check the visited array
            // if we are pushing the node in the queue we will increament the time counter
            // hence we use the flag which is set to true evertime we push and if it true we increment ans after the
            // for loop ends
            if(front->left && !visited[front->left]){
                flag = 1;
                q.push(front->left);
                visited[front->left] = true;
            }
            if(front->right && !visited[front->right]){
                flag = 1;
                q.push(front->right);
                visited[front->right] = true;
            }
            if(mp[front] && !visited[mp[front]]){
                flag = 1;
                q.push(mp[front]);
                visited[mp[front]] = true;
            }
        }
        // Incrementing the ans after each push once because the fire will burn both child and the parent 
        // in the same time of 1 sec
        if(flag == 1){
            ans++;
        }
        
    }
    return ans;
    
}

int findmintime(Node* root, int target){
    map<Node*,Node*> childtoparent;
    Node* t = createmap(root, childtoparent,target);
    int ans = buringtree(t,childtoparent);
    return ans;
}
int main(){
    Node* root = NULL;
    root = buildTree(root);
    cout<<findmintime(root,8);
return 0;
}