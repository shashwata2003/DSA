#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  
Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.

The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead to some parts being null.

The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal to parts occurring later.

Return an array of the k parts.

Input: head = [1,2,3], k = 5
Output: [[1],[2],[3],[],[]]
Explanation:
The first element output[0] has output[0].val = 1, output[0].next = null.
The last element output[4] is null, but its string representation as a ListNode is [].

Input: head = [1,2,3,4,5,6,7,8,9,10], k = 3
Output: [[1,2,3,4],[5,6,7],[8,9,10]]
Explanation:
The input has been split into consecutive parts with size difference at most 1, and earlier parts are a larger size than the later parts.
*/

/*
Find the length of the entire list
find the no. of extra nodes that we need to manage in other pairs in r
and find the size of each pair in n 
traverves the LL and store the head of each pair of the node
*/

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int size = 0;
        ListNode* temp = head;
        while(temp){
            size++;
            temp = temp->next;
        }
        int r = size%k;
        int n = size/k;
        vector<ListNode*> ans(k,NULL);
        ListNode* node = head;
        ListNode* prev = NULL;
        for (int i = 0; node && i < k; i++, r--) {
            // Store the current node as the start of the current part.
            ans[i] = node;
            // Traverse n + 1 nodes if there are remaining extra nodes (r > 0).
            // Otherwise, traverse only n nodes.
            for (int j = 0; j < n + (r > 0); j++) {
                prev = node;
                node = node->next;
            }
            // Disconnect the current part from the rest of the list by setting prev->next to nullptr.
            prev->next = nullptr;
        }
        return ans;
    }
};

int main(){

return 0;
}