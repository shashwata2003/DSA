#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  
Trapping Rain Water
Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it can trap after raining.

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

Example 2:
Input: height = [4,2,0,3,2,5]
Output: 9

Check the optimized apporach with two pointer method for the interveiws:

*/

int trapping(vector<int> &arr){
    int n = arr.size();

    vector<int> left(n);
    vector<int> right(n);

    // start calculating finding the largest wall form the left:
    left[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        left[i] = max(left[i-1],arr[i]);
    }

    // start the finding the largest wall from the right:
    right[n-1] = arr[n-1];
    for(int i = n-2;i>=0;i--){
        right[i] = max(right[i+1],arr[i]);
    }

    // now check how much water we can store: 
    // find the min
    int water = 0;
    for (int i = 1; i < n-1; i++)
    {
        // for a ith index we need to check the tallest bar in the left side and the tallest bar in the right:
        int var = min(left[i-1],right[i+1]);
        if(var>arr[i]){
            water = water+ (var- arr[i]);
        }
    }
    
    return water;
}

int main(){
    vector<int> arr = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<trapping(arr);
return 0;
}