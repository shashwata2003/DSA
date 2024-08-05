#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Given an array A[ ] of positive integers of size N, where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. There are M students, the task is to distribute chocolate packets among M students such that :
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
 */

long long findMinDiff(vector<long long> a, long long n, long long m){
    sort(a.begin(),a.end());

    int i = 0;
    int j = m -1;

    int mini = INT_MAX;
    while (j<a.size())
    {
       int diff = a[j]-a[i];
       mini = min(mini,diff);
       i++;
       j++;
    }
    return mini;
} 

int main(){
    long long  N = 7, M = 3;
    vector<long long> A = {7, 3, 2, 4, 9, 12, 56};
    cout<<findMinDiff(A,N,M);
    return 0;
}