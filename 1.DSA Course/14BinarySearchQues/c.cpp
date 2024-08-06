#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Square Root: Given a int n find the square root of it using binary search.
eg n = 25 ans = 5 
sol: There are two approaches to this 
1. Using brute force o(root n) given n, run a loop till n and check if sq of one of them is equal to n 
2. Using binary Search : Given n , we know that the ans will be in between 0 to n hence we need to use Binary
Search to find that ans.
 */

// This code may cause some issue if the int value is too long hence we need to use long long int 
int BinarySearch(int n){
    int s = 0;
    int e = n;
    long long int mid = (s+e)/2;
    long long int ans  = -1;
    while (s<=e)
    {
        if(mid * mid == n){
            return mid;
        }
        if(mid * mid<n){
            ans = mid;
            s=mid+1;
        }else{
            e = mid -1;
        }
        mid = (s+e)/2;
    }
    return ans;
}
int main(){
    int n = 8;
    cout<<BinarySearch(n)<<endl;
return 0;
}