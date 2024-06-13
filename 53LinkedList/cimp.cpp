#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*
 Flatten a Multilevel Doubly Linked List:
 You are given a doubly linked list, which contains nodes that have a next pointer, a previous pointer, and
 an additional child pointer. This child pointer may or may not point to a separate doubly linked list, also
 containing these special nodes. These child lists may have one or more children of their own, and so on, to
 produce a multilevel data structure as shown in the example below.
Given the head of the first level of the list, flatten the list so that all the nodes appear in a single-level,
doubly linked list. Let curr be a node with a child list. The nodes in the child list should appear after curr
 and before curr.next in the flattened list.
Return the head of the flattened list. The nodes in the list must have all of their child pointers set to
null.

Input: head = [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
Output: [1,2,3,7,8,11,12,9,10,4,5,6]
Explanation: The multilevel linked list in the input is shown.

Input: head = [1,2,null,3]
Output: [1,3,2]
Explanation: The multilevel linked list in the input is shown.


Solution:
step 1: move one step at a time from head until we find a child node for any of the node.
step 2 : When found a child node, follow the child node trail till u hit a null. after hitting null point the last
element of the child trail back to the main trail
step 3: Return to p and proceed until find next node with child.
Repeat until reach null
 */

Node *flatten(Node *head)
{
    if (head == nullptr)
        return head;
    Node *p = head;
    while (p != nullptr)
    {
        if (p->child == nullptr)
        {
            p = p->next;
            continue;
        }
        Node *temp = p->child;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = p->next;
        if (p->next != nullptr)
            p->next->prev = temp;
        p->next = p->child;
        p->child->prev = p;
        p->child = nullptr;
        p = p->next;
    }
    return head;
}

int main()
{

    return 0;
}