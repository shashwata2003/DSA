#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* Detect and remove loop from the linked list:
Given a linked list, the task is to check if there is a loop present in it and remove it.

Apporach 1:
Using Hashing set: add the element to the set if that element is already in the set then point to null else
move to the next element.

Apporach 2:
Using Floysc cycle detection algo:
removeloop step:
1. find the no. of nodes in the loop and store in k using ptr1 and ptr2.
2. now move ptr1 to the head and ptr 2 to kth place form the head
3. now find the start  of the loop by moving both pinter by one step and when ptr1 = ptr2 hence we reached the
start of the loop
4. now find the last elemnt of the loop and point that to the NULL
*/

struct Node {
    int data;
    Node* next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void removeloop(Node* loopnode, Node* head){
    int k = 0;// no. of element is the loop;
    Node* ptr1 = loopnode;
    Node* ptr2 = loopnode;
    //count the no. of nodes in the loop
    while (ptr1->next != ptr2)
    {
        ptr1 = ptr1->next;
        k++;
    }
    //Move the ptr1 to the head
    ptr1 = head;
    
    // move the ptr2 to the kth place:
    ptr2 = head;
    for (int i = 0; i < k; i++)
    {
        ptr2 = ptr2->next;
    }

    //place the ptr1 to the start of the loop:
    while (ptr1 != ptr2){
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    //finding the last node of the loop and stored in ptr2:
    while (ptr2->next != ptr1)
    {
        ptr2 = ptr2->next;
    }
    
    ptr2 ->next == NULL; // Pointing the last element on the loop to NULL hence removing the loop:
}

void detectandremoveloop(Node* head){
    Node* slow = head;
    Node* fast = head;
    while (slow!=fast && slow && fast){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            removeloop(slow,head);
            return;
        }
    }
}

int main(){

return 0;
}