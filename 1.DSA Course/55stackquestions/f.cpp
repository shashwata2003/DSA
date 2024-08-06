#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  
Sort a Stack:
You’re given a stack consisting of 'N' integers. 
Your task is to sort this stack in descending order using recursion.
We are not suppose to use any loops .
eg:
Sample Input 1:
1
5
5 -2 9 -7 3
Sample Output 1:
9 5 3 -2 -7

Solution:
As we are going to use recursion the base case will be if stack.empty() return.
now in a function  we will store the top element of the stack in a variable and call the recusiving the 
same function, by this we will have n no. of calls and n no. of vaiables will be stored in the variable 
now when we push the stored varible we will push it in sorted way.

to push the variable in sorted way we 
1. compare the val with the top if is less that the top we will push the val
2. else we will pop the top and store it a variable and recursive call the same function(base case: if top<val push val)
3. now we will push the val back

Time complexity: O(n2);
*/

void insertsorted(stack<int> &s, int d){
    if(s.empty() ||(!s.empty() && d>s.top())){
        s.push(d);
        return;
    }
    int n = s.top();
    s.pop();
    insertsorted(s,d);
    s.push(n);
}

void sortstack(stack<int> &st){
    if(st.empty()){
        return;
    }
    int num = st.top();
    st.pop();
    sortstack(st);
    insertsorted(st,num);
}

int main(){
    stack<int> st;
    
    st.push(5);
    st.push(-2);
    st.push(9);
    st.push(-7);
    st.push(3);
    int size = st.size();
    sortstack(st);
    for (int i = 0; i < size; i++)
    {
        cout << st.top() << " ";
        st.pop();
    }

return 0;
}