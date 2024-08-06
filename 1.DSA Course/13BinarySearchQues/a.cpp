#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* Code Studio: First and last position of a sorted array:
Given a Arr and a key value we need to find the keys leftmost and the right most occurance in the array.There are
duplicates in the array.
eg: [0,1,1,5]  k = 1 ans : 1 and 2 left and right most occurances.
we are given are sorted array.
Ans:
First to find the Left occurance of the key. We need to update only one condition that is when mid == key 
then store the mid and check the left side of the mid hence end= mid - 1.

 */
int FirstInstance(int arr[],int size, int key){
    int s = 0;
    int e = size-1;
    int mid = s+(e-s)/2;
    int ans = 0;
    while (s<=e)
    {
        if(arr[mid] == key){
            ans = mid;
            s = mid - 1;
        }
        if(arr[mid]<key){
            s=mid+1;
        }else{
            e = mid -1;
        }
        mid = s+(e-s)/2;
    }
    return ans;
}

int SecondInstance(int arr[],int size, int key){
    int s = 0;
    int e = size-1;
    int mid = s+(e-s)/2;
    int ans = 0;
    while (s<=e)
    {
        if(arr[mid] == key){
            ans = mid;
            s = mid + 1;
        }
        if(arr[mid]<key){
             e = mid -1;
        }else{
            s = mid +1;
        }
        mid = s+(e-s)/2;
    }
    return ans;
}

int main(){
int arr[9] = {1,2,3,3,3,3,7,3,5};
cout<<FirstInstance(arr,9,3)<<endl;
cout<<SecondInstance(arr,9,3)<<endl;
return 0;
}