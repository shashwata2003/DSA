#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
*/

/*
Apporach 1:
Using Map:
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();  // Step 1: Initialize n with the size of the array
        unordered_map<int, int> m;  // Step 1: Create an unordered map to store frequency counts
        
        // Step 2: Count frequencies of each element in the array
        for (int i = 0; i < n; i++) {
            m[nums[i]]++;
        }
        
        // Step 3: Calculate the majority threshold
        n = n / 2;  // Majority element must appear more than n/2 times
        
        // Step 4: Find and return the majority element
        for (auto x : m) {
            if (x.second > n) {
                return x.first;
            }
        }
        
        // Step 5: Return 0 (should not be reached due to problem constraints)
        return 0;
    }
};

/*Apporach 2:
The algorithm starts by assuming the first element as the majority candidate and sets the count to 1.

As it iterates through the array, it compares each element with the candidate:
a. If the current element matches the candidate, it suggests that it reinforces the majority element because it appears again. Therefore, the count is incremented by 1.
b. If the current element is different from the candidate, it suggests that there might be an equal number of occurrences of the majority element and other elements. Therefore, the count is decremented by 1.

Note that decrementing the count doesn't change the fact that the majority element occurs more than n/2 times.

If the count becomes 0, it means that the current candidate is no longer a potential majority element. In this case, a new candidate is chosen from the remaining elements.

The algorithm continues this process until it has traversed the entire array.

The final value of the candidate variable will hold the majority element.
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = 0;
        
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            
            if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }
        
        return candidate;
    }
};


int main(){

return 0;
}