#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Given an integer array, find the previous smaller element for every array element. The previous smaller 
element of a number x is the first smaller number to the left of x in the array.

In other words, for each element A[i] in the array A, find an element A[j] such that j < i and A[j] < A[i] 
and value of j should be as maximum as possible. If the previous smaller element doesn't in the array for 
any element, consider it -1.

 For example,

Input:  [2, 5, 3, 7, 8, 1, 9]Output: [-1, 2, 2, 3, 7, -1, 1]  

Input:  [5, 7, 4, 9, 8, 10]Output: [-1, 5, -1, 4, 4, 8]
 */


/*
Using stack:
1. create a empty stack
2. as the stack is empty at first push -1 in the ans and push the first element in the stack
3. now check run till stack is empty and check weather the top of the stack is less than the current elem
4. if so then push that top in the stack
5. else pop the top and move to the next top in the stack
6. if the stack becomes empty push -1
*/
vector<int> findprevsmallest(vector<int> &arr, int n){
    stack<int> st;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        while(!st.empty()){
            if(st.top()<arr[i]){
                ans.push_back(st.top());
                break;
            }else{
                st.pop();
            }
        }
        if(st.empty()){
            ans.push_back(-1);
        }
        st.push(arr[i]);
    }
    return ans;
}

int main(){
    vector<int> arr = {2, 5, 3, 7, 8, 1, 9};
    vector<int> ans = findprevsmallest(arr,arr.size());
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
return 0;
}