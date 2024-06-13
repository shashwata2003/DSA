#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*
Reverse List In K Groups:
You are given a linked list of 'n' nodes and an integer 'k', where 'k' is less than or equal to 'n'.
Your task is to reverse the order of each group of 'k' consecutive nodes, if 'n' is not divisible by 'k',
then the last group of nodes should remain unchanged.
For example, if the linked list is 1->2->3->4->5, and 'k' is 3, we have to reverse the first three elements,
and leave the last two elements unchanged. Thus, the final linked list being 3->2->1->4->5.
Implement a function that performs this reversal, and returns the head of the modified linked list.

Example:
Input: 'list' = [1, 2, 3, 4], 'k' = 2
Output: 2 1 4 3
Explanation:
We have to reverse the given list 'k' at a time, which is 2 in this case. So we reverse the first 2
elements then the next 2 elements, giving us 2->1->4->3.

Solution:
here we are apply recursive apporach. Here we will solve for the first k elements rest will be taken care by the
recursion.
now to reverse the k elements we will use the iterative method that we used earlier and apply recursion for the rest

Base condition:
if(head == null){
    return NULL
}

Time Complexity : O(n)
Space complexity: O(n)
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

Node *Kreverse(Node *head, int k)
{
    //check if there are at least k nodes remaining in the list to reverse.If during this traversal, 
    //cursor becomes nullptr, it indicates that there are less than k nodes remaining in the list.
    //this is used for cases like Input: head = [1,2,3,4,5], k = 3 Output: [3,2,1,4,5] now if you want to reverse
    // 4 and 5 also then we dont need this extra code.
    ListNode *cursor = head;
    for (int i = 0; i < k; i++)
    {
        if (cursor == NULL)
        {
            return head;
        }
        cursor = cursor->next;
    }
    // ___________
    if (head == NULL)
    {
        return NULL;
    }
    Node *next = NULL;
    Node *current = head;
    Node *prev = NULL;
    int count = 0;
    while (current != NULL && count < k)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
    if (next != NULL)
    {
        head->next = Kreverse(next, k);
    }
    return prev;
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    insertLL(head, 11);
    insertLL(head, 12);
    insertLL(head, 13);
    insertLL(head, 14);
    printLL(head);
    cout << endl;
    head = Kreverse(head, 2);
    printLL(head);
    return 0;
}