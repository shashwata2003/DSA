#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
In a sorted array find the Pivot element:
Given a array like [7,9,1,2,3] (this is a roated array)if we plot this on a grph we will find that there will be a a large down slop
between 9 and 1 which is called a pivot. Hence the pivot element are 9 and 1. In here we will conside 1 as the
pivot element.
Sol: As we are going to use binary search we need to first find the mid. Now will the value of mid we have 2
conditions.
1. if arr[mid]>=arr[0] this is on the climbing slope hence we need to move the start pointer. S=mid+1;
2. now the else condition will be on the lower climbing slope hence we will move the end pointer e = mid
(not mid -1 because of the same reason as the last question).
 */
int FindPIvot(int arr[],int size){
    int s = 0;
    int e = size - 1;
    int mid = s +(e-s)/2;
    while (s<e)
    {
    if (arr[mid]>=arr[0])
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
    int arr[5] = {7,9,1,2,3};
    cout<<FindPIvot(arr,5);
return 0;
}