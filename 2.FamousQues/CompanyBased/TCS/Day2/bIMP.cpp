#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Find all the subarrays with a given target value.

 */

/*
Here’s how the approach works:

Keep track of the cumulative sum (prefix sum) as you iterate through the array.
For each element, calculate the difference between the current prefix sum and the target.
If this difference has been seen before in the hash map, it means there exists a subarray ending at the current index that sums to the target.
*/
void findSubarraysWithTarget(vector<int>& nums, int target) {
    unordered_map<int, vector<int>> prefixMap;
    int prefixSum = 0;
    
    // Initialize the map with the prefix sum 0 at index -1
    prefixMap[0].push_back(-1);

    for (int i = 0; i < nums.size(); i++) {
        prefixSum += nums[i];
        
        // Check if (prefixSum - target) is in the map
        if (prefixMap.find(prefixSum - target) != prefixMap.end()) {
            for (int start : prefixMap[prefixSum - target]) {
                cout << "Subarray found from index " << start + 1 << " to " << i << endl;
            }
        }

        // Add the current prefixSum to the map
        prefixMap[prefixSum].push_back(i);
    }
}

int main() {
    vector<int> nums = {10, 2, -2, -20, 10};
    int target = -10;

    findSubarraysWithTarget(nums, target);

    return 0;
}