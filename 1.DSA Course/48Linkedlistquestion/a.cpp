#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*
Remove Duplicates from Sorted List:
You are given a linked list of N nodes. Your task is to remove the duplicate nodes from the linked 
list such that every element in the linked list occurs only once i.e. in case an element occurs more than 
once, only keep its first occurrence in the list.

For example :
Assuming the linked list is 3 -> 2 -> 3 -> 4 -> 2 -> 3 -> NULL.
Number ‘2’ and ‘3’ occurs more than once. Hence we remove the duplicates and keep only their first 
occurrence. So, our list becomes : 3 -> 2 -> 4 -> NULL.
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



void removeduplicates(Node* &head){
    if(head==NULL){
        return ;
    }
    Node* temp= head;
    while(temp != NULL && temp->next != NULL){
        if(temp->data == temp->next->data){
            temp->next = temp->next->next;
            //also we have to delete the node:
            //delete(temp->next);
        }else{
            temp = temp->next;
        }
    }
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    insertLL(head, 10);
    insertLL(head, 12);
    insertLL(head, 12);
    insertLL(head, 14);
    printLL(head);
    removeduplicates(head);
    cout<<endl;
    printLL(head);
    return 0;
}