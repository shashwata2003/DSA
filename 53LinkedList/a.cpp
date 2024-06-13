#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* Apply merge Sort in Linked List */
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

Node* findmiddle(Node* head){
    Node* fast = head->next;
    Node* slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
    
}

Node* merge2sortedlist(Node* head1, Node* head2){
    if(head1 == NULL){
        return head2;
    }
    if(head2 == NULL){
        return head1;
    }
    Node *ans = NULL;
    if (head1->data <= head2->data)
    {
        ans = head1;
        ans->next = merge2sortedlist(head1->next, head2);
    }
    else
    {
        ans = head2;
        ans->next = merge2sortedlist(head1, head2->next);
    }
    return ans;
}

Node* sortLinkList(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* middle = findmiddle(head);
    Node* lefthead = head;
    Node* righthead = middle->next;
    middle->next = NULL;
    lefthead = sortLinkList(lefthead); 
    righthead = sortLinkList(righthead); 
    return merge2sortedlist(lefthead,righthead);
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
    Node *ans = sortLinkList(head);
    cout << endl;
    printLL(ans);
    return 0;
}