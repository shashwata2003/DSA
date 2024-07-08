#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Plus one:
Given a array of a number in a array we need to add one to that no.
eg: {1,2,3}
ans: {1,2,4}

Sol:
here we have three condition:
1. if less than 9 then simple add the last element with on
2. if 9 then set it 0
3. if all 9's then create a new array with + 1 size
*/

vector<int> sumone(vector<int> arr){
    for (int i = arr.size()-1; i >= 0; i--)
    {
        if(arr[i] < 9){
            arr[i]++;
            return arr;
        }
        arr[i] = 0;
    }
    // if we reached here that means we have all 9s
    vector<int> newans(arr.size()+1,0);
    newans[0] =1;
    return newans;
    
}

int main(){
    vector<int> arr = {9,9,9};
    arr =  sumone(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    
return 0;
}