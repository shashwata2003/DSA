#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Heapify:
Given an array of integers, convert it into heap.
TS: O(n)
 */
class heap{
    int arr[100];
    int size;
    heap(){
        arr[0]=-1;
        size = 0;
    }
};
void heapify(int *arr,int n, int i){
    // setting the largest val = the current element
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;
    if(left<n && arr[largest]<arr[left]){
        largest = left;
    }
    if(right<n && arr[largest]<arr[right]){
        largest = right;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }

}
int main(){
    int arr[6]={-1,54,53,55,52,50};
    int n = 6;
    for (int i = n/2; i > 0; i--)
    {
        heapify(arr, n, i);
    }
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
return 0;
}