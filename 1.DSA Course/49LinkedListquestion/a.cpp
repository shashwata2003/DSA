#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  
Sort 0's 1's and 2's:
Given a linked list of 'N' nodes, where each node has an integer value that can be 0, 1, or 2. 
You need to sort the linked list in non-decreasing order and the return the head of the sorted list.
Input1:
7
1 0 2 1 0 2 1
Sample Output 1:
0 0 1 1 1 2 2
Solution:
Apporach1:
Treaverse the List and count the no. 0's 1's and 2's in the list and print the list accordingly 
Time Complexity: O(n)
Space Complexity: O(1)
Apporach 2:(in place)
create three linked for each 0, 1 and 2 and merge all three of them together.as the data replacement is not allowed
so whenever 0 arraives we will add that to the 0 linked list contnue it till the end. we will also keep a dummy node
at the beginning which will help us to merge the list.
Time complixity = O(n)
Space Complexity: O(1);
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

Node* sort012(Node* &head){
    Node* temp = head;
    int count0 = 0,count1 = 0, count2 = 0;
    while (temp != NULL)
    {
        if(temp->data == 0){
            count0++;
        }
        else if(temp->data == 2){
            count2++;
        }
        else if(temp->data == 1){
            count1++;
        }
        temp = temp->next;
    }
    temp = head;
    while (temp != NULL)
    {
        if(count0 != 0){
            temp->data = 0;
            count0 --;
        }
        else if(count1 != 0){
            temp->data = 1;
            count1 --;
        }
        else if(count2 != 0){
            temp->data = 2;
            count2 --;
        }
        temp = temp->next;
    }
    
    return head;
    
}
Node* sort123apporach2(Node* &head) {
    if (!head || !head->next) // Handling edge cases where the list is empty or has only one element
        return head;

    Node* zerohead = new Node(-1);
    Node* zerotail = zerohead;
    Node* onehead = new Node(-1);
    Node* onetail = onehead;
    Node* twohead = new Node(-1);
    Node* twotail = twohead;
    Node* curr = head;

    while (curr != nullptr) {
        int val = curr->data;
        if (val == 0) {
            zerotail->next = curr;
            zerotail = curr;
        } else if (val == 1) {
            onetail->next = curr;
            onetail = curr;
        } else if (val == 2) {
            twotail->next = curr;
            twotail = curr;
        }
        curr = curr->next; // Move to the next node
    }

    // Merge three lists
    zerotail->next = onehead->next;
    onetail->next = twohead->next;
    twotail->next = nullptr;

    // Update head to point to the sorted list
    head = zerohead->next;

    // Free memory
    delete zerohead;
    delete onehead;
    delete twohead;

    return head;
}


int main(){
    Node *node1 = new Node(2);
    Node *head = node1;
    Node *tail = node1;
    insertLL(head, 1);
    insertLL(head, 2);
    insertLL(head, 0);
    insertLL(head, 1);
    insertLL(head, 0);
    insertLL(head, 2);
    printLL(head);
    // Node* ans = sort012(head);
    Node* ans = sort123apporach2(head);
    cout<<endl;
    printLL(ans);
return 0;
}