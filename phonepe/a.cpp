#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Possible to form a triangle from array values
Given an array of integers, we need to find out whether it is possible to construct at least one 
non-degenerate triangle using array values as its sides. In other words, we need to find out 3 such array 
indices which can become sides of a non-degenerate triangle. 

eg:
Input : [4, 1, 2]
Output : No 
No triangle is possible from given
array values

Input : [5, 4, 3, 1, 2]
Output : Yes
Sides of possible triangle are 2 3 4

A + B > C    and     
B + C > A    and
C + A > B
where A, B and C are length of sides of the triangle.
 */

bool checktriangle(vector<int> arr, int n){
    if(n < n){
        return false;
    }
    sort(arr.begin(),arr.end());
    for (int i = 0; i < n-2; i++)
    {
        if(arr[i] + arr[i+1] > arr[i+2]){
            return true;
        }
    }
    return false;
}

int main(){
    vector<int> arr = {4, 1, 2};
    int n = arr.size();
    cout<<checktriangle(arr,n);
return 0;
}

