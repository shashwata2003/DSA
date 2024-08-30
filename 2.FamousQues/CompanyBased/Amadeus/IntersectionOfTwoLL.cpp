#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Problem statement
You are given two Singly Linked Lists of integers, which may have an intersection point.

Your task is to return the first intersection node. If there is no intersection, return NULL.



Example:-
The Linked Lists, where a1, a2, c1, c2, c3 is the first linked list and b1, b2, b3, c1, c2, c3 is the second 
linked list, merging at node c1.

Sample Input 1 :
4 1 -1
5 6 -1
8 -1
Sample Output 1 :
8
Explanation For Sample Input 1:
As shown in the diagram, the node with data is 8, at which merging starts

Sample Input 2 :
1 9 1 -1
3 -1
2 -1
Sample Output 2 :
2
Constraints :
-10^9 <= data <= 10^9 and data != -1
 The length of both the linked list is positive.
 Time Limit: 1 sec
 */

/*
Steps:
1. find the length of the two LL
2. now find the the difference and the move the pointer of larger LL to the d step 
such that both of pointers are at the same level
3. now find the common intersection

TE: O(n+m)
SP: O(1)
*/

int getlength(Node* head){
    Node* curr = head;
    int cnt = 0;
    while(head){
        cnt++;
        curr = curr->next;
    }
    return cnt;
}

Node* findinter(Node* first, Node* second, int d){
    Node* curr1 = first;
    Node* curr2 = second;

    for (int i = 0; i < d; i++)
    {
        if(curr1 == NULL){
            return NULL;
        }
        curr1 = curr1->next;
    }

    while(curr1 && curr2){
        if(curr1 == curr2){
            return curr1;
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    return NULL;
}

Node* findIntersection(Node *firstHead, Node *secondHead)
{
    int n1 = getlength(firstHead);
    int n2 = getlength(secondHead);

    if(n1 > n2){
        int d = n1-n2;
        return findinter(firstHead,secondHead,d);
    }
    else{
        int d = n2-n1;
        return findinter(secondHead,firstHead,d);
    }
}

int main(){

return 0;
}