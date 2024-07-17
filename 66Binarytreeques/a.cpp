#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Construct a BT from Inorder/PreOrder traversal:
Given Two int arrays of inroder and preorder traversal val. we need to build a tree using both the array values.
and we need to print the post order(left right root) of the built tree.
eg: Inorder(Left root right):[ 1 6 8 7]
preorder(root left right): [1 6 7 8]
out: 8 7 6 1
SOl:
Check notes for it.

TS: o(n);

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

  int Findposition(int in[] ,int inorderStart , int inorderEnd , int element ,int  n){
        for(int i = inorderStart ; i<=inorderEnd ;i++){
            if(in[i]==element){
                return i ; 
            }
        }
        return -1 ;
    }

//This function will map the index of inorder array with its val. hence we dont have to find the position
// we can directly use a find function on the map;
// This is giving TLA In GFG so use the find pos function:
void createamap(map<int,int> &mp, int in[],int n){
    for (int i = 0; i < n; i++)
    {
        mp[in[i]] = i;
    }
    
}
Node* solve(int in[], int pre[],int n, int &preorderstart, int inorderstart, int inorderend,map<int,int> mp){
    // Base case:
    // 1. check weather we have traversed the entire pre array
    // 2. check weather the inorder start pointer as crossed the end pointer
    if(preorderstart > n || inorderstart>inorderend){
        return NULL;
    }
    // taking the first element of teh pre array as the root
    int elem = pre[preorderstart++];
    Node* temp = new Node(elem);
    // then finding the position of that root in the in order arr.
    // But Multiples calls of this fucntions increases the TS, hence we will use a map to map the index with the node
    // hence that we need to run only once and ts will be controlled
    //old : int pos = Findposition(elem,in,n);
    //new using a map.
    int pos = mp[elem];

    // recursivly calling the left and right subtree.
    // left will start form the start of the inorder till the pos -1 of the root elemeny in the in array
    temp->left = solve(in,pre,n,preorderstart,inorderstart,pos-1,mp);
    // the right will from pos+1 of in to inorder end.
    temp->right = solve(in,pre,n,preorderstart,pos+1,inorderend,mp);

    return temp;
}

Node* buildTree(int in[], int pre[],int n){
    int preorderstart = 0;
    int inorderstart = 0;
    int inorderend = n-1;
    map<int,int> mp;
    createamap(mp,in,n);
    Node* ans = solve(in, pre, n,preorderstart,inorderstart,inorderend,mp);
    return ans;
}

void printpostorder(Node* root){
    if(root == NULL){
        return ;
    }
    printpostorder(root->left);
    printpostorder(root->right);
    cout<<root->data<<" ";

}
int main(){
    Node* root = NULL;
    int n = 4;
    int in[n] = {1, 6, 8 ,7};
    int pre[n] = {1, 6, 7, 8};
    root = buildTree(in,pre,n);
    printpostorder(root);
return 0;
}