#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Given a binary tree. Find the size of its largest subtree which is a Binary Search Tree.
Note: Here Size equals the number of nodes in the subtree.

Sol:
Apporach 1:
Using a custome class to store, min , max, isbst, ans(current length) of each node
Main login to implement is 
A Tree is BST if following is true for every node x.
    The largest value in left subtree (of x) is smaller than value of x.
    The smallest value in right subtree (of x) is greater than value of x.
 */

class Node{
    public :
    int data;
    Node* left;
    Node* right;
    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};


/*
Apporach 1:
1. create a new custom class
2. Traverse each node DFS and update the value of each node 
3. check of BST or not 
*/

class info{
    public:
    int maxi;
    int mini;
    bool isBST;
    int longestsize;
};

info solve(Node* root){
    if(root == NULL){
        return {INT_MAX,INT_MIN,true,0};
    }
    if(root->left == NULL && root->right == NULL){
        return {root->data,root->data,true};
    }

    info left = solve(root->left);
    info right = solve(root->right);

    info ans;
    if(left.isBST && right.isBST && left.maxi < root->data && right.mini > root->data){
        ans.isBST = true;
        ans.maxi = max(right.maxi , root->data);
        ans.mini = min(left.mini, root->data);
        ans.longestsize = 1+right.longestsize+left.longestsize;
    }
    else{
        ans.isBST=false;
        ans.longestsize = max(left.longestsize,right.longestsize);
    }
    return ans;
}

int largestBst(Node *root)
{
    info ans = solve(root);
    return ans.longestsize;
}

/*Apporach two :
Instesd of using a different class we can just use array for each node and store the max min and curr size 
We will use a array/list ans :

• ans[0]=minimum value
• ans[1]=maximum value
• ans[2]=size of current largest BST

Algorithm:

1. If root==None:
return INT_MAX,INT_MIN,0
2. If (root.left==None and root.right==None):
             return root.data,root.data,1
3. Initialize ans=[0,0,0]
4. Check if the largest value of the left subtree is less than the value of the root node and the smallest value of the right subtree is greater than the value of the root node, if this holds true, update the ans accordingly and return ans.
5. If 4 is false, we will assign values as IMIN,IMAX, max(left[2],right[2] and return ans.


*/
vector<int> largestBSTBT(Node* root)
{
    // Base cases : When tree is empty or it has one child.
    if (root == NULL)
        return {INT_MAX, INT_MIN, 0};
    if (root->left == NULL && root->right == NULL)
        return {root->data, root->data, 1};
 
    // Recur for left subtree and right subtrees
    vector<int> left = largestBSTBT(root->left);
    vector<int> right = largestBSTBT(root->right);
 
    // Create a return variable and initialize its size.
    vector<int> ans(3, 0);
 
    // If whole tree rooted under current root is BST.
    if ((left[1] < root->data) && (right[0] > root->data))
    {
        ans[0] = min(left[0], min(right[0], root->data));
        ans[1] = max(right[1], max(left[1], root->data));
        // Update answer for tree rooted under current 'root'
        ans[2] = 1 + left[2] + right[2];
        return ans;
    }
 
    // If whole tree is not BST, return maximum of left and right subtrees
    ans[0] = INT_MIN;
    ans[1] = INT_MAX;
    ans[2] = max(left[2], right[2]);
 
    return ans;
}
 
int largestBSTBTutil(Node *root)
{
      return largestBSTBT(root)[2];
}
int main(){

return 0;
}