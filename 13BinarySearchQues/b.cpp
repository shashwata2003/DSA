#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Find the total no. of occurance in a array given a key
eg: [1,2,3,3,3,3,3,7,8] key 3 
ans : 5
sol: 
First find the first and the last reference of the key, as the array is sorted. the no. of occurances will be from 
(right - left) +1
 */

int firstInstance(int arr[],int size,int key){
    int s = 0;
    int e = size - 1;
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
int arr[9] = {1,2,3,3,3,3,3,5,7};
cout<<SecondInstance(arr,9,3)-firstInstance(arr,9,3) +1<<endl;
return 0;
}