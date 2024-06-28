#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* Merge Two BST:

You are given two binary search trees of integers having ‘N’ and ‘M’ nodes. 
Return an array that contains elements of both BST in sorted order.

Sample Input 1:
2 1 3 -1 -1 -1 -1
4 -1 -1
Sample Output 1:
1 2 3 4 

Sol:
Apporach 1:
Steps:
1. First convert Both the bsts to an inorder array which are sorted in nature
2. now merge the 2 sorted arrays
3. Now convert the inorder sorted array to a BST
Ts: O(n+m)
SP: O(n+m)

Apporach 2:
To optimize the solution we can remove the use of extra space. and use the tree as a flattened linked lists
Steps:
1. Convert both the trees to a sorted linked which is flatten
2. merge two sorted linked lists
3. convert the linked list to a balanced BST

TS:
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


//Apporach 1:

void inorderarray(Node* root , vector<int> &arr){
    if(root == NULL){
        return ;
    }
    inorderarray(root->left,arr);
    arr.push_back(root->data);
    inorderarray(root->right,arr);
}

vector<int> mergearray(vector<int> arr1, vector<int> arr2){
    int i = 0;
    int j = 0;
    int k = 0;
    int size = arr1.size() + arr2.size();
    vector<int> ans(size);
    while (i<arr1.size() && j<arr2.size())
    {
        if(arr1[i]<arr2[j]){
            ans[k++] = arr1[i];
            i++;
        }else{
            ans[k++] = arr2[j];
            j++;
        }
    }
    while (i<arr1.size())
    {
        ans[k++] = arr1[i];
        i++;
    }
     while (j<arr2.size())
    {
        ans[k++] = arr2[j];
        j++;
    }
    return ans;
}

Node* inordertobst(vector<int> &arr,int s, int e){
    if(s>e){
        return NULL;
    }
    int mid = (s+e)/2;
    Node* root = new Node(arr[mid]);
    root->left = inordertobst(arr,s,mid-1);
    root->right = inordertobst(arr,mid+1,e);
    return root;
}
Node* mergeBST(Node* root1, Node* root2){
    vector<int> arr1,arr2;
    inorderarray(root1,arr1);
    inorderarray(root2,arr2);

    vector<int> ans = mergearray(arr1,arr2);
    int s = 0, e = ans.size()-1;
    Node* root = inordertobst(ans,s,e);
    printBST(root);
    return root;
}

// Apporach 2:
// Function to convert bst to
// a doubly linked list
void bstTodll(Node* root, Node*& head)
{
    // if root is NULL
    if (!root)
        return;
 
    // Convert right subtree recursively
    bstTodll(root->right, head);
 
    // Update root
    root->right = head;
 
    // if head is not NULL
    if (head) {
 
        // Update left of the head
        head->left = root;
    }
 
    // Update head
    head = root;
 
    // Convert left subtree recursively
    bstTodll(root->left, head);
}
 
// Function to merge two sorted linked list
Node* mergeLinkedList(Node* head1, Node* head2)
{
 
    /*Create head and tail for result list*/
    Node* head = NULL;
    Node* tail = NULL;
 
    while (head1 && head2) {
 
        if (head1->data < head2->data) {
 
            if (!head)
                head = head1;
            else {
 
                tail->right = head1;
                head1->left = tail;
            }
 
            tail = head1;
            head1 = head1->right;
        }
 
        else {
 
            if (!head)
                head = head2;
            else {
                tail->right = head2;
                head2->left = tail;
            }
 
            tail = head2;
            head2 = head2->right;
        }
    }
 
    while (head1) {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }
 
    while (head2) {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }
 
    // Return the created DLL
    return head;
}
 
// function to convert list to bst
Node* sortedListToBST(Node*& head, int n)
{
    // if no element is left or head is null
    if (n <= 0 || !head)
        return NULL;
 
    // Create left part from the list recursively
    Node* left = sortedListToBST(head, n / 2);
 
    Node* root = head;
    root->left = left;
    head = head->right;
 
    // Create right part from the list recursively
    root->right = sortedListToBST(head, n - (n / 2) - 1);
 
    // Return the root of BST
    return root;
}
 
// This function merges two balanced BSTs
Node* mergeTrees(Node* root1, Node* root2, int m, int n)
{
    // Convert BSTs into sorted Doubly Linked Lists
 
    Node* head1 = NULL;
    bstTodll(root1, head1);
    head1->left = NULL;
 
    Node* head2 = NULL;
    bstTodll(root2, head2);
    head2->left = NULL;
 
    // Merge the two sorted lists into one
    Node* head = mergeLinkedList(head1, head2);
 
    // Construct a tree from the merged lists
    return sortedListToBST(head, m + n);
}

void printBST(Node* root){
    if(root == NULL){
        return ;
    }
    printBST(root->left);
    cout << root->data << " ";
    printBST(root->right);
}


int main(){
    Node* root1 = NULL;
    Node* root2 = NULL;
    root1 = buildBSTtree(root1);
    root2 = buildBSTtree(root2);
    Node* ans = mergeBST(root1,root2);
return 0;
}