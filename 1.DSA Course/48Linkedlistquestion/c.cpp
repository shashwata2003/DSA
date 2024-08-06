#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* Remove Duplicates from Sorted List II
Given the head of a sorted linked list, delete all nodes that have duplicate numbers,
 leaving only distinct numbers from the original list. Return the linked list sorted as well.
 Input: head = [1,1,1,2,3]
Output: [2,3]
  */

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

void printLL(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// Insert at the head
void insertLL(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void removeAllDuplicates(struct Node*& start) 
{ 
    // create a dummy node 
    // that acts like a fake 
    // head of list pointing 
    // to the original head 
    Node* dummy = new Node(-1); 
  
    // dummy node points 
    // to the original head 
    dummy->next = start; 
  
    // Node pointing to last 
    // node which has no duplicate. 
    Node* prev = dummy; 
  
    // Node used to traverse 
    // the linked list. 
    Node* current = start; 
  
    while (current != NULL) { 
        // Until the current and 
        // previous values are 
        // same, keep updating current 
        while (current->next != NULL && prev->next->data == current->next->data) 
            current = current->next; 
  
        // if current has unique value 
        // i.e current is not updated, 
        // Move the prev pointer to 
        // next node 
        if (prev->next == current) 
            prev = prev->next; 
  
        // when current is updated 
        // to the last duplicate 
        // value of that segment, 
        // make prev the next of current 
        else
            prev->next = current->next; 
  
        current = current->next; 
    } 
  
    // update original head to 
    // the next of dummy node 
    start = dummy->next; 
} 

int main()
{
    Node *node1 = new Node(3);
    Node *head = node1;
    Node *tail = node1;
    insertLL(head, 2);
    insertLL(head, 1);
    insertLL(head, 1);
    insertLL(head, 1);
    printLL(head);
    removeduplicates(head);
    cout << endl;
    printLL(head);
    return 0;
}
