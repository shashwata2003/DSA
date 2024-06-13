#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*
Add two numbers represented by linked lists
Given two decimal numbers, num1 and num2, represented by linked lists of size n and m respectively.
The task is to return a linked list that represents the sum of these two numbers.
For example, the number 190 will be represented by the linked list, 1->9->0->null,
similarly 25 by 2->5->null. Sum of these two numbers is 190 + 25 = 215, which will be
represented by 2->1->5->null. You are required to return the head of the linked list 2->1->5->null.
Note: There can be leading zeros in the input lists, but there should not be any leading zeros in the output list.
Example 1:
Input:
n = 2
num1 = 45 (4->5->null)
m = 3
num2 = 345 (3->4->5->null)
Output:
3->9->0->null

Example 2:
Input:
n = 4
num1 = 0063 (0->0->6->3->null)
m = 2
num2 = 07 (0->7->null)
Output:
7->0->null

Solution:
We are given two LINked List we will first reverse both the list and start add each node from the left side
with a carry variable. after we get the answer we will reverse the final ans linked list.
Time Complexity: O(n+m)
Space complexity: O(max(m,n))
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

Node* ReverseList(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;
    Node* temp = head;
    while (curr != NULL )
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
    
}

/*
Steps to find the sum:
1. carry = 0
2. find sum
3. find digit = sum%10
4. create a node for the digit 
5. find carry = sum/10
*/



Node* add(Node* head1, Node* head2){
    int carry = 0;
    Node* anshead = NULL;
    Node* anstail = NULL;
    
    while (head1 != NULL || head2 != NULL || carry != 0) {
        int val1 = (head1 != NULL) ? head1->data : 0;
        int val2 = (head2 != NULL) ? head2->data : 0;
        
        int sum = carry + val1 + val2;
        int digit = sum % 10;
        carry = sum / 10;
        
        if (anshead == NULL) {
            anshead = new Node(digit);
            anstail = anshead;
        } else {
            anstail->next = new Node(digit);
            anstail = anstail->next;
        }
        
        if (head1 != NULL) head1 = head1->next;
        if (head2 != NULL) head2 = head2->next;
    }
    
    return anshead;
}


Node* addtwolist(Node* head1, Node* head2){
    head1 = ReverseList(head1); // Correct function name: ReverseList
    head2 = ReverseList(head2); // Correct function name: ReverseList

    Node* ans = add(head1, head2);

    ans = ReverseList(ans); // Correct function name: ReverseList
    return ans;
}
int main()
{
    Node *head1 = new Node(5);
    Node *tail1 = head1;
    insertLL(head1, 4);
    Node *head2 = new Node(5);
    Node *tail2 = head2;
    insertLL(head2, 4);
    insertLL(head2, 3);
    printLL(head1);
    cout << endl;
    printLL(head2);
    Node *ans = addtwolist(head1, head2);
    cout<<endl;
    cout<<head1->data<<endl;
    printLL(ans);
    return 0;
}