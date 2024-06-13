#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Given an array/list of length ‘n’, where the array/list represents the boards and each element of the given 
array/list represents the length of each board. Some ‘k’ numbers of painters are available to paint these boards. 
Consider that each unit of a board takes 1 unit of time to paint.
You are supposed to return the area of the minimum time to get this job done of painting all the ‘n’ 
boards under a constraint that any painter will only paint the continuous sections of boards.
Example :
Input: arr = [2, 1, 5, 6, 2, 3], k = 2
Output: 11

Sol: This is exactly same as the last question done called the allocate books please check that solution.
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


int allocatePainters(vector<int> arr,int n, int m){
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
    vector<int> arr = {5,5,5,5};
    int m = 2;
    int n = arr.size();
    cout<<allocatePainters(arr,n,m);
return 0;
}