#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Add one to a number represented by LL
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

void insertattail(Node* &head, Node* &tail, int d){
    Node* temp = new Node(d);
    if(head == NULL){
        head = temp;
        tail = temp;
        return;
    }
    else{
        tail->next = temp;
        tail = temp;
    }
}

Node* reverse(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    Node* forward =NULL;
    while (curr!=NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

Node* add(Node* head, Node* one){
    int carry = 0;
    Node* anshead = NULL;
    Node* anstail = NULL;
    while(head != NULL || one != NULL || carry != 0){
        int val1 = (head != NULL) ? head->data : 0;
        int val2 = (one != NULL) ? one->data : 0;
        int sum = val1 + val2 + carry;
        int digit = sum % 10;
        carry = sum / 10;
        if (anshead == NULL) {
            anshead = new Node(digit);
            anstail = anshead;
        } else {
            anstail->next = new Node(digit);
            anstail = anstail->next;
        }
        if (head != NULL) head = head->next;
        if (one != NULL) one = one->next; // Advance the pointer for the second list
    }
    // If there's a remaining carry, add it as a new node
    if (carry > 0) {
        anstail->next = new Node(carry);
    }
    return anshead;
}


Node* addone(Node* head){
    head = reverse(head);
    Node* one = new Node(1);
    Node* ans = add(head,one);
    ans = reverse(ans);
    return ans;
}

int main()
{
    Node *head1 = new Node(5);
    Node *tail1 = head1;
    insertLL(head1, 4);
    printLL(head1);
    Node* ans  = addone(head1);
    printLL(ans);
    return 0;
}