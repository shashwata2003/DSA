#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Largest Rectangle in Histogram:
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, 
return the area of the largest rectangle in the histogram.
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
Input: heights = [2,4]
Output: 4
Solution:
Apporach 1: Brute force:
We know that the area = L * B 
here we can traverse the array one by one making the length constant and finding the maximum breath by checking the 
right and left side of the array 
eg: for L = 2 we will check if we can go right which is 1 hence no , can we go left no hence max arear == 2 * 1 = 2
we will continue this till the end
Time complexity: O(n2)

Apporach 2: Optimized:
Here we are going to use the logic of finding the next smallest element's index. 
so consider if we know the next smallest element we can find the max width for the rectangle 
hence B = next smallest index - prev smallest index -1 will be the largest width 
The are will give the make area with the current index.

Here we need to take care of the edge case when th i/p = [2,2,2,2] this means the next smallest and prev smallest 
elements will be -1 hence the area will be negative which doesnot make sense, hence we will change the next 
val to = n 
 */

vector<int> findnextsmallest(vector<int> arr, int n){
    stack<int> st;
    st.push(-1);
    vector<int> ans(n);
    for (int i = n-1; i >= 0; i--)
    {
        while (st.top() != -1 && arr[st.top()] >= arr[i]) 
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
        
    }
    return ans;
}

vector<int> findprevsmallest(vector<int> arr, int n){
    stack<int> st;
    st.push(-1);
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        while (st.top() != -1 && arr[st.top()] >= arr[i]) 
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
        
    }
    return ans;
}

int findlargestarea(vector<int> arr){
    int n = arr.size();
    vector<int> next(n);
    next = findnextsmallest(arr,n);
    vector<int> prev(n);
    prev = findprevsmallest(arr,n);
    int area = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int l = arr[i];
        if(next[i] == -1){
            next[i] = n;
        }
        int b  = next[i]  - prev[i] -1;
        int newarea = l*b;
        area = max(newarea, area);
    }
    return area;
}

int main(){
    vector<int> arr = {2,1,5,6,2,3}; 
    int ans = findlargestarea(arr);
    cout<<ans;
return 0;
}