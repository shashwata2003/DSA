#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Diameter of the tree.
The path between any two points
Apporach 1:
Here we are going to use recursion.
Base case: if root null return 0;
Here we will have three options.
1. op1: Max diameter from the left subtree only
2. op2: max diameter form the right subtree only
3. op3: Max diameter by mixing both right and left subtree which is max height of left subtree + max height of right
subtree + 1

hence max of all three of these will be the answer.
The major problem with this apporach is that we need to call the max height function also which makes the TS: o(n2)


Apporach 2:
Here we are trying to find both heights and diameter in the same function. 
1. So we will use a pair data type to store both the diameter and the height. pair.first = diameter and pair.second
= height.
2. firstly if the root is null then send both height and diameter = 0 
3. next call the recursive function to find the diameter and height of  both the sides left and right
4. now cal. the op1 op2 and op3 using the first and second of the given rights and left pairs
5. now create a pair to store the find ans which for
height max(op1, op2)+1 (store it in ans.second)
and for diameter max(op1,max(op2,op3)) (store it in ans.first)
6. now just return the ans.first after all the recursive calls are done.

TS: O(N)
SC: O(N)

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
    int data;
    cin>>data;
    root = new Node(data);
    if(data == -1){
        return NULL;
    }
    cout<<"left Node"<<data<<endl;
    root->left  = buildTree(root->left);
    cout<<"right node"<<data<<endl;
    root->right = buildTree(root->right);
    return root;
}

int maxheight(Node* root){
    if (root ==  NULL)
    {
        return 0;
    }
    int op1 = maxheight(root->left);
    int op2 = maxheight(root->right);
    int ans = max(op1,op2)+1;
    return ans;
    
}

int finddiameter1(Node* root){
    if(root == NULL){
        return 0;
    }
    int op1 = finddiameter1(root->left);
    int op2 = finddiameter1(root->right);
    int op3 = maxheight(root->left) + maxheight(root->right) + 1;
    int ans = max(op1,max(op2,op3));
    return ans;
}

pair<int,int> finddiameterfast(Node* root){
    if(root == NULL){
        pair<int,int> p = make_pair(0,0);
        return p;
    }
    pair<int,int> left = finddiameterfast(root->left);
    pair<int,int> right = finddiameterfast(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    pair<int,int> ans;
    ans.first = max(op1,max(op2,op3));
    ans.second = max(op1, op2) +1;
    return ans;
}

int finddiameter2(Node* root){
    return finddiameterfast(root).first;
}
int main(){
    Node* root = NULL;
    root = buildTree(root);
    cout<<"First "<<finddiameter1(root)<<endl;
    cout<<"second "<<finddiameter2(root)<<endl;

return 0;
}