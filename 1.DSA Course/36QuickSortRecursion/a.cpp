#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* Quick Sort Sort using recursion: */

int partitionindex(int arr[], int s, int e){
    int pivot = arr[s];
    int cnt = 0;
    for (int i = s+1; i <= e; i++)
    {
       if(arr[i]<=pivot){
        cnt++;
       }
    }
    int pivotindex = s+cnt;
    swap(arr[pivotindex],arr[s]);

    int i = s, j = e;
    while (i<pivotindex && j >pivotindex)   
    {
        while (arr[i]<=pivot)
        {
            i++;
        }
        while (arr[j]>pivot)
        {
            j--;
        }
        if (i<pivotindex&& j> pivotindex){
            swap(arr[i++],arr[j--]);
        }

        
        
        
    }
    return pivotindex;     
    
}

void QuickSort(int *arr,int s, int e){
    if(s>=e){
        return;
    }
    int p = partitionindex(arr,s,e);
    QuickSort(arr,s,p-1);
    QuickSort(arr,p+1,e);
    
}

int main(){
    int arr[5] = { 5 ,2, 3, 1 ,4};
    QuickSort(arr,0,4);
    for (int i = 0; i < 5; i++)
    {
        cout<<arr[i]<<" ";
    }
    
return 0;
}