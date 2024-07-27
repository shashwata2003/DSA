#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* Is Binary Tree Heap
Given a binary tree. The task is to check whether the given tree follows the max heap property or not.
Note: Properties of a tree to be a max heap - Completeness and Value of node greater than or equal to 
its child.

eg:
Input:
      5
    /  \
   2    3
Output: 1
Explanation: The given tree follows max-heap property since 5,
is root and it is greater than both its children.

Sol:
We need check of complete Binary tree and max heap property.
Apporach:
To check complete Binary tree:
1. run a total node counts and index 
2. if the current index > total node count return false
3. after that check roots left and right node and send the index as 2*i+1 and +2 

to check the max order
here we need to check three cond. 1. leaf node 2. only left and 3. both child
1. if leaf return true
2. if only left check if left is less than its parent
3. else check both child data is less than the parent and both left and right are max order or not. if so 
return true

TS: O(N)
Sp: O(N)
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

Node* buildBSTtree(Node* root) {
    int data;
    cin >> data;
    if (data == -1) {
        return NULL;
    }
    root = new Node(data);
    cout << "Enter left of " << data << endl;
    root->left = buildBSTtree(root->left);
    cout << "Enter right of " << data << endl;
    root->right = buildBSTtree(root->right);
    return root;
}

int countsnodes(Node* root){
  if(root== NULL){
    return 0;
  }
  int ans = 1+countsnodes(root->left)+countsnodes(root->right);
  return ans;
}

bool isCBT(Node* root, int i, int cnt){
  if(root == NULL){
    return true;
  }
  if(i>cnt){
    return false;
  }
  else{
    bool left = isCBT(root->left,2*i+1,cnt);
    bool right = isCBT(root->right,2*i+2,cnt);
    return (left&&right);
  }
}

bool isMaxOrder(Node* root){
  if(root->left == NULL && root->right == NULL){
    return true;
  }
  if(root->right == NULL){
    return (root->data > root->left->data);
  }else{
    bool left = isMaxOrder(root->left);
    bool right = isMaxOrder(root->right);

    return (left && right && (root->data > root->left->data && root->data > root->right->data));
  }
}

bool isHeap(Node* root){
  int index=0;
  int nodes = countsnodes(root);
  if(isCBT(root, index, nodes) && isMaxOrder(root)){
    return true;
  }else{
    return false;
  }
}


int main(){
  Node* root = NULL;
  root = buildBSTtree(root);
  cout<<isHeap(root);

return 0;
}