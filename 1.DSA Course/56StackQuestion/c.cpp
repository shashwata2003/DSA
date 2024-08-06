#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Previous Smallest element:
To find the smallest element in array in the left side of the reference element.
eg:
[1 2 3 4 5]
o/p:
[-1,1,2,3,4]
Sol:
The apporach will similar to finding the smallest next element, just here we will find the start our search from
start of the array and the stack will be init with -1 as usual.
 */

vector<int> smallestprevelement(vector<int> &arr, int n){
    stack<int> st;
    vector<int> ans(n);
    st.push(-1);
    for(int i = 0;i<n;i++){
        while(st.top()>arr[i]){
            st.pop();
        }
        ans[i] = st.top();
        st.push(arr[i]);
    }
    return ans;
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    vector<int> ans = smallestprevelement(arr,arr.size());
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<endl;
    }
    
return 0;
}