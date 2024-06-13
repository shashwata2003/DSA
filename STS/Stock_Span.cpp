#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Stock Span: Given a array of stock prices. We need to find the series of consecutive elements which are smaller
than the current index element.
eg : {10,4,5,90,120,80}
consider the current index is at 120
ans array will be : {1,1,2,4,5,1} we need to count itself also. 
10 is the last one hence = 1
4 < 10 hence counting itself only = 1
5 > 4 but 5<10 hence 2 
continue....
sol:
Using stack: we will store the index of the elements in the stack
first check the stack if it is empty or not if yes then push the current index and store the i+ 1 in the ans arr
Now if the stack is not empty then compare the values of index stored in the stack with the value of current index
if smaller then pop the index out of the stack and compare the next one. now if the value from the stack > than form 
the current index then ans = currentindex - stackindex,  push the current index in the stack.
Check not book for the example: 

 */
int main(){
    vector<int> arr = {10,4,5,90,120,80};
    vector<int> ans;
    stack<int> st;
    for (int i = 0; i < arr.size(); i++)
    {
        while (!st.empty() && arr[st.top()]<=arr[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            ans.push_back(i+1);
        }else
        {
            ans.push_back(i-st.top());
        }
        st.push(i);
    }
    
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
return 0;
}