#include <iostream>
using namespace std;

/* 
 Search In BST
Given a BST and a Node . Find the Node in the BST, if present return true else return false.
 */

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int s) {
        this->data = s;
        this->left = NULL;
        this->right = NULL;
    }
};



Node* insertintree(Node* root, int data) {
    if (root == NULL) {
        root = new Node(data);
        return root;
    }
    if (root->data > data) {
        root->left = insertintree(root->left, data);
    } else {
        root->right = insertintree(root->right, data);
    }
    return root;
}

Node* buildtree(Node* root) {
    int data;
    cout << "Enter elements to insert into BST (-1 to end): ";
    cin >> data;
    while (data != -1) {
        root = insertintree(root, data);
        cin >> data;
    }
    return root;
}

//using recursion:
bool searchinBST(Node* root, int x) {
    if (root == NULL) {
        return false;
    }
    if (root->data == x) {
        return true;
    }
    // when the data is smaller than the root.
    if (root->data > x) {
        return searchinBST(root->left, x);
    } else {
        return searchinBST(root->right, x);
    }
}

// using iterative:
bool searchinBSTusingiteration(Node* root, int x){
    // storing the data in temp node and traversing using it.
    Node* temp = root;
     while (temp != NULL)
     {
        if(temp->data == x){
            return true;
        }
        if(temp->data > x){
            temp = temp->left;
        }else{
            temp = temp->right;
        }
     }
     return false;
}

int main() {
    Node* root = NULL;
    root = buildtree(root);
    int searchValue;
    cout << "Enter value to search in BST: ";
    cin >> searchValue;
    if (searchinBSTusingiteration(root, searchValue)) {
        cout << "Value " << searchValue << " found in BST." << endl;
    } else {
        cout << "Value " << searchValue << " not found in BST." << endl;
    }
    return 0;
}
