#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
nCr:
Given two integers n and r, find nCr. Since the answer may be very large, calculate the answer modulo 109+7.
Note : If r is greater than n, return 0.

Example 1:

Input: n = 3, r = 2
Output: 3
Explaination: 3C2 = 3. 
Example 2:

Input: n = 2, r = 4
Output: 0
Explaination: r is greater than n.

https://www.geeksforgeeks.org/problems/ncr1019/1

https://www.geeksforgeeks.org/binomial-coefficient-dp-9/ solution:

nCr : n! / k!(n-k)!
 */

int solve(int n, int r){
    if(r>n){
        return 0;
    }
    if(r == 0 || r == n){
        return 1;
    }
    return solve(n-1,r-1) + solve(n-1,r);
}

int nCr(int n, int r){
    int ans = solve(n,r);
}

int main(){

return 0;
}