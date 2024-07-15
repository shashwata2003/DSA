#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Chocolate Distribution Problem:
Given an array A[ ] of positive integers of size N, where each value represents the number of chocolates 
in a packet. Each packet can have a variable number of chocolates. There are M students, the task is to 
distribute chocolate packets among M students such that :
1. Each student gets exactly one packet.
2. The difference between maximum number of chocolates given to a student and minimum number of chocolates given to a student is minimum.

Example 1:

Input:
N = 8, M = 5
A = {3, 4, 1, 9, 56, 7, 9, 12}
Output: 6
Explanation: The minimum difference between maximum chocolates and minimum chocolates is 9 - 3 = 6 
by choosing following M packets :{3, 4, 9, 7, 9}.

Example 2:
Input:
N = 7, M = 3
A = {7, 3, 2, 4, 9, 12, 56}
Output: 2
Explanation: The minimum difference between maximum chocolates and minimum chocolates is 4 - 2 = 2 by 
choosing following M packets :{3, 2, 4}.

STEPS:
Follow the steps mentioned below to implement the approach:

Initially sort the given array. And declare a variable to store the minimum difference, and initialize it to INT_MAX. Let the variable be min_diff.
Find the subarray of size m such that the difference between the last (maximum in case of sorted) and first (minimum in case of sorted) elements of the subarray is minimum.
We will run a loop from 0 to (n-m), where n is the size of the given array and m is the size of the subarray.
We will calculate the maximum difference with the subarray and store it in diff = arr[highest index] – arr[lowest index]
Whenever we get a diff less than the min_diff, we will update the min_diff with diff.

NOTE:
so we are assuming to giving the first m chocolate to the m kids and then taking the first element which 
will be the lowest and the right most i+m-1 element will be the largest and storing the difference in the 
variable,
Doing the same till the end to find the min
 */

int minchoco(vector<int> arr, int n, int m){
    if(n<m){
        return -1;
    }
    if(n==0 || m == 0){
        return 0;
    }
    int mini = INT_MAX;
    sort(arr.begin(),arr.end());
    for (int i = 0; i+m-1 < n; i++)
    {
        if(arr[i+m-1] - arr[i] < mini){
            mini = arr[i+m-1] - arr[i];
        }
    }
    return mini;
}

int main(){
    vector<int> arr = {7, 3, 2, 4, 9, 12, 56};
    int n = arr.size();
    int m = 3;
    cout<<minchoco(arr,n,m);
return 0;
}