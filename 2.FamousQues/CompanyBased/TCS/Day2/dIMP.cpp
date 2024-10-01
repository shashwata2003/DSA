/*
Q2:
Problem Statement
Given an integer array nums, return the number of subarrays filled with 0.
A subarray is a contiguous non-empty sequence of elements within an array.
Example 1

Input: 
8
1 3 0 0 2 0 0 4
Output: 
6
Explanation:
There are 4 occurrences of [0] as a subarray.
There are 2 occurrences of [0,0] as a subarray.
There is no occurrence of a subarray with a size more than 2 filled with 0. Therefore, we return 6.

Example 2

Input:
6
0 0 0 2 0 0

Output:
9
Explanation:
There are 5 occurrences of [0] as a subarray.
There are 3 occurrences of [0,0] as a subarray.
There is 1 occurrence of [0,0,0] as a subarray.
There is no occurrence of a subarray with a size more than 3 filled with 0. Therefore, we return 9.

Example 3

Input
3
2 10 2019
Output
0
Explanation:
There is no subarray filled with 0. Therefore, we return 0.
Input format :
The first line contains a single integer n, representing the size of the array nums.
The second line contains n space-separated integers arr[i], representing the elements of the array nums.
Output format :
The output displays a single integer representing the number of subarrays in nums that consist entirely of zeros.

Refer to the sample output for the formatting specifications.
Code constraints :
1 ≤ n ≤ 10
0 ≤ arr[i] ≤100
Sample test cases :
Input 1 :
8
1 3 0 0 2 0 0 4
Output 1 :
6
Input 2 :
6
0 0 0 2 0 0
Output 2 :
9
Input 3 :
3
2 10 2019
Output 3 :
0
*/
#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int cnt = 0;
    int l = 0, r = 0;

    while (r < n) {
        if (arr[r] == 0) {
            r++; // Extend the right boundary of the subarray
        } else {
            // Count subarrays for the block of 0's between l and r-1
            int sizecnt = r - l;
            if (sizecnt > 0) {
                cnt += (sizecnt * (sizecnt + 1)) / 2; // Count all subarrays of 0's
            }
            r++; // Move past the non-zero element
            l = r; // Set l to the new starting point
        }
    }

    // Handle the case where the array ends with a block of 0's
    if (arr[n - 1] == 0) {
        int sizecnt = r - l;
        if (sizecnt > 0) {
            cnt += (sizecnt * (sizecnt + 1)) / 2;
        }
    }

    cout << cnt << endl;
    return 0;
}
