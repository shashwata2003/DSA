#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

Since the result may be very large, so you need to return a string instead of an integer.

 

Example 1:

Input: nums = [10,2]
Output: "210"
Example 2:

Input: nums = [3,30,34,5,9]
Output: "9534330"

 */

class Solution {
private:
    // Comparator function to decide the order of concatenation
    // We compare the concatenation of a + b and b + a, and return true if a + b is larger
    static bool greater(string &a, string &b) {
        return a + b > b + a;
    }

public:
    // Function to form the largest number by concatenating the integers in nums
    string largestNumber(vector<int>& nums) {
        vector<string> stringnums;

        // Convert each integer in nums to its string representation
        for (int i : nums) {
            stringnums.push_back(to_string(i));
        }

        // Sort the strings based on the custom comparator `greater`
        sort(stringnums.begin(), stringnums.end(), greater);

        // Edge case: If the largest number is "0", then the whole number is 0
        if (stringnums[0] == "0") {
            return "0";
        }

        // Concatenate all the strings to form the largest number
        string ans = "";
        for (string i : stringnums) {
            ans += i;
        }

        // Return the final concatenated result
        return ans;
    }
};

int main(){

return 0;
}