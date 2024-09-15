#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
You are given an integer array nums of size n.

Consider a non-empty subarray from nums that has the maximum possible bitwise AND.

In other words, let k be the maximum value of the bitwise AND of any subarray of nums. Then, only subarrays with a bitwise AND equal to k should be considered.
Return the length of the longest such subarray.

The bitwise AND of an array is the bitwise AND of all the numbers in it.

A subarray is a contiguous sequence of elements within an array.

 

Example 1:

Input: nums = [1,2,3,3,2,2]
Output: 2
Explanation:
The maximum possible bitwise AND of a subarray is 3.
The longest subarray with that value is [3,3], so we return 2.
Example 2:

Input: nums = [1,2,3,4]
Output: 1
Explanation:
The maximum possible bitwise AND of a subarray is 4.
The longest subarray with that value is [4], so we return 1.
 */

class Solution {
public:
    // Method to find the length of the longest subarray consisting of the maximum element.
    int longestSubarray(std::vector<int>& nums) {
        // Get the maximum value in the array.
        int maxValue = *std::max_element(nums.begin(), nums.end());
        // Initialize answer (longest subarray length) and counter for current subarray length.
        int longestSubarrayLength = 0, currentSubarrayLength = 0;
      
        // Iterate over each element in the array.
        for (int value : nums) {
            // Check if the current element equals the maximum value.
            if (value == maxValue) {
                // Increment the current subarray length as it is part of a subarray containing max elements.
                ++currentSubarrayLength;
                // Update the answer with the maximum subarray length found so far.
                longestSubarrayLength = std::max(longestSubarrayLength, currentSubarrayLength);
            } else {
                // Reset current subarray length if the current element is not the maximum value.
                currentSubarrayLength = 0;
            }
        }
        // Return the length of the longest subarray found.
        return longestSubarrayLength;
    }
};

int main(){

return 0;
}