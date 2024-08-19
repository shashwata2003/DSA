#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Minimum Cost of ropes:

There are given N ropes of different lengths, we need to connect these ropes into one rope. 
The cost to connect two ropes is equal to sum of their lengths.
The task is to connect the ropes with minimum cost. Given N size array arr[] contains the lengths of the ropes.
n = 4
arr[] = {4, 3, 2, 6}
Output: 
29 
 */

   long long minCost(long long arr[], long long n) {
    priority_queue<long long, vector<long long>, greater<long long>> minheap;
    for (int i = 0; i < n; i++)
    {
        minheap.push(arr[i]);
    }
    long long cost = 0;
    while(minheap.size()>1){
        long long first = minheap.top();
        minheap.pop();
        long long second = minheap.top();
        minheap.pop();
        long long newlen = first+second;
        cost = cost+newlen;
        minheap.push(newlen);
    }
    return cost;
}

int main(){

return 0;
}