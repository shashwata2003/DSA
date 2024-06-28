#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Largest BST in the BInary tree:
We are given a Simple binary tree, Our job is to find the maximum size of the binary size tree present in the 
Binary tree.
eg:
Sample Input 1 :
2 1 3 -1 -1 -1 -1
Sample Output 1:
3

Sol:
Apporach 1: Brute Froce:
Here we will traverse all the node and check weather the tree is a bst or not, if yes then store the size and 
return the size. here we have to traverse each node twice 
TS: O(n2)
SP: O()

Apporach 2:
Here we use recursion and the store the val of nodes which we already visited
steps to check is valid:
1. check left is balaced or not
2. check right balanced or not
3. max left < root ->data < min left

to do it we will use pair data type and we need the following info:
1. min 2. max 3. isBST 4. size
we need this for each node and will be store in a pair datatype
 */

class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node(int d) {
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

class info{
    public:
    int max;
    int min;
    bool isBST;
    int size;
};

info solve(Node* root , int &maxsize){
    //base case:
    if(root == NULL){
        return {INT_MIN, INT_MAX, true, 0};
    }
    // check right and left subtree:
    info left = solve(root->left, maxsize);
    info right = solve(root->right, maxsize);
    // setting all value of the current node.
    info curr;
    curr.max = max(root->data, right.max);
    curr.min = min(root->data,left.min);
    curr.size = left.size +right.size+1;
    if(left.isBST && right.isBST && (root->data>left.max && root->data <right.min)){
        curr.isBST = true;
    }else{
        curr.isBST = false;
    }

    //Updating the max size
    if(curr.isBST){
        maxsize = max(curr.size,maxsize);
    }
    return curr;
}

int largestBST(Node* root){
    int maxsize = 0;
    info temp = solve(root, maxsize);
    return maxsize;
}

int main(){
    Node* root = NULL;
    root = buildBSTtree(root);
    cout<<largestBST(root);
return 0;
}