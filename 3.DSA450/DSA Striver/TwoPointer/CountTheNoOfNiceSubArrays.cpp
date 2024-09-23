#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  1248. Count Number of Nice Subarrays:
Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.

 

Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
Example 2:

Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There are no odd numbers in the array.
Example 3:

Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16
*/

/*This is question is exaclty similar to Binary Subarrays With Sum
Here we will consider a odd num = 1 and even as = 0 and 
and we need to find the count of subarray which is equal to k  */

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
            sum += nums[r] % 2;  // Add the current element to the sum

            // If the sum exceeds the goal, shrink the window from the left
            while (sum > goal) {
                sum -= nums[l] % 2;  // Subtract the element at the left pointer
                l++;  // Move the left pointer to the right, shrinking the window
            }

            // All subarrays that end at index 'r' and start between 'l' and 'r' are valid
            ans += (r - l + 1);  // Add the number of valid subarrays ending at 'r'
            r++;  // Move the right pointer to expand the window
        }

        return ans;  // Return the total count of valid subarrays
    }

    // Main function to find the number of subarrays with an exact sum equal to 'goal'
    
    


    int numberOfSubarrays(vector<int>& nums, int k) {
            // To find the exact number of subarrays with sum == goal, 
        // subtract the number of subarrays with sum <= goal-1 from those with sum <= goal
        return lessequaltok(nums, k) - lessequaltok(nums, k - 1);
    }
    
};

int main(){

return 0;
}