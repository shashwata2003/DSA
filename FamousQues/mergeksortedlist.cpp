#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  
Merge k Sorted Lists:

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.

Example 1:
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

Sol:
Appoarach 1:
Using Min heap , we will push all the first node in the min heap which will sort the node and the min will at 
the top of the LL.
Sp: extra space for heap

Apporach 2:

*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

 struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

ListNode* mergeKLists(vector<ListNode*>& lists) {
    int k = lists.size();
    if(k == 0){
        return NULL;
    }
    priority_queue<ListNode*,vector<ListNode*>,compare> minheap;
    ListNode* head = NULL;
    ListNode* tail = NULL;
    //adding the first element of all the linked list in the queue;
    for (int i = 0; i < k; i++)
    {
        if(lists[i] != NULL){
            minheap.push(lists[i]);
        }
    }
    
    while (!minheap.empty())
    {
        ListNode* top = minheap.top();
        minheap.pop();
        //add the next element in the heap:
        if(top->next != NULL){
            minheap.push(top->next);
        }
        //Now create the LINKED LIST:
        if(head == NULL){
            //list is empty:
            head = tail = top;
        }
        else{
            tail->next = top;
            tail = top;
        }
    }
    return head;
}
int main(){

return 0;
}