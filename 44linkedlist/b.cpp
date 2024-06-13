#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Double Linked List:

 */
class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    //constructor:
    Node(int d){
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};

void InsertatHead(Node*& head, int d){
    Node* temp = new Node(d);
    temp->next = head;
    if (head != NULL)
        head->prev = temp;
    head = temp;
}

void InsertatTail(Node*& tail, int d){
    Node* temp = new Node(d);
    temp->prev = tail;
    if (tail != NULL)
        tail->next = temp;
    tail = temp;
}

void InsertatPos(Node* head, Node* tail, int pos, int d){
    if (pos == 1)
    {
        InsertatHead(head,d);
        return;
    }
    Node* temp = head;
    int cnt = 1;
    while (cnt<pos-1)
    {
        temp = temp->next;
        cnt++;
    }
    //when pos == tail
    if(temp->next == NULL){
        InsertatTail(tail,d);
        return;
    }
    // insertating at the pos:
    Node* NodetoIn = new Node(d);
    NodetoIn->next = temp ->next;
    NodetoIn->prev = temp;
    (temp->next)->prev = NodetoIn;
    temp->next = NodetoIn; 
    
}

void PrintDL(Node* head){
    Node* temp = head;
    while (temp != NULL)  
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    
}

int main(){
    Node * node1 = new Node(10);
    Node * head = NULL;
    Node* tail = NULL;
    InsertatHead(head,12);
    InsertatHead(head,14);
    InsertatTail(tail,15);
    InsertatPos(head,tail,3,4);
    PrintDL(head);

return 0;
}