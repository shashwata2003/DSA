#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
K smallest Element:
Given a arr and value of k, we need to find the k smallest element in that array using heap.
eg:
Input:
n = 6
arr[] = 7 10 4 3 20 15
k = 3
l=0 r=5 (l and r represts the start and end of the array)
Output : 
7
Explanation :
3rd smallest element in the given 
array is 7.

Sol:
Apporach 1:(Brute force)
Here we will sort the array and return k-1 element easily
TS: O(nlog n)

Apporach 2: using heaps
Here first we will create a max heap using a the first k elements of the arr
next we will process the rest of the elements in the arr by the following steps
1. if element < heap.top then heap.pop(top) and heap.push(ele)
2. do this till the end of the arr
3. heap.top will be the ans.

TS: O(n)
Sp: O(1)
 */

int ksmallest(vector<int> arr, int k, int l, int r){
     // Check if k is within the valid range
    if (k > (r - l + 1) || k <= 0) {
        return -1; // or some appropriate error value
    }
    priority_queue<int> pq;
    for (int i = l; i < l+k; i++)
    {
        pq.push(arr[i]);
    }

    for (int i = l+k; i <= r; i++)
    {
        if(arr[i]<pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}


int main(){
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3;
    int l = 0, r = 5;
    cout<<ksmallest(arr,k,l,r);
return 0;
}