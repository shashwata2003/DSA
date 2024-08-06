#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* insertion Sort code: */
int main(){
    int n = 5;
    int arr[n] = {3,2,1,5,4};
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i-1;
        for (; j >= 0; j--) // here we treverse the sorted array backwards 
        {
           if (arr[j]>temp)
           {
            // we will shift and add the new no.
            arr[j+1] = arr[j];
           }else{
            break; // not greater then the element is at the right place.
           }
        }
        arr[j+1] = temp;
        
    }
     for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
return 0;
}