#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
We have to implement a stack using a queue:
Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack 
should support all the functions of a normal stack (push, top, pop, and empty).

Implement the MyStack class:

void push(int x) Pushes element x to the top of the stack.
int pop() Removes the element on the top of the stack and returns it.
int top() Returns the element on the top of the stack.
boolean empty() Returns true if the stack is empty, false otherwise.
 */

void push(int d,queue<int> &q1,queue<int> &q2){
    q2.push(d);
    while(!q1.empty()){
        q2.push(q1.front());
        q1.pop();
    }
    queue<int> q = q1;
    q1 = q2;
    q2 = q;
}

int popandprint(queue<int> &q1,queue<int> &q2){
    if(q1.empty()){
        return -1;
    }
    int d = q1.front();
    q1.pop();
    return d;
}

int main() {
    int q;
    cin>>q;
    queue<int> q1;
    queue<int> q2;
    for(int i = 0;i<q;i++){
        int t;
        cin>>t;
        if(t == 1){
            int d;
            cin>>d;
            push(d,q1,q2);
        }
        if(t == 2){
            cout<<popandprint(q1,q2)<<endl;;
        }
    }
    return 0;
}