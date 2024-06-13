#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Code Studio: Search in a Rotated Array:
Given a Roated array like : [7,9,1,2,3] we need to find the key value in this array:
sol:
Here also if we plot the array in a grapg we will get two climbing lines one higher and one at the lower end.
Now to use the binary search we need to find find in which climb the key exists. 
So to do so we can find the pivot element and find weather the key exist in the lower climb by using 
arr[pivot]<= target <=arr[e];
if yes then apply Binary search on this and find the key 
else it will on the higher climb.
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

int BinarySearch(int arr[], int key,int st , int en){
    int s = st;
    int e = en;
    int mid = (s+e)/2;
    while (s<=e)
    {
        if(arr[mid] == key){
            return mid;
        }
        if(arr[mid]<key){
            s=mid+1;
        }else{
            e = mid -1;
        }
        mid = (s+e)/2;
    }
    return -1;
}

int FindPosition(int arr[],int size,int key){
    int pivot = FindPIvot(arr,size);
    int ans;
    if(arr[pivot]<=key && arr[size-1]>=key){
        ans = BinarySearch(arr,key,pivot,size-1);
    }else{
        ans = BinarySearch(arr,key,0,pivot-1);
    }
    return ans;
}

int main(){
    int arr[7] = {7,9,1,2,3,5,6};
    cout<<FindPosition(arr,7,5);
return 0;
}