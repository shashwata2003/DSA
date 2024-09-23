#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  */
int findprefixsize(vector<int> &arr){
    if()
}
int findmaxzero(vector<int> &arr, int n){
    int prefix = findprefixsize(arr);
    while(prefix>0){
        for(int i = 0; i<n; i++){
           if(arr[i] != 0){
                arr[i] = arr[i]-1;
           }
        }
        prefix = findprefixsize(arr);
    }
    int cnt = 0;
    for(int i = 0; i<n; i++){
        if(arr[i] == 0){
            cnt++;
        }
    }
    return cnt;
}


int main(){

return 0;
}