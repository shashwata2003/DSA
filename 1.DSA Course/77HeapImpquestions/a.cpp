#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Smallest Range of K list:
We are given K sorted lists or array, we need to return the smallest possible range which includes alleast
one element form all the k lists.
eg:
a = {1,10,11}
b = {2,3,20}
c = {5, 6, 12}

Ans: [1,5]
return the ans like (5-1) +1 = 5

Solution:
Apporach 1: Brute force method:
1. First we will find all the possible ranges  O(n2*k2)
2. next find all the smallest possible ranges by comparing the differences

TS: O(n2 * k2)

Apporach 2:
Basic idea here will be to maintain a min and max value, to do so we will store the first element from each of the
k arrays, 
So we will find the min and the max of the k elements stored and store the difference and move the min point to the 
next element of that array as we can only update the min not the max as the arrays are sorted
This way will keep track smallest range 
eg : {1,10,11} {2,3,20} {5,6,12} first k elem will be {1,2,5} henc the min will be min : 1 max : 5
Hence we got our first range now we need to find the one with the min difference hence we will try to change
the min point which is currently point at 1 , take the next element from the array which is 10 hence the 
k array will we now {10,2,5} new min = 2 max = 10 difference = 8 > 4 (old for 1,5) now again move the min pointe
from 2 tp next element in the same array ie 3, hence the updated k array will be {10,3,5} min = 3 max = 10 diff
7. continu till u find the min range

This method ensures that the min and max have a range such that one element form each array is included, we just 
need to find the one with min difference

TS: O(n*k2)
SP: O(k)

Apporach 3: Using heaps:
In the above apporach we need to find the min and max and we can do that easily using a heap.
steps:
1. keep track of the min and max by creating the varible for the k element inserted in heap.
2. now create a min heap of size k 
3. create a ansmin and ansmax for the final ans. using that find the current range
4. run a loop till the heap is empty
5. we can update the min using the top val of the heap
6. now check weather the current range is smaller than the previous one stored in ans if so update it
7. Now update max if there is another variable present in the arr.

TS: O(nk log k)
SP: O(k)
 */

class Node{
    // speacial data type to keep track of the row and the col we are currently processing
    public:
    int data;
    int row;
    int col;
    Node(int d, int r, int c){
        this->data = d;
        this->row = r;
        this->col = c;
    }
};

class compare{
    public:
    bool operator()(Node* a, Node* b){
        return a->data > b->data;
    }
};


int smallestrange(vector<vector<int>> arr, int n, int k){
    // init the min and max variable
    int mini = 99999, maxi = -11111;
    // init the min heap
    priority_queue<Node*, vector<Node*>, compare> minheap;

    // fill the min heap with the first k element in the arr;
    for (int i = 0; i < k; i++)
    {
        // ele is the first ele of theeach arr
        int ele = arr[i][0];
        mini = min(mini, ele);
        maxi = max(maxi , ele);
        minheap.push(new Node(ele, i, 0));
    }

    int ansstart = mini, ansend = maxi;

    while (!minheap.empty())
    {
        Node* temp = minheap.top();
        // update mini
        mini = temp->data;
        minheap.pop();

        // update the range
        if(maxi-mini < ansend - ansstart){
            ansstart = mini;
            ansend = maxi;
        }

        // updating maxi if there is a next element:
        if(temp->col + 1 < n){
            // row will be same but we will move to the next col.
            maxi = max(maxi, arr[temp->row][temp->col+1]);
            minheap.push(new Node(arr[temp->row][temp->col+1],temp->row, temp->col+1));
        }else{
            // the next element does not exist:
            break;
        }

        return (ansend-ansstart + 1);
    }
    
    
}

int main(){
    vector<vector<int>> arr = {{1,10,11},{2,3,20},{5, 6, 12}};
    int n = arr[0].size();
    int k = arr.size();
    cout<<smallestrange(arr,n,k);
return 0;
}