#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Max Consecutive Ones III
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

 

Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
Example 2:

Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
 */

/*
When we reach the limit of the zero we just move the left point till the point it reduces the no. of zeros already traversed.
*/
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0;
        int l = 0; 
        int r = 0;
        int zeros = 0;
        int n = nums.size();
        while(r<n){
            if(nums[r] == 0){
                zeros++;
            }
            while(zeros>k){
                if(nums[l] == 0){
                    zeros--;
                }
                l++;
            }
            if(zeros <= k){
                ans = max(ans, r-l+1);
            }
            r++;
        }
        return ans;
    }
};


/*Same but more optimized:*/
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0;
        int l = 0; 
        int r = 0;
        int zeros = 0;
        int n = nums.size();
        while(r<n){
            if(nums[r] == 0){
                zeros++;
            }
            //Here we removed the while loop and keep the window sied fixed
            if(zero>k){
                if(nums[l] == 0){
                    zero++;
                }
                l++;
            }
            if(zeros <= k){
                ans = max(ans, r-l+1);
            }
            r++;
        }
        return ans;
    }
};
int main(){

return 0;
}