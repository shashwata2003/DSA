#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Merge K sorted Linked list:
Given K sorted Linked lists we need to merge all of them in to a single sorted linked list. Do it inplace
return the head of the merged Linked list.

Solution:
Apporach 1:Brute Force:
Here we can traverse all the LL and add it in a single vector,
2. then sort it 
3. merge all the linked list
4. Then replace the data of the merged ll with the data in the vector.

TS: O(n*k log n*k)

Apporach 2:
Here we Going to similar to merge k sorted arrays,
as we need to return a heap of a existing node so we will not create a ans array rather we will insert 
at the tail of any one of the given input linked lists.
TS: O(n*k log K)
Sp: O(k)
// Was not able to implement the same in the local env. hence not runned
 */

class Node{
    int data;
    Node* next;
    Node(int d){
        this->data = d;
        this->next = NULL;
    }
};

class compare{
    public:
    bool operator()(Node<int>* a, Node<int>* b){
        return a->data >b -> data;
    }
};

Node* mergesortedLL(vector<Node<int>*> Karray){
    int k = karray.size();
    // check if the input vector is empty.
    if(k == 0){
        return NULL;
    }
    priority_queue<Node<int>*, vector<Node<int>*, compare> minheap;
    // push all the first node of k LL in the min heap
    for (int i = 0; i < k; i++)
    {
        if(Karray[i]!=NULL){
            minheap.push(Karray[i]);
        }
    }

    Node* head = NULL;
    Node* tail = NULL;
    
    while (!minheap.empty())    
    {
        Node<int>* temp = minheap.top();
        minheap.pop();

        if(temp->next != NULL){
            //adding new element in the heap if teh next is empty
            maxheap.push(temp->next);
        }
        if(head == NULL){
            // if the LL is emty and inseting the first element
            head = tail = temp;
        }else{
            tail -> next = temp;
            tail = temp;
        }

    }
    return head;
    
    
}


int main(){

return 0;
}