#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Subsets II:
Given an integer array nums that may contain duplicates, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]

https://leetcode.com/problems/subsets-ii/description/
 */



/*
Here also we will implement the logic of include and not include but the problem with using only that will be
It will also take up the duplicate values also 

So to make it non duplicate we can do:
i. first find all the possible subset and insert them in a set which will remove all the duplicates
ii. sort the input array and check if i == i-1 then continue as this will lead to a duplicate subset
i != ind
*/

void solve(vector<int> &nums, vector<vector<int>> &ans, vector<int> &temp, int i, int n) {
        //We need to push the empty set also hence push every thing
        ans.push_back(temp);
        
        for (int ind = i; ind < n; ind++) {
            // Skip duplicates
            if (ind != i && nums[ind] == nums[ind - 1]) continue;
            temp.push_back(nums[ind]);
            solve(nums, ans, temp, ind + 1, n);  // Recursive call with ind+1
            temp.pop_back();  // Backtrack
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        solve(nums, ans, temp, 0, n);      
        return ans;  
    }
int main(){

return 0;
}