#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Code for Selection sort:
Moves the smallest element to the start of the array
 */
int main(){
    int n = 5;
    int arr[5] = {64,55,43,23,21};
    for (int i = 0; i < n-1; i++)
    {
        int minIndex = i;
        for (int j = i+1; j < n; i++)
        {
            if (arr[j]<arr[minIndex])
            {
                minIndex = j;     
            }
            
        }
        swap(arr[i],arr[minIndex]);
    }
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    
return 0;
}