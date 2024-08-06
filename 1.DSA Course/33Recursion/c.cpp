#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* Linear search using recursion:
 base case: size == 0 : return false
 
 */
bool linearsearch(int arr[],int key, int size){
    if(size == 0){
        return false;
    }
    if(arr[0] == key){
        return true;
    }
    else{
        bool ans = linearsearch(arr+1,key,size-1);
        return ans;
    }
}

int main(){
    int arr[6] = {1,2,3,4,5,6};
    int key = 7;
    cout<<linearsearch(arr,key,6);
return 0;
}