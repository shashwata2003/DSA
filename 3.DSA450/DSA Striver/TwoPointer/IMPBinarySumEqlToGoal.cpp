#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 930. Binary Subarrays With Sum
Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.

 

Example 1:

Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
Example 2:

Input: nums = [0,0,0,0,0], goal = 0
Output: 15
 
 */

class Solution {
public:
    // Function to find the number of subarrays with a sum less than or equal to a given 'goal'
    int lessequaltok(vector<int>& nums, int goal) {
        if (goal < 0) 
            return 0;  // If the goal is negative, no valid subarrays exist, so return 0

        int l = 0;  // Left pointer to track the start of the subarray
        int r = 0;  // Right pointer to track the end of the subarray
        int ans = 0;  // This will store the count of valid subarrays
        int n = nums.size();  // Length of the input array
        int sum = 0;  // This will store the current sum of the subarray

        // Iterate through the array using the right pointer
        while (r < n) {
            sum += nums[r];  // Add the current element to the sum

            // If the sum exceeds the goal, shrink the window from the left
            while (sum > goal) {
                sum -= nums[l];  // Subtract the element at the left pointer
                l++;  // Move the left pointer to the right, shrinking the window
            }

            // All subarrays that end at index 'r' and start between 'l' and 'r' are valid
            ans += (r - l + 1);  // Add the number of valid subarrays ending at 'r'
            r++;  // Move the right pointer to expand the window
        }

        return ans;  // Return the total count of valid subarrays
    }

    // Main function to find the number of subarrays with an exact sum equal to 'goal'
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // To find the exact number of subarrays with sum == goal, 
        // subtract the number of subarrays with sum <= goal-1 from those with sum <= goal
        return lessequaltok(nums, goal) - lessequaltok(nums, goal - 1);
    }
};

int main(){

return 0;
}