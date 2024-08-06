#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* Binary Search in array with out recursion */
int BinarySearch(int arr[],int size, int key,){
    int s = 0;
    int e = size-1;
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

int main(){
    int arr[6] ={1,2,3,4,5,6};
    cout<<BinarySearch(arr,6,6)<<endl;
return 0;
}