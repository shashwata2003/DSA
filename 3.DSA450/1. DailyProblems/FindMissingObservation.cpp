#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
You have observations of n + m 6-sided dice rolls with each face numbered from 1 to 6. n of the observations 
went missing, and you only have the observations of m rolls. Fortunately, you have also calculated the average 
value of the n + m rolls.

You are given an integer array rolls of length m where rolls[i] is the value of the ith observation. You are 
also given the two integers mean and n.

Return an array of length n containing the missing observations such that the average value of the n + m rolls
is exactly mean. If there are multiple valid answers, return any of them. If no such array exists, return an 
empty array.

The average value of a set of k numbers is the sum of the numbers divided by k.

Note that mean is an integer, so the sum of the n + m rolls should be divisible by n + m.

 

Example 1:

Input: rolls = [3,2,4,3], mean = 4, n = 2
Output: [6,6]
Explanation: The mean of all n + m rolls is (3 + 2 + 4 + 3 + 6 + 6) / 6 = 4.
Example 2:

Input: rolls = [1,5,6], mean = 3, n = 4
Output: [2,3,2,2]
Explanation: The mean of all n + m rolls is (1 + 5 + 6 + 2 + 3 + 2 + 2) / 7 = 3.
Example 3:

Input: rolls = [1,2,3,4], mean = 6, n = 4
Output: []
Explanation: It is impossible for the mean to be 6 no matter what the 4 missing rolls are.
 */

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sumofm = accumulate(rolls.begin(), rolls.end(), 0); // Sum of the given rolls
        int total = rolls.size() + n; // Total number of rolls
        int resultsum = (mean * total) - sumofm; // Total sum needed for missing rolls
        vector<int> res;
        // Check if resultsum is within the valid range for 'n' rolls (1 to 6 per roll)
        if (resultsum < n || resultsum > 6 * n) {
            return res; // Impossible to achieve
        }

        vector<int> ans(n, 1); // Initialize with the minimum possible value (1)
        int remaining = resultsum - n; // Remaining sum to distribute

        // Distribute the remaining sum
        for (int i = 0; i < n && remaining > 0; i++) {
            int increment = min(remaining, 5); // We can increment up to 5 (since 6 - 1 = 5)
            ans[i] += increment;
            remaining -= increment;
        }

        return ans; // Return the resulting vector
    }
};


int main(){

return 0;
}