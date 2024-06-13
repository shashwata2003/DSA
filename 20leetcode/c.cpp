#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Moves zero: Given a array with multiple zeros in it. Move all the zeros to the right of the array and move the 
element to the right in the same order.
eg [2,0,1,3,0,0,0]
ans: [2,1,3,0,0,0,0]
SOl: we need to use two logic to solve the
1. if arr[i] == 0 then ignore 
2. if arr[i] != 0 then swap the arr[i] with the zeroth index (which will be stored in a variable for reference 
perpose) and increment i.
 */
int main(){
    vector<int> arr = {2,0,1,3,0,0,0};
    int i =0;
    for (int j = 0; j < arr.size(); j++)
    {
        if(arr[j] != 0){
            swap(arr[j],arr[i]);
            i++;
        }
    }

    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    
    
return 0;
}