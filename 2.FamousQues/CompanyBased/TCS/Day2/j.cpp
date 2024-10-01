#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 

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


 */
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int t;
    cin>>t;
    sort(arr.begin(),arr.end());
    for (int i = (n-t); i < (n); i++)
    {
        cout<<arr[i]<<" ";
    }
    
    
return 0;
}