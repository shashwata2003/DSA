#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

 

Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]
 
 */

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size(); // Step 1: Initialize n with the size of the array
        unordered_map<int, int>
            m; // Step 1: Create an unordered map to store frequency counts

        // Step 2: Count frequencies of each element in the array
        for (int i = 0; i < n; i++) {
            m[nums[i]]++;
        }

        // Step 3: Calculate the majority threshold
        n = n / 3; // Majority element must appear more than n/2 times
        vector<int> ans;
        // Step 4: Find and return the majority element
        for (auto x : m) {
            if (x.second > n) {
                 ans.push_back(x.first);
            }
        }

        // Step 5: Return 0 (should not be reached due to problem constraints)
        return ans;
    }
};

int main(){

return 0;
}