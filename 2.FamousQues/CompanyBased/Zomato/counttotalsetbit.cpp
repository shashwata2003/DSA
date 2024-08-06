#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Find total number of set bit in numbers upto n.:





*/

int countbitutil(int n){
    if(n<=0){
        return 0;
    }
    if(n%2 == 0){
        return 0 + countbitutil(n/2);
    }else{
        return 1 + countbitutil(n/2);
    }
}

int countbits(int n){
    int bitcount = 0;
    for (int i = 1; i <= n; i++)
    {
        bitcount = bitcount + countbitutil(i);
    }
    return bitcount;
}

int main(){
    int n = 6;
    cout<<countbits(n);
    
return 0;
}