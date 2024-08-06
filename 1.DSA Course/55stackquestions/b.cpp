#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* Delete middle elememt form the stack:
You are having a stack "ARR" of size 'N+1', 
your task is to delete the middlemost element so that the size of resulting stack is 'N'.
eg: INPUT : ARR [ ] = [ 1 , 2 , 3 , 4 , 5 ] , N = 4
OUTPUT: ARR [ ] = [ 1 , 2 , 4,  5 ]
Solution:
we will use the concept of recursion we will find the mid of the stack using the size/ 2 and also run a 
counter called 
count if count == mid we will pop that element.
Now to traverse the stack we need to pop the top item every time hence we need to store the non mid elements whicha
are not mid element.
 */


void solve(stack<int> &st, int size, int count) {
    if (count == size / 2 - 1) { // Corrected condition
        st.pop();
        return; // Added return statement to stop further recursion
    }
    int num = st.top();
    st.pop();
    solve(st, size, count + 1);
    st.push(num);
}

void popmid(stack<int> &st, int size) {
    int count = 0;
    solve(st, size, count);
}

int main() {
    stack<int> st;
    int size = 5;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    popmid(st, size);
    while (!st.empty()) { // Corrected loop condition
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}