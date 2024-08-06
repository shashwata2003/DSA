#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Given a array having three no. 0,1,2 sort the array in a way that 0 is at the left most , 1 in the middle and 
2 at the right most.
Sol: 1.sort the array 
2. three pointer method. This is called Dutch national flag algorithm:
we need three pointers low = 0 mid = 0 and high = n-1
Here we will check three condition i) if mid == 0 swap(mid, low) mid++ low++ 2) if mid == 1 mid ++ 
3) id mid==2 swap(mid,high) high-- mid++
*/
int main(){
    vector<int> arr = {0,1,2,1,0,2};
    //sort(arr.begin(),arr.end()); sorting way will take nlogn complexity 
    int n = arr.size();
    int mid = 0,low = 0, high = n-1;
     while (mid <= high) {
        switch (arr[mid]) {
            case 0:
                swap(arr[low++], arr[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(arr[mid], arr[high--]);
                break;
        }
     }
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    
return 0;
}

