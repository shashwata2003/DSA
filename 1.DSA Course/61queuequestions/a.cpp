#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Queue Reversal
Given a Queue Q containing N elements. The task is to reverse the Queue.
 Your task is to complete the function rev(), that reverses the N elements of the queue.
 Input:
6
4 3 1 10 2 6
Output: 
6 2 10 1 3 4
Explanation: 
After reversing the given elements of the queue , the resultant queue will be 6 2 10 1 3 4.

Input:
4
4 3 2 1 
Output: 
1 2 3 4

Sol:
Apporach 1:
using a stack.
we know that using a stack we can reverse any list of elements
Hence we can add all the elements one by one to the queue and the replace the elements in the queue by poping each 
element on the stack
 space complexity: o(n) 
 time complexity o(n)

Apporach 2:
Using recursion:
Base case if the queue is empty return empty;
store the front val and then reverse the rest of the queue then add the store top val at the end of the stack.
 space complexity: o(1) 
 time complexity o(n)

 */

void reversequeuestack(queue<int> &q,int n){
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        int a  = q.front();
        q.pop();
        st.push(a);
    }
    for (int i = 0; i < n; i++)
    {
        int b = st.top();
        q.push(b);
        st.pop();
    }
}

void reversequeueresursion(queue<int> &q,int n){
    if(q.empty()){
        return;
    }
    int a = q.front();
    q.pop();
    reversequeueresursion(q,n);
    q.push(a);
}

int main(){
    queue<int> q;
    q.push(4);
    q.push(3);
    q.push(2);
    q.push(1);
    q.push(0);
    
    reversequeueresursion(q,5);
    for (int i = 0; i < 5; i++)
    {
        cout<<q.front()<<endl;
        q.pop();
    }
    
return 0;
}