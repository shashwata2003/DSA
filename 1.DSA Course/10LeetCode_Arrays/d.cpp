#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Code Studio: Find Dupilcates in Array:
given a array of size n. This array consist of 1 to n-1 unique elements in it. THere is only one element repeating 
find that repeating int.
eg: let n = 5
the array has elements from 1 to 5-1 ie is [1,2,3,4,4] and 4 is appearing twice find 4 
sol:
1. using brute force: just count each element and find the one with count 2 and print it 
2. using xor: we know that the element are form 1 to n - 1 so we are update the array by adding the element which 
will make ever element count as 2 and the duplicate element will be 3 times hence now xor the entire solution will
give the duplicate element.
 */
int main(){
    vector<int> arr = {2,2,2,2,2};
    int s = arr.size();
    int ans = 0;
    //XOR of all element of the arr
    for (int i = 0; i < s; i++)
    {
        ans = ans^arr[i];
    }
    // XOR of n-1
    for (int j = 0; j < s; j++)
    {
        ans=ans^j;
    }
    cout<<ans;
    
return 0;
}