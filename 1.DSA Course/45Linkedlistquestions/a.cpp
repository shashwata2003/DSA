#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Given a singly linked list of integers. Your task is to return the head of the reversed linked list.

For example:
The given linked list is 1 -> 2 -> 3 -> 4-> NULL. Then the reverse linked list is 4 -> 3 -> 2 -> 1 -> NULL and the head of the reversed linked list will be 4.
Follow Up :
Can you solve this problem in O(N) time and O(1) space complexity?
Sample Input 1 :
1
1 2 3 4 5 6 -1
Sample Output 1 :
6 5 4 3 2 1 -1

SOlution:
Appoarch 1:
Here we will simply change the direction of each node pointing forward to pointing backward eg:
1->2->3->4->null now it will be null<-1<-2<-3<-4
to do so we will use 2 pointer method: first will current = head and the other will be the prev = null and one more
called forward = current->next. Hence we have will run a loop in wich we will
forward = current->next;
current->next = prev;
prev = current;
current = forward;
and in the final iteration the prev will be my new head hence return prev
TIME COMPLEXTY: O(n);
Space complexity: O(1);

Appoarch 2: 
Using recursion:
Base case: if(current == NUL){
    head = prev;
    return head;
}
 */

class Node{
    public:
    int data;
    Node* next;

    Node(int d){
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

void insertLL(Node* &head,int d){
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

Node* reversrLinkedList(Node* head){
    //empty LL:
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* prev = NULL;
    Node* current = head;
    Node* forward = NULL;
    while (current!=NULL)
    {
        forward = current->next;
        current->next = prev;
        prev = current;
        current = forward;
    }
    return prev;
}

Node* reverseLLusingrecursion(Node* &head, Node* current, Node* prev){
    if(current==NULL){
        head = prev;
        return head;
    }
    Node* forward = current -> next;
    //sending forward as the current node and the current as the previous node.
    reverseLLusingrecursion(head,forward,current);
    current->next = prev;
}

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    insertLL(head,11);
    insertLL(head,12);
    insertLL(head,13);
    printLL(head);
    cout<<endl;
    cout<<"After"<<endl;
    //head = reversrLinkedList(head);
    reverseLLusingrecursion(head,head,NULL);
    printLL(head);

return 0;
}