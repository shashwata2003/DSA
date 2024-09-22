/*
Questions1:
Given a sequence of numbers in an array A. The task is to break short the array such the twice minimum value in the array should be greater than the maximum value in the array. The number of values removed from the array should be minimal. The removal of elements from the array can be done from the start or from the end of the array as per the condition mentioned above.

Input format :
The first line contains a single integer n, which represents the number of integers in the list.

The second set of input contains n integers on n lines, which represents the list of elements.

Output format :
The output consists of a single integer, which represents the minimum number of elements that need to be removed from the list to make the remaining elements in the list satisfy the condition that the minimum element is at least half of the maximum element.



Refer to the sample output for formatting specifications.

Sample test cases :
Input 1 :
7
2 
4 
5 
6 
8 
9 
1
Output 1 :
3
Input 2 :
4
4
7
5
6
Output 2 :
0
*/

/*Question 2:
You have planned your visits to a recreational park one year in advance. The days of the year on which you will visit the park are given as an integer array visitDays. Each day is an integer from 1 to 365. 



Membership passes for the park are sold in three different ways:

A 1-day pass is sold for membershipCosts[0] dollars.
A 7-day pass is sold for membershipCosts[1] dollars.
A 30-day pass is sold for membershipCosts[2] dollars.


The passes allow that many days of consecutive park visits. For example, if you get a 7-day pass on day 2, you can visit the park for 7 days: 2, 3, 4, 5, 6, 7, 8. 



Return the minimum number of dollars you need to spend to cover all your planned park visits given in the list visitDays.



Example 



Input:

visitDays = {1, 4, 6, 7, 8, 20}

membershipCosts = {2, 7, 15}

Output: 

11

Explanation: 

Here is one way to buy passes that cover your visit plan:

On day 1, you buy a 1-day pass for membershipCosts[0] = $2, which covers day 1.

On day 3, you buy a 7-day pass for membershipCosts[1] = $7, which covers days 3, 4, ..., 9.

On day 20, you buy a 1-day pass for membershipCosts[0] = $2, which covers day 20.

In total, you spent $11 and covered all the days of your park visits.



Company Tags: Google, Microsoft

Input format :
The first line of input consists of an integer N, representing the number of days planned to visit the park.

The second line consists of N integers, each representing visiting days, in strictly increasing order.

The third line consists of three space-separated integers, representing the membership cost of 1-day, 7-day, and 30-day passes, respectively.

Output format :
The output prints the minimum number of dollars that need to be spent to cover all the planned park visits.



Refer to the sample output for formatting specifications.

Code constraints :
1 ≤ N ≤ 365

1 ≤ visiting days ≤ 365

1 ≤ membershipCosts[i] ≤ 1000

Sample test cases :
Input 1 :
6
1 4 6 7 8 20
2 7 15
Output 1 :
11
Input 2 :
12
1 2 3 4 5 6 7 8 9 10 30 31
2 7 15
Output 2 :
17
*/

/*
Question 3:
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.



Return the max sliding window.



Example 1:

Input: n=8

nums = [1,3,-1,-3,5,3,6,7], k = 3

Output: [3,3,5,5,6,7]



Explanation:





Example 2:

Input:n=1

nums = [1], k = 1

Output: [1]

Input format :
The first line contains an integer n, the number of elements in the array.

The second line contains n space-separated integers, representing the elements of the array nums.

The third line contains an integer k, the size of the sliding window.

Output format :
A single line containing the space-separated integers representing the maximum sliding window.



Refer to the sample output for formatting specifications.

Code constraints :
1 ≤ n ≤ 100

1 ≤ nums[i] ≤ 100

1 ≤ k ≤ n

Sample test cases :
Input 1 :
8
1 3 -1 -3 5 3 6 7
3
Output 1 :
3 3 5 5 6 7 
Input 2 :
1
1
1
Output 2 :
1 
*/

/*
Consider an event where a log register is maintained containing the guest’s arrival and departure times. Given an array of arrival and departure times from entries in the log register, find the point when there were the most guests present at the event.



Note: If an arrival and departure event coincide, the arrival time is preferred over the departure time.



Example:

Input:

arrival = { 1, 2, 4, 7, 8, 12 }

departure = { 2, 7, 8, 12, 10, 15 }



Output: Maximum number of guests is 3, present at time 7



Explanation:

Maximum Overlapping Interval

Input format :
The first line of input contains an integer value 'n', representing the number of guests.

The second line of input consists of n integers representing the arrival time of each guest.

The third line of input is an integer value 'm', which represents the number of guests for departure.

The fourth line of input consists of m integers representing the departure time of each guest.

Output format :
The first line of the output displays the maximum number of guests present at any time.

The second line of the output displays the time when the maximum number of guests are present.



Refer to the sample output for the formatting specifications.

Code constraints :
1 ≤ n ≤ 10

1 ≤ m ≤ 10

Sample test cases :
Input 1 :
6
5 2 3 7 8 9
6
1 2 3 5 6 7
Output 1 :
2
1
Input 2 :
6
1 2 4 7 8 12
6
2 7 8 12 10 15
Output 2 :
7
3
Expected Time Complexity : O(1)
Expected Space Complexity : O(1)
*/