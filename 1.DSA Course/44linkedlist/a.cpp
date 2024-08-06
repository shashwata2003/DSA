#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*
Implementation of singly linked list

 */
class Node
{
public:
    int data;
    Node *next;
    // constructor:
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    // Destructor:
    ~Node()
    {
        cout << "Deleted node with value: " << this->data << endl;
        // No need to delete 'next', just let the system handle it.
    }
};
void InsertAtHead(Node *&head, int d)
{
    // adding at the beginning of the list
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void InsertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp; // Changing the old tail
    tail = tail->next; // moving the tail to new node
}
void InsertAtposition(Node *&tail, Node *&head, int p, int d)
{
    // if the position is 1 i.e inserting at head
    if (p == 1)
    {
        InsertAtHead(head, d);
        return;
    }
    // if the position is the tail, so we donot have the lenght of the LL so we will use the following condition
    Node *temp = head;
    int i = 1;
    while (i < p - 1)
    {
        temp = temp->next;
        i++;
    }

    if (temp->next == NULL)
    {
        InsertAtTail(tail, d);
        return;
    }
    Node *nodetoadd = new Node(d);
    nodetoadd->next = temp->next;
    temp->next = nodetoadd;
}

void Deleteatanypos(Node *&head, int p)
{
    if (head == NULL)
    {
        cout << "List is empty. Deletion is not possible." << endl;
        return;
    }

    if (p < 1)
    {
        cout << "Invalid position. Deletion is not possible." << endl;
        return;
    }

    if (p == 1)
    {
        // Deleting first position:
        Node *temp = head;
        head = temp->next;
        delete temp;
    }
    else
    {
        // Deleting every other position:
        Node *curr = head;
        Node *prev = NULL;
        int cnt = 1;
        while (curr != NULL && cnt < p)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        if (curr == NULL)
        {
            cout << "Position " << p << " is out of range. Deletion is not possible." << endl;
            return;
        }

        prev->next = curr->next;
        curr->next = NULL; // Setting the deleted node's next to NULL
        delete curr;
    }
}

void printLL(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Node *node1 = new Node(10);
    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl;
    // head pointer pointing at the head
    Node *head = node1;
    InsertAtHead(head, 12);
    InsertAtHead(head, 14);
    // inserting form the tail
    Node *tail = node1;
    InsertAtTail(tail, 16);
    InsertAtTail(tail, 18);
    // inserting in the middle
    InsertAtposition(tail, head, 1, 2);
    InsertAtposition(tail, head, 3, 8);
    InsertAtposition(tail, head, 8, 4);
    printLL(head);
    Deleteatanypos(head, 1);
    printLL(head);

    return 0;
}