#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Code Studio: Book Allocation Problem: 
We are given a array of size n. In that array it represents each books with no. of pages in it. also we are given 
m = no. of student. we need to assign this book to m students in continuous manner such that all m students get 
a book. The array may be unstored
eg: arr=[10,20,30,40] m = 2 and n = 4
Now this book can be divided in to two parts like {10}{20,30,40},{10,20}{30,40},{10,20,30}{40}
Now find the sum of each set like: (10,90),(30,70),(60,40) -> max of each set{90,70,60 } -> min of this set {60}
hence 60 is the ans(This is max no. of pages assigned  to a student is minimum).
Sol in Note Book 
 */

bool isPossible(vector<int> arr,int n,int m, int mid){
    int studentCount = 1;
    int pageCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (pageCount + arr[i] <= mid)
        {
                pageCount = pageCount +arr[i];
        }else
        {
            studentCount++;
            if (studentCount > m || arr[i] > mid)
            {
                return false;
            }
            pageCount = arr[i];
            
        }   
    }
    return true;
}


int allocateBook(vector<int> arr,int n, int m){
    int s = 0;
    int sum =0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum=sum+arr[i];
    }
    int e = sum;
    int mid = s+(e-s)/2;
    int ans = - 1;
    while (s<=e)
    {
        if (isPossible(arr,n,m,mid))
        {
            ans = mid;
            e= mid -1;
        }else
        {
            s=mid+1;
        }
        mid = s+(e-s)/2;
    }
    return ans;
}

int main(){
    vector<int> arr = {10,20,30,40};
    int m = 2;
    int n = arr.size();
    cout<<allocateBook(arr,n,m);
return 0;
}