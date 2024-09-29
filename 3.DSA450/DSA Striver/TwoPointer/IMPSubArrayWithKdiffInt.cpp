#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Given an integer array nums and an integer k, return the number of good subarrays of nums.

A good array is an array where the number of different integers in that array is exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]
Example 2:

Input: nums = [1,2,1,3,4], k = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
 */

/*Similar to the Binary Sum eql to goal question but here we dont have a sum goal rather we have a 
Count of map to maintain.
*/


class Solution {
public:
    // Function to calculate the number of subarrays with at most 'k' distinct integers.
    int solve(vector<int> &nums, int k) {
        unordered_map<int, int> mp;  // Hash map to store the frequency of elements in the current window.
        int n = nums.size();         // Get the size of the input array.
        int l = 0;                   // Left pointer of the sliding window.
        int r = 0;                   // Right pointer of the sliding window.
        int cnt = 0;                 // Counter to keep track of the number of valid subarrays.

        // Iterate through the array with the right pointer.
        while(r < n) {
            mp[nums[r]]++;  // Add the element at the right pointer to the hash map and increase its frequency.

            // Shrink the window from the left if there are more than 'k' distinct elements.
            while(mp.size() > k) {
                mp[nums[l]]--;  // Decrease the frequency of the element at the left pointer.
                
                // If the frequency of the element at the left pointer becomes 0, remove it from the map.
                if(mp[nums[l]] <= 0) {
                    mp.erase(nums[l]);
                }
                l++;  // Move the left pointer to the right, shrinking the window.
            }

            // If the window has at most 'k' distinct elements, add the number of subarrays ending at 'r'.
            if(mp.size() <= k) {
                cnt = cnt + (r - l + 1);  // All subarrays between the current left and right pointers are valid.
            }

            r++;  // Move the right pointer to the next element.
        }

        return cnt;  // Return the total count of subarrays with at most 'k' distinct elements.
    }

    // Function to calculate the number of subarrays with exactly 'k' distinct integers.
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // The number of subarrays with exactly 'k' distinct integers is the difference between:
        // 1. Subarrays with at most 'k' distinct integers.
        // 2. Subarrays with at most 'k-1' distinct integers.
        return solve(nums, k) - solve(nums, k - 1);
    }
};


int main(){

return 0;
}