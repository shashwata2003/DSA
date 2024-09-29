/*
Q1:
Problem Statement



Given an array A of size N that contains only non-negative integers, find a continuous sub-array that adds to a given number S and return the left and right indexes of that sub-array. In the case of multiple subarrays, return the subarray indexes that come first when moving from left to right.



Note: Both the indexes in the array should be according to 1-based indexing. You have to return an array list consisting of two elements, left and right. If no such subarray exists, return an array consisting of element -1.



Example 1



Input:

N = 5, S = 12

A[5] = {1,2,3,7,5}

Output:

2 4

Explanation:

The sum of elements from the 2nd position to the 4th position is 12.



Example 2



Input:

N = 10, S = 15

A[10] = {1,2,3,4,5,6,7,8,9,10}

Output:

1 5

Explanation:

The sum of elements from the 1st position to the 5th position is 15.

Input format :
The first line of input consists of the length of the array, N.

The second line of input consists of the sum of the sub-arrays to be searched, S.

The third line of input consists of N space-separated array elements.

Output format :
The output prints two space-separated integers, representing the start and end index positions of the subarray respectively whose sum is S.

If no such subarray exists, return an array consisting of element -1.



Refer to the sample output for the formatting specifications.

Code constraints :
In this scenario, the test cases fall under the following constraints:

1 ≤ N ≤ 105

1 ≤ array elements ≤ 109

Sample test cases :
Input 1 :
5
12
1 2 3 7 5
Output 1 :
2 4
Input 2 :
10
15
1 2 3 4 5 6 7 8 9 10
Output 2 :
1 5
Input 3 :
3
22
1 4 5
Output 3 :
-1

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

﻿There is no subarray filled with 0. Therefore, we return 0.

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

Q3:
You are a software developer working for a grocery store chain. The store manager has asked you to create a tool to help track and identify a specific range of daily expenses that match a target budget. The manager wants to know if there is a continuous subarray of daily expenses that sums up exactly to the target budget, to analyze spending patterns and optimize budget allocations.



Given a list of daily expenses over a period of N days, your task is to write a program that identifies a continuous subarray of these expenses that sums up to a given target budget. If such a subarray exists, the program should output the 1-based indices of the starting and ending days of this subarray. If no such subarray is found, the program should indicate this.



Example 1



Input: 

5

1 2 3 7 5

12



Output: 

2 4



Explanation:

The sum of elements from the 2nd position to the 4th position is 12.



Example 2



Input:

10

1 2 3 4 5 6 7 8 9 10

15



Output:

1 5



Explanation:

The sum of elements from 1st position to 5th position is 15.



Example 3



Input

7

10 36 48 26 39 10 24

100



Output

No subarray found with the given sum



Explanation:

In this test case, there is no subarray whose elements sum up to 100. All possible combinations of subarrays are examined, but none of them have a sum equal to 100. Therefore, the output correctly indicates that no such subarray exists.



Company Tags: Microsoft

Input format :
The first line consists of an integer N representing the number of days.

The second line consists of an array of N integers where each integer represents the daily expense, separated by a space.

The third line consists of an integer S representing the target budget sum.

Output format :
The output displays one of the following:

The 1-based indices of the starting and ending days of the continuous subarray that sum to S.

If no such subarray exists, print "No subarray found with the given sum".



Refer to the sample output for the formatting specifications.

Code constraints :
1 ≤ N ≤ 10

1 ≤ daily expense ≤ 100

1 ≤ S ≤ 1000

Sample test cases :
Input 1 :
5
1 2 3 7 5
12
Output 1 :
2 4
Input 2 :
10
1 2 3 4 5 6 7 8 9 10
15
Output 2 :
1 5
Input 3 :
7
10 36 48 26 39 10 24
100
Output 3 :
No subarray found with the given sum

Q4:
Problem Statement



Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive. There is only one repeated number in nums, return this repeated number. You must solve the problem without modifying the array nums and using only constant extra space with linear time complexity.



Example

Input

5

1 3 4 2 2

Output

2



Input:

5

3 1 3 4 2

Output

3

Input format :
The first input consists of the array size.

The second input consists of the array elements.

Output format :
The output displays the duplicate element in array.



Refer to the sample output for the formatting specifications.

Code constraints :
1 ≤ n ≤ 105

nums.length = n + 1

1 ≤ nums[i] ≤ n

All the integers in nums appear only once except for precisely one integer which appears two or more times.

Sample test cases :
Input 1 :
5
1 3 4 2 2
Output 1 :
2
Input 2 :
5
3 1 3 4 2
Output 2 :
3

Q5:

Problem Statement



Given an array and a value x, write a program to find if there is a triplet in the array whose sum is equal to the given value. If there is such a triplet present in the array, print the triplet.



Example



Input:

array = {12, 3, 4, 1, 6, 9}, x = 24



Output: 

12 3 9



Explanation: 

There is a triplet (12, 3, and 9) present, whose sum is equal to the given value of 24.

Input format :
The first line of input consists of an integer n, representing the number of elements.

The second line of input consists of n integers arr[i], separated by space.

The third line of input consists of an integer x, representing the sum value.

Output format :
If there exists a triplet in the array A whose sum is equal to the sum, print the three integers separated by space.

If no such triplet exists, print "No triplet found with the given sum".



Refer to the sample output for the formatting specifications.

Code constraints :
1 ≤ n ≤ 20

1 ≤ arr[i] ≤ 100

1 ≤ x ≤ 200

Sample test cases :
Input 1 :
6
12 3 4 1 6 9
24
Output 1 :
12 3 9
Input 2 :
6
4 8 9 3 4 5
25
Output 2 :
No triplet found with 

Q6:
In the K-partition problem, we need to partition an array of positive integers into k-disjoint subsets that all have an equal sum and completely cover the set.



Example



Input:

9

7 5 2 6 6 1 8 9 4 

4

Output:

Partition 0 is 8 4 

Partition 1 is 2 1 9 

Partition 2 is 6 6 

Partition 3 is 7 5 

Input format :
The first line of input consists of an array size, N.

The second line consists of an array of elements separated by space.

The third line represents the value of k.

Output format :
The output prints the possible partitions that have an equal sum.



Refer to the sample output for the formatting specifications.

Sample test cases :
Input 1 :
9
7 5 2 6 6 1 8 9 4 
4
Output 1 :
Partition 0 is 8 4 
Partition 1 is 2 1 9 
Partition 2 is 6 6 
Partition 3 is 7 5 
Input 2 :
5
5 6 3 1 4 
3
Output 2 :
k-partition of set S is not possible
Note :

Q7:
Problem Statement



Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.



A subarray is a contiguous part of an array.



Example 1



Input: 

6

4 5 0 -2 -3 1

5



Output: 

7



Explanation:

There are 7 subarrays with a sum divisible by k = 5:

[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]



Example 2



Input:

1

5

9



Output:

0



Explanation:

The sum of elements from 1st position to 5th position is 15.

Input format :
The first line contains a single integer n, representing the size of the array nums.

The second line contains n space-separated integers arr[i], representing the elements of the array nums.

The third line contains a single integer k, representing the divisor.

Output format :
The output displays a single integer representing the number of subarrays in nums whose sum is divisible by k.



Refer to the sample output for the formatting specifications.

Code constraints :
1 ≤ n ≤ 10

1 ≤ arr[i] ≤100

1 ≤ k ≤ 1000

Sample test cases :
Input 1 :
6
4 5 0 -2 -3 1
5
Output 1 :
7
Input 2 :
1
5
9
Output 2 :
0

Q8:
Problem Statement



You are given an integer array of nums and an integer k. You want to find a subsequence of nums of length k that has the largest sum.



Return any such subsequence as an integer array of length k.



A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.



Example 1



Input: 

4

2 1 3 3 

2



Output: 

3 3 



Explanation:

The subsequence has the largest sum of 3 + 3 = 6.



Example 2



Input:

4

-1 -2 3 4

3



Output:

-1 3 4



Explanation:

The subsequence has the largest sum of -1 + 3 + 4 = 6.



Example 3



Input

4

3 4 3 3

2

Output

3 4 



Explanation:

The subsequence has the largest sum of 3 + 4 = 7. 

Another possible subsequence is [4, 3].



Company Tags: Google

Input format :
The first line contains an integer n, denoting the size of the array nums.

The second line contains n space-separated integers, representing the elements of the array a[i].

The third line contains an integer k, denoting the size of the subsequence to find.

Output format :
The output displays a single line containing k space-separated integers, representing the maximum subsequence.



Refer to the sample output for the formatting specifications.

Code constraints :
1 ≤ n ≤ 10

-100 ≤ a[i] ≤ 100

1 ≤ k ≤ 5

Sample test cases :
Input 1 :
4
2 1 3 3 
2
Output 1 :
3 3 
Input 2 :
4
-1 -2 3 4
3
Output 2 :
-1 3 4 
Input 3 :
4
3 4 3 3
2
Output 3 :
3 4 

Q9:
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

Q10:
Problem Statement



You are given a list of item prices in your store and a customer's gift card balance. Your task is to find a pair of items the customer can purchase, ensuring the total price matches the gift card balance. If such a pair exists, print the prices of the two items. If multiple pairs are possible, print the price of the first occurred pair.



Write a function that takes item prices, the number of available items, and the gift card balance as input. The function should determine if there's a valid pair of items whose prices sum to the gift card balance and, if so, print the prices of the first occurred pair of items.



If no valid pair of items is found, print "No combination of items."

Input format :
The first line of input consists of an integer, representing the number of items in the store.

The second line of input consists of an array of integers separated by a space, representing the prices of the items.

The last line of input consists of an integer representing the customer's gift card balance.

Output format :
If there exists a combination of items whose prices sum up to the gift card balance, then print this combination.

If no such combination exists, print "No combination of items".



Refer to the sample output for the formatting specifications.

Code constraints :
In this scenario, the given test cases will fall under the following constraints:

1 ≤ number of items ≤ 5

1 ≤ price ≤ 50

1 ≤ gift card balance ≤ 150

Sample test cases :
Input 1 :
3
10 20 30
50
Output 1 :
20 30
Input 2 :
4
10 15 20 30
58
Output 2 :
No combination of items
Input 3 :
4
3 5 7 5
10
Output 3 :
3 7

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

Q12:
Problem Statement:



Given an integer array nums, find the subarray with the largest sum, and return its sum.



Example 1:



Input: n=9

nums = [-2,1,-3,4,-1,2,1,-5,4]

Output: 6

Explanation: The subarray [4,-1,2,1] has the largest sum 6.



Example 2:



Input: n=1 

nums = [1]

Output: 1

Explanation: The subarray [1] has the largest sum of 1.



Example 3:



Input: n=5 

nums = [5,4,-1,7,8]

Output: 23

Explanation: The subarray [5,4,-1,7,8] has the largest sum of 23.

Input format :
The first line consists of an integer n, representing the number of elements in the array nums.

The second line consists of n space-separated integers, representing the elements of the array nums.

Output format :
The output prints an integer, representing the sum of the subarray with the largest sum.



Refer to the sample output for formatting specifications.

Code constraints :
1 ≤ n ≤ 20

-100 ≤ nums[i] ≤ 100

Sample test cases :
Input 1 :
9
-2 1 -3 4 -1 2 1 -5 4
Output 1 :
6
Input 2 :
1
1
Output 2 :
1
Input 3 :
5
5 4 -1 7 8
Output 3 :
23


*/