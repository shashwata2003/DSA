#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Leetcode: Reverse an Array:
Given a array [1,2,3,4,5] reverse it [5,4,3,2,1]
 */
int main(){
    vector<int> arr= {1,2,3,4,5};
    vector<int> arr1 = {1,2,3,4,5};
    vector<int> arr2 = {1,2,3,4,5};
    // using STL
    reverse(arr.begin(),arr.end());
    //Not using STL(two pointer method:
    int s = 0, e = arr.size() - 1;
    while (s<=e)
    {
        swap(arr1[s],arr1[e]);
        s++;
        e--;
    }
    // Addition problem: given a index in the question. Reverse the array after that index. like m = 2 reversed arr
    // will be {1,2,3,5,4}
    int m = 2;
    int st = m+1, en = arr.size()-1;
    while (st<=en)
    {
        swap(arr2[st],arr2[en]);
        st++;
        en--;
    }
    
    
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr2[i]<<" ";
    }
     
return 0;
}