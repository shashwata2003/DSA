#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
 
 */
/* 
How to identify if a number can be the starting number for a sequence:
    1.First, we will put all the array elements into the set data structure.
    2.If a number, num, is a starting number, ideally, num-1 should not exist. So, for every element, x, in the set,  we will check if x-1 exists inside the set. :
    3.If x-1 exists: This means x cannot be a starting number and we will move on to the next element in the set.
    4.If x-1 does not exist: This means x is a starting number of a sequence. So, for number, x, we will start finding the consecutive elements.

How to search for consecutive elements for a number, x:
    Instead of using linear search, we will use the set data structure itself to search for the elements x+1, x+2, x+3, and so on.
 */

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Create a hash set to store all the numbers from the input array
        unordered_set<int> st;
        int n = nums.size();
        
        // Insert each number from the input array into the set
        for (int i : nums) {
            st.insert(i);
        }
        
        int ans = 0; // Variable to store the length of the longest consecutive sequence
        
        // Iterate through each number in the array
        for (int i : nums) {
            // Check if the current number is the start of a sequence
            // If i-1 is not in the set, it means i is the smallest number in the sequence
            if (st.find(i - 1) == st.end()) {
                // Initialize count to track the length of the consecutive sequence
                int cnt = 1;
                
                // Continue finding the next consecutive numbers in the sequence
                while (st.find(i + 1) != st.end()) {
                    cnt++;  // Increment count for each consecutive number found
                    i++;    // Move to the next number in the sequence
                }
                
                // Update the maximum length of consecutive sequences found so far
                ans = max(ans, cnt);
            }
        }
        
        // Return the length of the longest consecutive sequence
        return ans;
    }
};



int main(){

return 0;
}