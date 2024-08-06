#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Codestudio: Sort 01:
Here we are given with an array of 0 & 1. we need to move all the 0 to left and the 1 to the right.
like:
[100010] => [000011]
sol: 1) Applying sort method on the array
2) traversing the array to find the count of each 0 and 1 and print the same 
3. two pointer method: keep two pointers one at the 0th and the other at the nth: then check following 
three conditions: i) if arr[i]==0: i++ and ii) if arr[j] == 1 j--; iii) if arr[i] ==1 && arr[j] == 0 swap both 
this done under the assumptin that i th side we are entering all zeros and the j th size we are adding all the ones
 */
int main(){
vector<int> arr={1,0,1,0,0,1};
int n = arr.size();
int i = 0, j = n-1;
while (i<=j)
{
    while (arr[i] == 0 && i<=j)  
    {
        i++;
    }
    while (arr[j]==1&& i<=j)
    {
        j--;
    }
    while (i<=j)
    {
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
}

for (int i = 0; i < n; i++)
{
    cout<<arr[i]<<" ";          
}

return 0;
}