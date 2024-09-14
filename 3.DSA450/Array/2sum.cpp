#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> mp; // Map to store number and its index
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            // Check if the complement (target - nums[i]) exists in the map
            if (mp.find(target - nums[i]) != mp.end()) {
                ans.push_back(mp[target - nums[i]]); // Index of the complement
                ans.push_back(i); // Current index
                return ans; // Return the result
            }
            // Add the current number and its index to the map
            mp[nums[i]] = i;
        }
        
        return ans; // Return empty vector if no solution found
    }
};


int main(){

return 0;
}