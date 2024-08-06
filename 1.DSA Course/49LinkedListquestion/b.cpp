#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 148. Sort List:
Given the head of a linked list, return the list after sorting it in ascending order.
Input: head = [4,2,1,3]
Output: [1,2,3,4]
Solution:
Appoarch 1:
create a array and store the data of the linked list and then use merge sort to sort the array and then update the
linked list . hence the linked list is sorted.
Time Complexity: O(nlogn)
Space Complexity: O(n)

Apporach 2:
Apply merge sort on the linked list:
Algo:
1. check if the head is null or head is only node if so then retunr head
2. find the middle node using fast and slow pointer (use the first moddle of the linked list)
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

Node *findmiddle(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node *merge2sorted(Node *head1, Node *head2)
{
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }

    Node *ans = NULL;
    if (head1->data <= head2->data)
    {
        ans = head1;
        ans->next = merge2sorted(head1->next, head2);
    }
    else
    {
        ans = head2;
        ans->next = merge2sorted(head1, head2->next);
    }
    return ans;
}

Node *sortLinkList(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *middle = findmiddle(head);
    Node *lefthead = head;
    Node *righthead = middle->next;
    middle->next = NULL;
    lefthead = sortLinkList(lefthead);
    righthead = sortLinkList(righthead);
    return merge2sorted(lefthead, righthead);
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