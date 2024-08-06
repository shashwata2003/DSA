#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 

Given an integer array nums, find the 
subarray with the largest sum, and return its sum and also print the same subarray.
eg:
Example 1:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.

Example 2:
Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.

Example 3:
Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.

 */

int maxsubarray(vector<int> arr, int n){
    int maxsum = -999,  currmax = 0;
    for (int i = 0; i < n; i++)
    {
        currmax = currmax + arr[i];
        if(maxsum < currmax){
            maxsum = currmax;
        }
        if(currmax < 0){
            currmax = 0;
        }
    }
    return maxsum;
}

pair<int,int> maxsumindex(vector<int> arr, int n){
    int start = 0, end = 0, s = 0;
    int maxsum = INT_MIN, currmax = 0;
    for (int i = 0; i < n; i++)
    {
        currmax = currmax + arr[i];
        if(maxsum < currmax){
            maxsum = currmax;
            start = s;
            end  = i;
        }
        if(currmax < 0){
            currmax = 0;
            s = i +1;
        }
    }
    return {start,end};
}

int main(){
    vector<int> arr = {5,4,-1,7,8};
    int n = arr.size();
    cout<<maxsumindex(arr,n).first<<" "<<maxsumindex(arr,n).second<<endl;
return 0;
}