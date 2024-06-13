#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Rotate the array: Given an array rotate it.
eg:[1,7,9,11] rotate by 2 
this means roate the array b 2 places
like: [9,11,1,7] 1 and 7 moves two places each and 9 and 11 move one places each circling back the array.
sol:
We need to use mod to solve the problem. Let us consider 7 need to moved by 2 places to pos index 1 hence we can
use index of 7 = 3 + 2(no. of pos to move) % 4 = 1 (ans)  
 */
int main(){
    vector<int> arr = {9,11,1,7};
    int n = arr.size();
    vector<int> ans(n);
    int m = 2;
    for (int i = 0; i < n; i++)
    {
        ans[(i+m)%n] = arr[i];
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
    
return 0;
}