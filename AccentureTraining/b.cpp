#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Even Comes before odds in a given array:
10 98 3 38 12 22 21
10 98 22 12 33 3 21
 */
int main(){
    vector<int> arr = {3,5,1,2,4,6};
    int start = 0;
    int end = arr.size()-1;
    while (start<end){
        if(arr[start]%2 == 0){
            start++;
        }
        else if(arr[end]%2!=0){
            end++;
        }
        else{
            swap(arr[start],arr[end]);
            start++;
            end--;
        }
    }
    
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    
    
    
return 0;
}