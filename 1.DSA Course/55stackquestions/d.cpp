#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  Insert An Element At Its Bottom In A Given Stack:
You are given a stack/deque of integers 'MY-STACK' and an integer ‘X’. Your task is to insert ‘X’ to the bottom 
of ‘MY-STACK’ and return the updated stack/deque.
Note :
If ‘MY_STACK’ = [7, 1, 4, 5], then the first element represents the element at the bottom of the stack and the last element represents the element at the top of the stack.
For Example :
Let ‘MY_STACK’ = [7, 1, 4, 5] and ‘X’ = 9. So, ‘MY_STACK’ after insertion becomes [9, 7, 1, 4, 5].

Solution:
Here we going recursion to solve this problem. Base case will be if the stack is empty we will push the new value 
to tervers the stack we need to pop the top element every time hence we wil store the top value in a variable 
and after the recursion call we push the poped the value.
time complexity = O(n)
space complexity = O(n)
 */

void solve(stack<int> &st, int size, int d){
    if(st.empty()){
        st.push(d);
        return;
    }
    int num = st.top();
    st.pop();
    solve(st,size,d);
    st.push(num);
}

void addatend(stack<int> &st, int size, int d){
    solve(st,size,d);
}

int main(){
    int add = 5;
    
    stack<int> st;
    st.push(1);
    st.push(1);
    st.push(2);
    st.push(2);
    int size = st.size();
    addatend(st,size,add);
    size = st.size();
    for (int i = 0; i < size; i++)
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    
return 0;
}