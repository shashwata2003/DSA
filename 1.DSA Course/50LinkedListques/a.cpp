#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* Palindrome Linked List:
Given the head of a singly linked list, return true if it is a palindrome
 or false otherwise. */
 bool isPalindrome(ListNode* head) {
        stack<int> st;
        ListNode* temp = head;
        while(temp!=NULL){
            st.push(temp->val);
            temp = temp -> next;
        }
        while(head!=NULL){
            if(head->val == st.top()){
                head = head->next;
                st.pop();
            }else{
                return false;
            }
        }
        return true;
    }
int main(){

return 0;
}