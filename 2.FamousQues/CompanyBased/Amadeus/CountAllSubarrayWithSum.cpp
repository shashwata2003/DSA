#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
You are given an integer array 'arr' of size 'N' and an integer 'K'.

Your task is to find the total number of subarrays of the given array whose sum of elements is equal to k.

A subarray is defined as a contiguous block of elements in the array.

Example:
Input: ‘N’ = 4, ‘arr’ = [3, 1, 2, 4], 'K' = 6

Output: 2

Explanation: The subarrays that sum up to '6' are: [3, 1, 2], and [2, 4].
 */

/*steps:
1. we need to use a hashset to store all the sum as we go on
2. now if we reach the target increment ans
3. also every time check if the currsum-targer is present in the set or not
if it does that means we can make a subset with that 
*/

int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
    int sum = 0;
    int n = arr.size();
    int count = 0;
    unordered_set<int> s;
    for(int i = 0; i<n; i++){
        sum = sum+arr[i];
        if(sum == k){
            count++;
        }

        if(s.find(sum-k) != s.end()){
            count++;
        }

        s.insert(sum);
    }
    return count;
}

int main(){

return 0;
}