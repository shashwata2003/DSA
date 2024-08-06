#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Given a and b find a^b using recursion
Base case:
b == 0 return 1
b == 1 return a
 */

int power(int a,int b){
    if(b==0){
        return 1;
    }
    if(b==1){
        return a;
    }
    int ans = power(a,b/2);
    if(b%2 == 0){
        return ans*ans;
    }
    else{
        return a*ans*ans;
    }

}

int main(){
    int a = 2,b = 3;
    cout<<power(a,b);
return 0;
}