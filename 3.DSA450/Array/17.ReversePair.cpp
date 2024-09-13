#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
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
/*Apporach 1: Brute Force */
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                if(nums[i] > 2*nums[j]){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

/*Apporach 2: Using Merge Sort*/

class Solution {
private:
    // Step 1: Merge two sorted halves of the array.
    void merge(vector<int> &nums, int s, int mid, int e){
        // Calculate lengths of two halves
        int len1 = mid - s + 1;
        int len2 = e - mid;

        // Step 2: Create temporary arrays to store the two halves
        vector<int> first(len1);
        vector<int> second(len2);

        // Step 3: Copy values from original array into these temporary arrays
        int index = s;
        for(int i = 0; i < len1; i++){
            first[i] = nums[index++];
        }
        index = mid + 1;
        for(int i = 0; i < len2; i++){
            second[i] = nums[index++];
        }

        // Step 4: Initialize pointers to traverse both temporary arrays
        int index1 = 0;
        int index2 = 0;
        index = s;

        // Step 5: Merge the two sorted halves back into the original array
        while(index1 < len1 && index2 < len2){
            if(first[index1] < second[index2]){
                nums[index++] = first[index1++];
            } else {
                nums[index++] = second[index2++];
            }
        }

        // Step 6: Copy any remaining elements from the left half (if any)
        while(index1 < len1){
            nums[index++] = first[index1++];
        }

        // Step 7: Copy any remaining elements from the right half (if any)
        while(index2 < len2){
            nums[index++] = second[index2++];
        }
    }

    // Step 8: Count reverse pairs between the two halves.
    // A reverse pair is where nums[i] > 2 * nums[j], with i < j.
    int countpairs(vector<int> &nums, int s, int mid, int e){
        int right = mid + 1;
        int cnt = 0;

        // Step 9: For each element in the left half, find how many elements
        // in the right half satisfy the reverse pair condition.
        for(int i = s; i <= mid; i++){
            // Ensure no overflow by casting nums[i] and nums[right] to long long
            while(right <= e && (long long)nums[i] > 2 * (long long)nums[right]){
                right++; // Increment right pointer to find pairs
            }
            // Step 10: Add the count of valid pairs for this element
            cnt += (right - (mid + 1));
        }
        return cnt;
    }

    // Step 11: Perform merge sort and count reverse pairs
    int MergeSort(vector<int> &nums, int s, int e){
        int cnt = 0;
        if(s >= e) return cnt; // Base case: one or no elements in the subarray

        // Step 12: Find the midpoint of the current subarray
        int mid = s + (e - s) / 2;

        // Step 13: Recursively sort and count pairs in the left half
        cnt += MergeSort(nums, s, mid);

        // Step 14: Recursively sort and count pairs in the right half
        cnt += MergeSort(nums, mid + 1, e);

        // Step 15: Count the reverse pairs across the two halves
        cnt += countpairs(nums, s, mid, e);

        // Step 16: Merge the two halves in sorted order
        merge(nums, s, mid, e);

        return cnt;
    }

public:
    // Step 17: Public method to initiate the merge sort and return the total count
    int reversePairs(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;

        // Step 18: Call MergeSort to count reverse pairs and sort the array
        return MergeSort(nums, start, end);
    }
};

int main(){

return 0;
}