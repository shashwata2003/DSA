#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Reverse First K elements of Queue: using stack:
Given an integer K and a queue of integers, we need to reverse the order of the first K elements of the queue, 
leaving the other elements in the same relative order.
Only following standard operations are allowed on queue.
enqueue(x) : Add an item x to rear of queue
dequeue() : Remove an item from front of queue
size() : Returns number of elements in queue.
front() : Finds front item.
Note: The above operations represent the general processings. In-built functions of the respective
 languages can be used to solve the problem.

Input:
5 3
1 2 3 4 5
Output: 
3 2 1 4 5
Explanation: 
After reversing the given
input from the 3rd position the resultant
output will be 3 2 1 4 5.

Solution:
Apporach: using a stack. 
we know that we can reverse any list if array using a stack. hence we all the first k elements in the stack and 
pop them out and push it back in the queue. but we will still have (size-k) elements in the front of the queue
hence we will pop them out and push them back in the array.
steps:
1. run a loop of k elements and push them in the stack
2. then pop them out of the stack and push them at the back of the queue.
3. now process the leaf over elements in the queue.
4. pop the elements from the front of the queue and push them back of the stack.
5. do it size - k times
Space : o(k);
time: O(n)


 */

void reversefirstkelements(queue<int> &q, int n, int k){
    stack<int> st;
    // reverse the first k element.
    for (int i = 0; i < k; i++)
    {
        int a = q.front();
        q.pop();
        st.push(a);
    }
    while (!st.empty())
    {
        int b = st.top();
        q.push(b);
        st.pop();
    }

    // insert the last element;
    int t = n - k;
    while (t--)
    {
        int c = q.front();
        q.pop();
        q.push(c);
    }
}

int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    int n = 5;
    int k = 3;
    reversefirstkelements(q,n,k);
    for (int i = 0; i < n; i++)
    {
        cout<<q.front()<<endl;
        q.pop();
    }
    
return 0;
}