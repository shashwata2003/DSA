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

#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  */
int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int l = 0;
    int r = 0;
    int maxele = 0;
    vector<int> ans;
    while(r<k){
        maxele = max(maxele,arr[r]);
        r++;
    }
    ans.push_back(maxele);
    while(r<n){
        maxele = max(maxele,arr[r]);
        ans.push_back(maxele);
        r++;
        l++;
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
return 0;
}