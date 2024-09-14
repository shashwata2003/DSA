#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

Examples:

Input: arr[] = {15,-2,2,-8,1,7,10,23}, n = 8
Output: 5
Explanation: The largest subarray with sum 0 is -2 2 -8 1 7.
Input: arr[] = {2,10,4}, n = 3
Output: 0
Explanation: There is no subarray with 0 sum.
Input: arr[] = {1, 0, -4, 3, 1, 0}, n = 6
Output: 5
Explanation: The subarray is 0 -4 3 1 0.
 */

/* 
Now let’s say we know that the sum of subarray(i, j) = S, and we also know that the sum of subarray(i, x) = S where i < x < j. We can conclude that the sum of subarray(x+1, j) = 0.

Let us understand the above statement clearly,

So in this problem, we’ll store the prefix sum of every element, and if we observe that 2 elements have the same prefix sum, we can conclude that the 2nd part of this subarray sums to zero

Approach: 
1. First, let us initialize a variable say sum = 0 which stores the sum of elements traversed so far and another variable says max = 0 which stores the length of the longest subarray with sum zero.
2. Declare a HashMap<Integer, Integer> which stores the prefix sum of every element as a key and its index as a value.
3. Now traverse the array, and add the array element to our sum. 
 */

class Solution {
public:
    // Function to find the length of the longest subarray with sum 0
    int maxLen(vector<int>& arr, int n) {
        unordered_map<int, int> mp; // Hash map to store the cumulative sum and its first occurrence index
        int sum = 0;                // Variable to store the cumulative sum
        int ans = 0;                // Variable to store the maximum length of subarray with sum 0

        // Traverse through the array
        for (int i = 0; i < n; i++) {
            sum += arr[i];  // Add the current element to the cumulative sum

            // If cumulative sum becomes 0, update the answer with the current length (i+1)
            if (sum == 0) {
                ans = i + 1;
            }
            // If the sum has been seen before, it means the subarray between previous index and i has sum 0
            else if (mp.find(sum) != mp.end()) {
                ans = max(ans, i - mp[sum]);  // Update the answer with the maximum length found so far
            }
            // If the sum is not found, store its index in the hash map
            else {
                mp[sum] = i;
            }
        }

        return ans; // Return the length of the longest subarray with sum 0
    }
};


int main(){

return 0;
}