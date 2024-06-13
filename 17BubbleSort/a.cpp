#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* Code for Bubble sort */
int main(){
    int n = 5;
    int arr[n] = {3,4,2,1,6};
    for (int i = 1; i < n; i++)
    {
        bool isSorted = false; // this checks weather the array is already sorted or not if yes then it will not
        //continue to apply the bubble sort.
        for (int j = 0; j < n-i; j++)
        {
            if (arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                isSorted =true;
            }
            
        }
        if(isSorted == false){ // break the rounds loop if it is sorted
            break;
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
return 0;
}