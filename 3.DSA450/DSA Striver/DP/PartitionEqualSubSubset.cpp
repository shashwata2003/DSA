#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  Partition Equal Subset Sum:
Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.

Example 1:

Input: N = 4
arr = {1, 5, 11, 5}
Output: YES
Explanation: 
The two parts are {1, 5, 5} and {11}.
Example 2:

Input: N = 3
arr = {1, 3, 5}
Output: NO
Explanation: This array can never be 
partitioned into two such parts.
*/

    int solve(int n, int arr[], int target, int index) {
        if (target < 0) {
            return 0;
        }
        if (target == 0) {
            return 1;
        }
        if (index >= n) {
            return 0;
        }

        int inclu = solve(n, arr, target - arr[index], index + 1);
        int exclu = solve(n, arr, target, index + 1);
        return inclu + exclu;
    }

    int equalPartition(int N, int arr[]) {
        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += arr[i];
        }
        if (sum % 2 != 0) {
            return 0;
        }
        int target = sum / 2;
        int index = 0;
        int ans = solve(N, arr, target, index);
        return ans > 0 ? 1 : 0; // Return 1 if a valid partition is found, otherwise 0
    }

int main(){

return 0;
}