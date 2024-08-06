#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Given a array find the sum of the elements of the array using recursion.
base condition size == 1 return arr[i] and size == 0 stop
}

Base case: size == 0  return 0
ans size == 1 return arr[0]
RR: arr[o]+ f(arr+1,size -1);
 */

int findsum(int arr[],int size){
    if(size==1){
        return arr[0];
    }
    if(size == 0){
        return 0;
    }
    int ans = arr[0] + findsum(arr +1 ,size - 1);
    return ans;
}
int main(){
    int arr[6] = {1,2,3,4,5,6};
    cout<<findsum(arr,6)<<endl;
return 0;
}