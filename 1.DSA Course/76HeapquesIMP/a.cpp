#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*
K largest Subarray:
Here we are given a arr of int, we need to find the k largest sum of sub arr
ie: find the sum of all the subarrs and store it in the vector now return the k largest sum in the arr

Solu:
Apporach 1:Brute force:
1. use two loop to find all the sums and store all of them
2. now sort sum arr 
3. cal. the k largest from the back of the sorted sum arr and return it

TS: o(n2 log n)
Sp: O(n2)

Apporach 2: using min heap
The Min heap will return the largest element on the top.
steps: 
1. Run two loop to find all the sums possible in the arr
2. if the size of min heap is less than k then push the element in the heap
3. else check weather the sum > heap.top 
4. if so the pop the top and push the new larger sum.
5. return the top
  */

int klargestsumapp1(vector<int> arr , int k){
    vector<int> sumstore;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
       int sum = 0;
       for (int j = i; j < n; j++)
       {
        sum = sum+ arr[j];
        sumstore.push_back(sum);
       }
       
    }

    sort(sumstore.begin(),sumstore.end());

    return sumstore[sumstore.size()-k];
    
}

int klargestsumapp2(vector<int> arr, int k){
    int n = arr.size();
    priority_queue<int, vector<int>, greater<int>> mini;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum = sum + arr[j];
            if(mini.size()<k){
                mini.push(sum);
            }else{
                if(sum>mini.top()){
                    mini.pop();
                    mini.push(sum);
                }
            }
        }
        
    }
    return mini.top();
    
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    int k = 3;
    cout<<klargestsumapp1(arr,k)<<endl;
    cout<<klargestsumapp2(arr,k)<<endl;


return 0;   
}