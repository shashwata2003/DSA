#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  
isSorted: Given a arr find out weather the arr is sorted or not using recursion.
base case: size == 0 || 1 then return true
*/
bool issorted(int arr[],int size){
    if(size == 0 || size == 1){
        return true;
    }
    if(arr[0]>arr[1]){
        return false;
    }else{
        bool ans = issorted(arr + 1,size - 1);
        return ans;
    }
}
int main(){
    int arr[5] = {1,2,3,4,5};
    cout<<issorted(arr,5)<<endl;
return 0;
}