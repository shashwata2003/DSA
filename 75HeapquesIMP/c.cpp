#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
2. Find the K largest element using min heap
 */

int klargest(vector<int> arr, int k){
    // create a minheap:
    //Check of k is a valid index or not
    // also if l and r are given then start from l and stop at l+k 
    // same for the other  start l+k to <=r
    priority_queue<int,vector<int>, greater<int>> minheap;
    for (int i = 0; i < k; i++)
    {
        //Push the first k elements in the min heap
        minheap.push(arr[i]);
    }

    for (int i = k; i < arr.size(); i++)
    {
        // Check weather if the top element is of the min heap is actually the greatest or not:
        // if not we replace it with the element in the array
        if(arr[i] > minheap.top()){
            minheap.pop();
            minheap.push(arr[i]);
        }
    }
    
    return minheap.top();

    
}

int main(){
    vector<int> arr = {7,1,4,3,20,15};
    int k = 3;
    cout<<klargest(arr,k);
return 0;
}