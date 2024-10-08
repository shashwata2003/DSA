#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Given a list of non-negative integers, find the minimum number of merge operations to make it a palindrome. A merge operation can only be performed on two adjacent elements. The result of a merge operation is that the two adjacent columns are replaced with their sum. 



To make any array a palindrome, we can simply apply the merge operation n-1 times, where n is the size of the array (because a single-element array is always palindromic, similar to a single-character string). In that case, the size of the array will be reduced to 1.

https://www.geeksforgeeks.org/find-minimum-number-of-merge-operations-to-make-an-array-palindrome/
 */



// You are using GCC
#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    
    int l = 0;
    int r = n-1;
    int cnt = 0;
    while(l<r){
        if(arr[l] == arr[r]){
            l++;
            r--;
        }
        else if(arr[l]>arr[r]){
            r--;
            arr[r] = arr[r]+arr[r+1];
            cnt++;
        }
        else{
            l++;
            arr[l] = arr[l] + arr[l-1];
            cnt++;
        }
    }
    cout<<cnt;
}