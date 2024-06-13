#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* Next Smaller Element
You are given an array 'ARR' of integers of length N. Your task is to find the next smaller element for each of
 the array elements.Next Smaller Element for an array element is the first element to the right of that element 
 which has a value strictly smaller than that element.If for any array element the next smaller element does 
 not exist, you should print -1 for that array element.
 For Example:

If the given array is [ 2, 3, 1], we need to return [1, 1, -1]. Because for  2, 1 is the Next Smaller element. 
For 3, 1 is the Next Smaller element and for 1, 
there is no next smaller element hence the answer for this element is -1.
Sample Input 1:
2
4
2 1 4 3
3
1 3 2
Sample Output 1:
1 -1 3 -1
-1 2 -1


Sample Input 2:
2
4
1 2 3 4
2
5 0
Sample Output 2:
-1 -1 -1 -1
 0 -1

 Solution:
 Apporach 1:(using array)
We will first pop the first element out and find the next smallest int value 
by doing this we will be using two loops hence high time complexity.
Time complexity: O(n2)

Apporach 2:
Here we are going to use a stack to solve the question. Here we are going to start the traversal from the right side
1. Intiate a stack with -1 . as the right most element will be return -1 always.
2. now check if the element > st.top then ans = st.top and push the element 
3. else we need to find the smallest element in the stack, we will start poping the tops in the stack until we find
element > st.top when we find it store it ans and return it and after that push the element. 

time complexity: O(n)

 */
vector<int> findsmallest(vector<int> arr, int n){
    stack<int> st;
    st.push(-1);
    vector<int> ans(n) ;
    for (int i = n-1; i >= 0 ; i--)
    {
        while (st.top()>=arr[i])
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(arr[i]);
    }
    return ans;
}


int main(){
    vector<int> arr= {2, 1, 4, 3};
    int n = arr.size();
    vector<int> ans = findsmallest(arr,n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
return 0;
}