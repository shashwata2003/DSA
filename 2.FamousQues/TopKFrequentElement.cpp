#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Given an integer array nums and an integer k, return the k most frequent elements. You may 
return the answer in any order.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        
        // Count the frequency of each element in nums
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        // Create a max-heap using a priority queue, where the first element of the pair is the frequency
        priority_queue<pair<int, int>> pq;
        for (auto& pair : mp) {
            pq.push({pair.second, pair.first});
        }

        vector<int> ans;
        
        // Extract the top k elements from the heap
        for (int i = 0; i < k; i++) {
            ans.push_back(pq.top().second); // Add the element to the answer vector
            pq.pop(); // Remove the top element from the heap
        }

        return ans; // Return the result vector containing the top k frequent elements
    }
};

int main(){

return 0;
}