#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Maximum frequency of No.
Given a array of multiple unorder no. we need to return the no. with highest frequency.

If two or more elements contend for the maximum frequency, return the element which occurs in the array first i.e. whose index is lowest.

For example,

For 'arr' = [ 1, 2, 3, 1, 2]. you need to return 1.
Sample Input 1:
1 
13
2 12 2 11 -12 2 -1 2 2 11 12 2 -6 
Sample Output 1:
2

Sol: 
Using a unordered map we can solve it easily
 */

int findfreq(vector<int> arr, int n){
    unordered_map<int,int> mp;
    int maxfreq = 0, maxans = 0;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
        maxfreq = max(mp[arr[i]],maxfreq);
    }
    for (int i = 0; i < n; i++)
    {
        //This is the loop to find the element which has the max freq in the map
        if(maxfreq == mp[arr[i]]){
            maxans = arr[i];
            break;
        }
    }
    return maxans;
    
    
}

int main(){
vector<int> arr = {2, 12, 2, 11, -12, 2, -1, 2 ,2, 11, 12, 2, -6};
int n = arr.size();
cout<<findfreq(arr,n);
return 0;
}