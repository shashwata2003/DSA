#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* Reverse Nodes in k-Group:
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes 
is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
 */

class ListNode{
    public:
    int data;
    int next;

    ListNode(int d){
        this->data = d;
        this->next = NULL;
    }
}

ListNode* reverseKGroup(ListNode* head, int k) {
        // Step 1: Check whether there are k elements in the list:
        ListNode* check = head;
        for (int i = 0; i < k; i++) {
            if(check == NULL) {
                return head; // If fewer than k nodes, return head as it is
            }
            check = check->next;
        }

        // Step 2: Reverse the first k elements:
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        int count = 0;
        
        while (curr != NULL && count < k) {
            next = curr->next;  // Store next node
            curr->next = prev;  // Reverse current node's pointer
            prev = curr;        // Move prev and curr one step forward
            curr = next;
            count++;
        }
        
        // Step 3: Recursively call the function for the rest of the list:
        if(next != NULL) {
            head->next = reverseKGroup(next, k);
        }
        
        return prev; // Return the new head of the reversed segment
}

int main(){

return 0;
}