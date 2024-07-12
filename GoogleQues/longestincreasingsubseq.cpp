#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Longest increasing subsequend:
Given an array we need to find the length of the longest increasing subsequence in that arr.

eg:
{1,3,5,4,7}
ans: 3
 */

int longestincresing(vector<int> arr, int n){
    int curr = 1;
    int maxi = 1;
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    for(int i = 1; i<n;i++){
        if(arr[i]> arr[i-1]){
            curr++;
        }else{
            curr = 1;
        }
        maxi = max(maxi,curr); 
    }
    return maxi;
}

int main(){
    vector<int> arr = {1,2,3,4,5,1,2,3,4,5,4,7};
    int n = arr.size();
    cout<<longestincresing(arr,n);
return 0;
}