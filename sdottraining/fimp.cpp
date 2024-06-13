#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
 */
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

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

void insertInLL(int d, Node *&tail)
{
    Node *temp = new Node(d);
    if (tail == NULL)
    {
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}
// Insert at the head
void insertLL(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

Node* mergeTwoLists(Node* l1, Node* l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    if (l1->data <= l2->data) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

Node* mergeKSortedLists(vector<Node*>& arr) {
    if (arr.empty()) return NULL;
    int n = arr.size();
    while (n > 1) {
        int k = (n + 1) / 2;
        for (int i = 0; i < n / 2; ++i) {
            arr[i] = mergeTwoLists(arr[i], arr[i + k]);
        }
        n = k;
    }
    return arr[0];
}

int main()
{
    Node *node1 = new Node(1);
    Node *head1 = node1;
    Node *tail1 = node1;
    insertInLL(4, tail1);
    insertInLL(5, tail1);
    Node *node2 = new Node(1);
    Node *head2 = node2;
    Node *tail2 = node2;
    insertInLL(3, tail2);
    insertInLL(4, tail2);
    Node *node3 = new Node(2);
    Node *head3 = node3;
    Node *tail3 = node3;
    insertInLL(6, tail3);
    vector<Node *> arr = {head1, head2, head3};
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     printLL(arr[i]);
    //     cout<<endl;
    // }

    Node *ans = mergeKSortedLists(arr);
    printLL(ans);
    cout<<3/2;
    return 0;
}