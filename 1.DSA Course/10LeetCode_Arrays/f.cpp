#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
codestudio: Intersection of two array
GIven two array and we need to find the intersection of these two array
and if there is no intersection return -1
eg arr1: 1 2 2 2 3 4
    arr2 : 2 2 3 3
    ans : 2 2 3
Sol:
appoarch 1:
we need to use brute force for now. we will select one element from the second array and match it with 
the first array, if the match happens we need the update the second array with the int_min value , print the value 
and break the loop
These solution hits Time limit extention
Approach 2: Optimize the above solution: First sort the arrays and if the arr1[0]<arr2[0] then no need to search ahead.
hench break the loop

Approach 3: To optimize the code: done it in next file.
     */
int main(){
    vector<int> arr1 ={1,2,2,2,3,4};
    vector<int> arr2 = {2,2,3,3}; 
    vector<int> ans;
    for (int i = 0; i < arr1.size(); i++)
    {
        int ele = arr1[i];
        for (int j = 0; j < arr2.size(); j++)
        {
            if(ele < arr2[j]){
                break;
            }
            if(ele == arr2[j]){
                cout<<ele<<" ";
                arr2[j] = -11111;
                break;
            }
        }
        
    }
    
return 0;
}