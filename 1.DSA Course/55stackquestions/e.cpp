#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*
Reverse Stack Using Recursion:
Reverse a given stack of 'N' integers using recursion. You are required to make changes in the input parameter 
itself.
Note: You are not allowed to use any extra space other than the internal stack space used due to recursion.
Example:
Input: [1,2,3,4,5] 
Output: [5,4,3,2,1]

Solution:
Here we use recursion to solve the problem :
first we will remove the top element of the stack and run recursivily call the reverse stack fuction and add the
stored top val to the buttom of the stack.
we will use the same method we use in the previous problem to add the element to the buttom of the stack.
Time complexity : O(n2)
 */
void insertAtBottom(stack<int> &s, int element) {
    //basecase
    if(s.empty()) {
        s.push(element);
      	return ;
    }
    
    int num = s.top();
    s.pop();
    
    //recursive call
    insertAtBottom(s, element);
    
    s.push(num);
}

void reverseStack(stack<int> &stack) {
  	//base case
    if(stack.empty()) {
        return ;
    }
    
    int num = stack.top();
    stack.pop();
    
    //recursive call
    reverseStack(stack);
    
    insertAtBottom(stack,num);
}
int main()
{
    stack<int> st;
    
    st.push(1);
    st.push(1);
    st.push(2);
    st.push(2);
    int size = st.size();
    reverseStack(st);
    for (int i = 0; i < size; i++)
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}