#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Merge K sorted arrays:
we are given K sorted arrays, we need to merge all of them in a single sorted arrays:

Solution:
Appoarch 1:
steps:
1. we need to create a ans vector
2. add all the array to the ans vector
3. sort the ans and return.

TS: O(n*klog nk)
SP:

Apporach 2:
Using min heap
Steps:
1. take all the first elements of the k arrays and add it in the min heap
2. take the top of the heap and add it to the ans vector and insert the next element of that arr in the heap if present
3. do this till heap.size > 0

Now to add a new element we need to keep a track form with array we are push which no. so we will use a custome datatype.
class node{
int data;
int i // rows
int j // columes}

the input for the k rows are given in 2d matrix format hence the use of rows and cols..

TS:O(N*k(log k))
SP: O(n*K)
*/

class Node {
public:
    int data;
    int row;
    int col;
    Node(int d, int i, int j) {
        this->data = d;
        this->row = i;
        this->col = j;
    }
};

class compare {
public:
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};

vector<int> mergeksorted(vector<vector<int>>& karrays, int k) {
    vector<int> ans;
    priority_queue<Node*, vector<Node*>, compare> minheap;

    // Adding all the first elements of k arrays
    for (int i = 0; i < k; i++) {
        if (!karrays[i].empty()) {
            Node* temp = new Node(karrays[i][0], i, 0);
            minheap.push(temp);
        }
    }

    while (!minheap.empty()) {
        Node* tmp = minheap.top();
        minheap.pop();
        ans.push_back(tmp->data);

        if (tmp->col + 1 < karrays[tmp->row].size()) {
            Node* next = new Node(karrays[tmp->row][tmp->col + 1], tmp->row, tmp->col + 1);
            minheap.push(next);
        }

        delete tmp; // Free the memory allocated for the node
    }

    return ans;
}

int main() {
    vector<vector<int>> a = {{1, 2, 3, 6, 7}, {4, 5, 8, 9, 10}};
    int k = a.size();
    vector<int> ans = mergeksorted(a, k);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}