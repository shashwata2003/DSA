#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* Reverse Pairs:
Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where:

0 <= i < j < nums.length and
nums[i] > 2 * nums[j].

Example 1:

Input: nums = [1,3,2,3,1]
Output: 2
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1
Example 2:

Input: nums = [2,4,3,5,1]
Output: 3
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
(2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1
 */

int reversePairs(vector<int>& nums) {
    if(nums.size() == 0){
        return 0;
    }
    int n = nums.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(nums[i]>nums[j]*2){
                count++;
            }
        }
        
    }
    return count;   
} 


//Apporach 2:
// Using merge sort:


void merge(vector<int>& nums, int h, int mid, int l) {
    int len1 = mid - l + 1; // Corrected length calculation
    int len2 = h - mid;

    vector<int> first(len1);
    vector<int> second(len2);

    for (int i = 0; i < len1; i++) {
        first[i] = nums[l + i]; // Corrected index handling
    }

    for (int i = 0; i < len2; i++) {
        second[i] = nums[mid + 1 + i]; // Corrected index handling
    }

    int i = 0, j = 0, k = l;
    while (i < len1 && j < len2) {
        if (first[i] <= second[j]) { // Changed < to <= to handle equal elements correctly
            nums[k++] = first[i++];
        } else {
            nums[k++] = second[j++];
        }
    }

    while (i < len1) {
        nums[k++] = first[i++];
    }
    while (j < len2) {
        nums[k++] = second[j++];
    }
}

int countreverse(vector<int>& nums, int h, int mid, int l) {
    int cnt = 0;
    int j = mid + 1;
    for (int i = l; i <= mid; i++) { // Corrected loop bounds
        while (j <= h && nums[i] > 2 * nums[j]) {
            j++;
        }
        cnt += (j - (mid + 1));
    }
    return cnt;
}

int mergesort(vector<int>& nums, int h, int l) {
    if (l >= h) {
        return 0;
    }

    int mid = l + (h - l) / 2;
    int cnt = 0;

    cnt += mergesort(nums, mid, l);
    cnt += mergesort(nums, h, mid + 1);

    cnt += countreverse(nums, h, mid, l);

    merge(nums, h, mid, l);

    return cnt;
}

int reversePairs1(vector<int>& nums) {
    int h = nums.size() - 1;
    return mergesort(nums, h, 0);
}

int main(){
    vector<int> nums = {2,4,3,5,1};
    cout<<reversePairs1(nums);
return 0;
}