#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* Fruit Into Baskets

You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array of arr[], where arr[i]  is the type of fruit the ith tree produces.
You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow :

You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of the baskets.
Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
Given the integer array of fruits, return the maximum number of fruits you can pick.

Examples:

Input: arr[]= [2, 1, 2]
Output: 3
Explanation: We can pick one fruit from all three trees. Please note that the type of fruits is same in the 1st and 3rd baskets.
Input: arr[] = [3, 1, 2, 2, 2, 2]
Output: 5
Explanation: It's optimal to pick from the last 5 trees. Please note that we do not pick the first basket as we would have to stop at thrid tree which would result in only 2 fruits collected.
 */
class Solution {
  public:
    int totalFruits(vector<int> &arr) {
        unordered_map<int, int> mp;
        int l = 0;
        int r = 0;
        int n = arr.size();
        int ans = 0;

        while (r < n) {
            mp[arr[r]]++;  // Increment the count of the fruit at position r

            // If we have more than 2 distinct fruits, shrink the window from the left
            if (mp.size() > 2) {
                while (mp.size() > 2) {
                    mp[arr[l]]--;  // Decrease the count of the fruit at position l
                    if (mp[arr[l]] == 0) {
                        mp.erase(arr[l]);  // Remove the fruit if its count becomes 0
                    }
                    l++;  // Shrink the window
                }
            }

            // Update the result for the longest subarray with at most 2 distinct fruits
            ans = max(ans, r - l + 1);
            r++;  // Expand the window by moving the right pointer
        }

        return ans;
    }
};

int main(){

return 0;
}