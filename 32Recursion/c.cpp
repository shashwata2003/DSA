#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Say Digits:
Given a n = 412 we need to print four one two
rr: f(n/10);
base case: n == 0 : return
 */

void saydigit(int n, string arr[]){
    if(n==0){
        return ; 
    }
    int digit = n%10;
    n= n/10;
    saydigit(n,arr);
    cout<<arr[digit]<<" ";
}

int main(){
    string arr[3] = {"zero","one","two"};
    saydigit(120,arr);
return 0;
}