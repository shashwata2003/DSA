#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
You have been given a number of stairs. Initially, you are at the 0th stair, and you need to reach the Nth stair.
Each time, you can climb either one step or two steps.
You are supposed to return the number of distinct ways you can climb from the 0th step to the Nth step.
eg: n = 3
out: 3
sol: RR: f(n-1)+f(n-2)
base case: n<0 return 0
n==0 return 1

This will be solved using TLA now it will give TLA

 */
int countways(int n ){
    if(n<0){
        return 0;
    }
    if(n==0){
        return 1;
    }
    int ans = countways(n-1)+countways(n-2);
    return ans;
}
int main(){
    int n = 33;
    cout<<countways(n);
return 0;
}