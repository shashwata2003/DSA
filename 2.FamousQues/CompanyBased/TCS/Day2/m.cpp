/*

Q11:
Problem Statement



You are given an array nums consisting of positive integers.



We call a subarray of nums nice if the bitwise AND of every pair of elements in different positions is equal to 0. Return the length of the longest nice subarray. A subarray is a contiguous part of an array.



Note that subarrays of length 1 are always considered nice.



Example 1



Input: 

5

1 3 8 48 10



Output: 

3



Explanation:

The longest nice subarray is [3,8,48]. This subarray satisfies the conditions:

- 3 AND 8 = 0.

- 3 AND 48 = 0.

- 8 AND 48 = 0.

It can be proven that no longer nice subarray can be obtained, so we return 3.



Example 2



Input:

5

3 1 5 11 13



Output:

1



Explanation:

The length of the longest nice subarray is 1. Any subarray of length 1 can be chosen.

Input format :
The first line contains an integer N representing the size of the array.

The second line contains N space-separated integers arr[i], representing the elements of the array.

Output format :
The output displays a single integer, the length of the longest nice subarray.



Refer to the sample output for the formatting specifications.

Code constraints :
1 ≤ N ≤ 10

1 ≤ arr[i] ≤100

Sample test cases :
Input 1 :
5
1 3 8 48 10
Output 1 :
3
Input 2 :
5
3 1 5 11 13
Output 2 :
1

*/