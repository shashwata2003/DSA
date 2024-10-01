/*
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
 */

#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  */
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    
    // Input array elements
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    unordered_map<int,int> mp;
    for(int i : arr){
        mp[i]++;
        if(mp[i]>1){
            cout<<i;
            return 0;
        }
    }
return 0;
}