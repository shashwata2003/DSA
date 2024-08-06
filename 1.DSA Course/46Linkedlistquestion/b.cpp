#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*
Circularly Linked
You are given the head of a linked list containing integers, You need to find out whether the given linked
list is circular or not.
Note :
1. A linked list is said to be circular if it has no node having its next pointer equal to NULL and all the nodes
form a circle i.e. the next pointer of last node points to the first node.
2. An empty linked will also be considered as circular.
3. All the integers in the linked list are unique.
4. In the input, the next pointer of a node with i’th integer is linked to the node with data (i+1)’th integer
(If (i+1)’th node exists). If there is no such (i+1)’th integer then the next pointer of such node is set to NULL.
Sample Input 1:
1
5
1 2 3 4 1
Sample Output 1 :
True

Sample Input 2 :
1
7
1 2 3 4 5 6 7
Sample Output 2 :
False
Solution:
Apporach 1:
Here we are going to terverse the entire list and at the end we will check weather the temp == head then return 
true else return false.
also we need to take care of the base conditions like:
if LL is null then return true 
if only one node is present then check weather it is pointing if at head then true else false

Time Complexity :O(n)
Space Complexity: O(1);

Apprach 2:
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

bool isCircular(Node* &head){
    if(head == NULL){
        return true;
    }
    if(head->next == head){
        return true;
    }
    Node* temp = head->next;
    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }
    if(temp == NULL){
        return false;
    }
    if(temp == head){
        return true;
    }
    
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    insertLL(head, 11);
    insertLL(head, 12);
    insertLL(head, 13);
    insertLL(head, 14);
    cout <<isCircular(head)<<endl;


    return 0;
}