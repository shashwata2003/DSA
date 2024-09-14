#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
 */

/*
Steps:
The steps are as follows:

1. First, we will sort the entire array.
We will use a loop(say i) that will run from 0 to n-1. This i will represent one of the fixed pointers. In each iteration, this value will be fixed for all different values of the rest of the 3 pointers. Inside the loop, we will first check if the current and the previous element is the same and if it is we will do nothing and continue to the next value of i.
2.After checking inside the loop, we will introduce another fixed pointer j(runs from i+1 to n-1) using another loop. Inside this second loop, we will again check for duplicate elements and only perform any further operation if the elements are different.
3.Inside the second loop, there will be 2 moving pointers i.e. k(starts from j+1) and l(starts from the last index). The pointer k will move forward and the pointer l will move backward until they cross each other while the value of i and j will be fixed.
4.Now we will check the sum i.e. nums[i]+nums[j]+nums[k]+nums[l].
    **If the sum is greater, then we need lesser elements and so we will decrease the value of l.
    **If the sum is lesser than the target, we need a bigger value and so we will increase the value of k. 
    **If the sum is equal to the target, we will simply insert the quad i.e. nums[i], nums[j], nums[k], and nums[l] into our answer and move the pointers k and l skipping the duplicate elements(i.e. by checking the adjacent elements while moving the pointers).
5.Finally, we will have a list of unique quadruplets.
*/


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end()); // Sort the array
        int n = nums.size();
        vector<vector<int>> ans;
        
        for (int i = 0; i < n - 3; i++) {
            // Skip duplicates for the first number
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            for (int j = i + 1; j < n - 2; j++) {
                // Skip duplicates for the second number
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                
                int k = j + 1;
                int l = n - 1;
                
                while (k < l) {
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                    
                    if (sum == target) {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        
                        // Skip duplicates for the third and fourth numbers
                        while (k < l && nums[k] == nums[k + 1]) k++;
                        while (k < l && nums[l] == nums[l - 1]) l--;
                        
                        k++;
                        l--;
                    } else if (sum < target) {
                        k++;
                    } else {
                        l--;
                    }
                }
            }
        }
        
        return ans;
    }
};


int main(){

return 0;
}