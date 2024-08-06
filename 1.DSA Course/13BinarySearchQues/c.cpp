#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Code studio : peak index in moutain array.
Given a mountain array i.e. [1,2,3,1] when we plot this array in a graph it forms a mountain. other eg: 5,10,7,2
Now in this kind of array we need to find the peak of the moutain. ie is the index of the largest of the array.
eg: [1,2,3,1] ans 2
Sol: 1. Linear search appoarch. o(n)
2. Binary Seacrch o(nlogn):
First find the mid value. now after getting the mid value we have only three condition:
1. mid < mid+1 hence the we are no the climbing side of the mountain. hence movw s = mid+1;
2. else mid = peak then move the e  = mid ;not mid - 1 because this will cause us to move 
the the climbing side of the mountain
we are not checking this mid>mid+1 condition because this will be true if mid<m+1 is false hence we can directly
use else and e = mid because ot to lead it to the vlimbing slide.
 */
int FindPeak(int arr[],int size){
    int s = 0;
    int e = size - 1;
    int mid = s +(e-s)/2;
    while (s<e)
    {
    if (arr[mid]<arr[mid+1])
    {
        s=mid+1;
    }
    else{
        e = mid;
    }
    mid = s+(e-s)/2;
    }
    
    return s;
}

int main(){
int arr[4] = {1,2,3,1};
cout<<FindPeak(arr,4)<<endl;
return 0;
}