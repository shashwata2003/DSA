#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
CodeStudio: Aggresive Cows:
You are given an array 'arr' consisting of 'n' integers which denote the position of a stall.
You are also given an integer 'k' which denotes the number of aggressive cows.
You are given the task of assigning stalls to 'k' cows such that the minimum distance between any
 two of them is the maximum possible.
Print the maximum possible minimum distance.
eg : arr[4,2,1,3,6]
ans : 5 
We need to place cow 1 and cow 2 at such position the distance between them is max.
 */

bool isPossible(vector<int> arr,int n,int m, int mid){
    int cowcount = 1;
    int lastpos = arr[0];
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i]-lastpos >= mid)
        {
            cowcount++;
            if (cowcount == m)  
            {
                return true;
            }
            lastpos = arr[i];
            
        }
        
    }
    return false;
    
}


int allocateCows(vector<int> arr,int n, int m){
    sort(arr.begin(),arr.end());
    int s = 0;
    int maxi = -1;
    for (int i = 0; i < arr.size(); i++)
    {
        maxi = max(maxi,arr[i]);
    }
    int e = maxi;
    int mid = s+(e-s)/2;
    int ans = - 1;
    while (s<=e)
    {
        if (isPossible(arr,n,m,mid))
        {
            ans = mid;
            s= mid +1;
        }else
        {
            e=mid-1;
        }
        mid = s+(e-s)/2;
    }
    return ans;
}

int main(){
    vector<int> arr = {4,2,1,3,6};
    int m = 2;
    int n = arr.size();
    cout<<allocateCows(arr,n,m);
return 0;
}