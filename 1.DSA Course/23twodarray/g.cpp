#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Binary search in 2d arr:
The only difference between a linear binary search and this is the calculating the mid value 
here the mid element will be row = mid/n col = mid%n

Time Complexity: O(log mn)
 */
int main(){
    vector<vector<int>> arr = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int target = 17;
    int rows = arr.size();
    int cols = arr[0].size();
    int start = 0;
    int end = (rows*cols) - 1;
    int mid = start +(end-start)/2;
    while (start<=end)
    {
        int element = arr[mid/cols][mid%cols];
        if (element == target)
        {
            cout<<"Found"<<endl;
        }
        if(element<target){
            start = mid+1;
        }else{
            end = mid-1;
        }
        mid = start +(end-start)/2;
    }
    cout<<"Notfound"<<endl;
return 0;
}