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
*/
#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  */

void findindexesofthesubarray(vector<int> &arr, int n, int t){
    unordered_map<int,vector<int>> mp;
    int currsum = 0;
    mp[0].push_back(-1);
    for(int i = 0; i<n; i++){
        currsum += arr[i];
        if(mp.find(currsum - t) != mp.end()){
            for(int j : mp[currsum - t]){
                cout<<"starts form "<< j+1+1 <<" to "<<i+1<<endl;
            } 
            break;
        }
        mp[currsum].push_back(i);
    }
}

int main(){
    int n,t;
    cin>>n>>t;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    findindexesofthesubarray(arr,n,t);
    
return 0;
}