#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Binary search using Recursion:
base case :
 */

bool BinarySearch(int arr[],int key,int size, int s,int end){
    //base case:
    if(s>end){
        return false;
    }
    int mid = s+ (end-s)/2;
    if(arr[mid] == key){
        return true;
    }
    if(arr[mid]<key){
        return BinarySearch(arr,key,size,mid+1,end);
    }else{
        return BinarySearch(arr,key,size,s,mid-1);
    }
}
int main(){
    int arr[6] = {1,2,3,4,5,7};
    int key = 6;
    int s = 0;
    int end = 6;
    cout<<BinarySearch(arr,key,6,s,end);
return 0;
}