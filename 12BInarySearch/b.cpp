#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* Binary Search with recursion */
int BinarySearch(int arr[], int key, int s, int e){
    int mid = (s+e)/2;
        if(arr[mid] == key){
            return mid;
        }
        if(arr[mid]<key){
            s=mid+1;
            BinarySearch(arr,key,s,e);
        }else{
            e = mid -1;
            BinarySearch(arr,key,s,e);
        }
}

int main(){
    int arr[6] ={1,2,3,4,5,6};
    cout<<BinarySearch(arr,3,0,6)<<endl;
return 0;
}