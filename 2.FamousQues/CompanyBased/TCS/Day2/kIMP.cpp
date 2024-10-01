/*Q9:
Problem Statement
Given an array of positive integer nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to the target. If there is no such subarray, return 0 instead.
Example 1
Input: 
7
6
2 3 1 2 4 3

Output:
2

Explanation:
The subarray [4,3] has a minimal length under the problem constraint.

Example 2
Input:
11
8
1 1 1 1 1 1 1 1
Output:
0



Explanation:
In this case, there is no subarray whose sum is at least 11. Thus, the output is 0.



Example 3



Input:

4

3

1 4 4 



Output:

1



Explanation:

In this case, the minimal subarray with a sum of at least 4 is [4], with a length of 1.

Input format :
The first line contains an integer target T, representing the target sum.

The second line contains an integer n, indicating the number of elements in the array.

The third line contains n space-separated integers arr[i], representing the elements of the array nums.

Output format :
The output displays an integer representing the minimal length of a contiguous subarray of nums whose sum is at least target.



Refer to the sample output for the formatting specifications.

Code constraints :
1 ≤ T ≤ 100

1 ≤ n ≤ 10

1 ≤ arr[i] ≤1000

Sample test cases :
Input 1 :
7
6
2 3 1 2 4 3
Output 1 :
2
Input 2 :
11
8
1 1 1 1 1 1 1 1
Output 2 :
0
Input 3 :
4
3
1 4 4 
Output 3 :
1
*/

#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  */
int main() {
    int n, t;
    cin >> t;  // Target sum
    cin >> n;  // Size of the array

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int l = 0, r = 0;
    int sum = 0;
    int minlen = INT_MAX;

    while (r < n) {
        sum += arr[r];

        // Shrink the window when sum >= t
        while (sum >= t) {
            if (sum == t) {
                minlen = min(minlen, r - l + 1);
            }
            sum -= arr[l];
            l++;
        }
        r++;
    }

    // If no subarray is found, return -1
    if (minlen == INT_MAX) {
        cout << -1;
    } else {
        cout << minlen;
    }

    return 0;
}