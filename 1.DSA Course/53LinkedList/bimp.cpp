#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  
 Flatten A Linked List:
 You are given a linked list containing 'n' 'head' 
 nodes, where every node in the linked list contains two pointers:
(1) ‘next’ which points to the next node in the list
(2) ‘child’ pointer to a linked list where the current node is the head.
Each of these child linked lists is in sorted order and connected by 'child' pointer.
Your task is to flatten this linked such that all nodes appear in a single layer or level in a 'sorted order'.

Sample Input 1 :
4
3
1 2 3
3
8 10 15
2
18 22
1
29
Sample Output 1 :
1 2 3 8 10 15 18 22 29

Example 2:
    /* Let us create the following linked list
        5 -> 10 -> 19 -> 28
        |    |     |     |
        V    V     V     V
        7    20    22    35
        |          |     |
        V          V     V
        8          50    40
        |                |
        V                V
        30               45

Output:
5 7 8 10 19 20 20 22 30 35 40 45 50 

Solution:
The idea is to use the Merge() process of merge sort for linked lists. 
Use merge() to merge lists one by one, recursively merge() the current list with the already flattened list. 
Steps:
Recursively call to merge the current linked list with the next linked list
If the current linked list is empty or there is no next linked list then return the current linked list (Base Case)
Start merging the linked lists, starting from the last linked list
After merging the current linked list with the next linked list, return the head node of the current linked list
*/
Node* merge(Node* a,Node* b){

    if (a == NULL)
        return b;

    if (b == NULL)
        return a;

    Node* result;
 
    if (a->data < b->data) {
        result = a;
        result->child = merge(a->child, b);
    }
 
    else {
        result = b;
        result->child = merge(a, b->child);
    }
    result->next = NULL;
    return result;
}


Node* flattenLinkedList(Node* head) 
{
	if(head == NULL || head->next == NULL){
		return head;
	}
	head->next = flattenLinkedList(head->next);
	head = merge(head,head->next);
	return head;
}

int main(){

return 0;
}