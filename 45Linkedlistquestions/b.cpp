#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* Middle of the Linked List
Given the head of a singly linked list, return the middle node of the linked list.
If there are two middle nodes, return the second middle node.\
Input 1:
Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.

Input2:
Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.

Solution:
Approach1:
Find the length of the LL and find the middle element of the LL
if Length = even:
the mid+1
else:
print mid

approach 2:
here we will take two pointer fast and slow. The fast pointer will travers the list 2 nodes at once and the 
slow will traverse the list one at a time. so when the fast will be at the end(NULL) the slow will be at the mid.
hence we find the mid of the linked list.
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

int getLength(Node *&head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }

    return count;
}
// approach 1:
Node *findMid(Node *&head)
{
    int len = getLength(head);
    int mid = 0;
    if (len % 2)
    {
         mid = len / 2 + 1;
    }
    else
    {
         mid = len / 2;
    }
    Node* temp = head;
    int cnt = 0;
    while (cnt<mid)
    {
        temp=temp->next;
        cnt++;
    }
    return temp;
}

//approach 2:

Node* findMid2(Node* &head){
    if(head == NULL){
        return head;
    }
    if(head->next == NULL){
        return head;
    }
    Node* fast = head;
    Node* slow = head;
     while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
    
}

int main()
{
    Node *node1 = new Node(5);
    Node *head = node1;
    insertLL(head, 4);
    insertLL(head, 3);
    insertLL(head, 2);
    insertLL(head, 1);
    printLL(head);
    cout<<endl;
    //head = findMid(head);
    head = findMid2(head);
    printLL(head);
    return 0;
}