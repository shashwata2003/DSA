#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]
Example 2:

Input: nums = [3,2,1]
Output: [1,2,3]
Example 3:

Input: nums = [1,1,5]
Output: [1,5,1]
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 100
 */

/*
Apporach 1: 
using next permuation build in function
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(),nums.end());
    }
};

/*
Apporach 2:
Steps:
1. find the seq which is longest on increasing seq for this we need start checking the array from the back
2. if the entire array is decreasing order just reverse the arr
3. else find the element from the back at which the array is not sorted
4. swap that position with the point where the sorted array ended
5. and reverse the array from the end till the end of the sorted array
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        auto it = is_sorted_until(nums.rbegin(),nums.rend());

        if(it == nums.rend()){
            //enntire array is in decresing order and is sorted from back
            reverse(nums.begin(),nums.end());
        }
        else{
            // now find the next elemnt after the it element
            auto next_it = upper_bound(nums.rbegin(),it,*it);
            swap(*it,*next_it);
            reverse(nums.rbegin(), it);
        }
    }
};

/*Apporach 3:
First find the index where the array is not sorted 
*/

class Solution {
public:
    
    void nextPermutation(vector<int>& nums) {
        int idx = -1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                idx = i; // index where the array becomes non sorted from the end
                break;
            }
        }

        if (idx == -1) {
            reverse(nums.begin(), nums.end()); // of not found hence the entire array is decreasing from the 
            //begining hence reverse the entire arr
            
        }
        else{
            // if not that find the pivot point and swap the vals and then reverse 
        for (int i = nums.size() - 1; i > idx; i--) {
            if (nums[i] > nums[idx]) {
                swap(nums[i], nums[idx]); // find the pivot
                break;
            }
        }

        reverse(nums.begin() + idx + 1, nums.end());
        }
    }
}

int main(){

return 0;
}