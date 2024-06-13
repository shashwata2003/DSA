#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Trapping Rain Water: Leetcode
Given n non-negative integers representing 
an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

sol: to find the water stored in each stage we need to use the formula: 
min(max of left side of i, max of right side of i) - 1 
if the answer is negative than change it to zero.
 */
int trappingrainwater(vector<int> arr) {

    int n = arr.size();
    int left[n]; 

    int right[n]; 
  
    // Initialize result 
    int water = 0; 
  
    // Fill left array 
    left[0] = arr[0]; 
    for (int i = 1; i < n; i++) 
        left[i] = max(left[i - 1], arr[i]); 
  
    // Fill right array 
    right[n - 1] = arr[n - 1]; 
    for (int i = n - 2; i >= 0; i--) 
        right[i] = max(right[i + 1], arr[i]); 


    for (int i = 1; i < n - 1; i++) { 
        int var = min(left[i - 1], right[i + 1]); 
        if (var > arr[i]) { 
            water += var - arr[i]; 
        } 
    } 
  
    return water;
}
int main(){
    vector<int> arr = {3, 0, 2, 0, 4};
    int ans = trappingrainwater(arr);
    cout<<ans;
return 0;
}