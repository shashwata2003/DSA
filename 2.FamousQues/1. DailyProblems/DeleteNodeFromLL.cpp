#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
You are given an array of integers nums and the head of a linked list. Return the head of the modified linked list after removing all nodes from the linked list that have a value that exists in nums.

 

Example 1:

Input: nums = [1,2,3], head = [1,2,3,4,5]

Output: [4,5]
 */
/*
Here we need to handle:
Of the node is the root
if it is in the between 
and if its is the tail.
*/

/*
Dummy node is a new node before head which is 0;
we do this such that if the head is one to be deleted we will not face any issue 
TS: o(n)
*/

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode dummy(0, head); // Use a dummy node to simplify edge case handling
        unordered_set<int> s(nums.begin(), nums.end()); // Initialize set from vector
        
        ListNode* p = &dummy;
        while (p->next != nullptr) {
            if (s.count(p->next->val)) { //starting from next as the fist is the dummy
                p->next = p->next->next; // Skip the node if its value is in the set
            } else {
                p = p->next; // Move to the next node if no deletion
            }
        }
        
        return dummy.next; // Return the modified list starting from the real head
    }
};



int main(){

return 0;
}