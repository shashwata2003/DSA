#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 */

/*Apporach 1: using DP and memorization*/

class Solution
{
public:
    bool solve(vector<int> &num, int n, int i, vector<int> &memo)
    {
        // Base case: If current index is at or beyond the last index, return true
        if (i >= n - 1)
        {
            return true;
        }

        // If this index is already computed, return its value
        if (memo[i] != -1)
        {
            return memo[i];
        }

        int currcap = num[i];
        for (int j = 1; j <= currcap; j++)
        {
            if (solve(num, n, i + j, memo))
            {
                return memo[i] = true; // Memoize the result
            }
        }

        return memo[i] = false; // Memoize the result
    }

    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> memo(n, -1); // Memoization array to store results
        return solve(nums, n, 0, memo);
    }
};

/*Apporach 2: simpilar apporach */
class Solution
{
public:
    bool canJump(vector<int> &jumps)
    {
        int maxReach =
            0; // This stores the maximum floor we can reach at any point
        int n = jumps.size();

        for (int i = 0; i < n; i++)
        {
            if (i > maxReach)
            {
                // If current floor is beyond the maximum floor we can reach, we
                // can't proceed
                return false;
            }
            maxReach =
                max(maxReach,
                    i + jumps[i]); // Update the maximum floor we can reach
        }

        return maxReach >= n - 1; // Check if we can reach the top (last floor)
    }
};

int main()
{

    return 0;
}