#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Fibonnaci series using recursion:
Given n we need to find the fibonacci of that index.
 */
int fibo(int n){
    if(n == 0){
        return 0;
    }if(n==1){
        return 1;
    }
    int ans = fibo(n-1)+fibo(n-2);
    return ans;
}

int main(){
    int n;
    cin>>n;
    cout<<fibo(n)<<endl;
return 0;
}