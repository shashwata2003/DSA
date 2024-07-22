#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* Count derangements:
A Derangement is a permutation of ‘N’ elements, such that no element appears in its original position.
For example, an instance of derangement of {0, 1, 2, 3} is {2, 3, 1, 0}, because 2 present at index 0 is 
not at its initial position which is 2 and similarly for other elements of the sequence.

Given a number ‘N’, find the total number of derangements possible of a set of 'N’ elements.

Sample Input 1:
2
2
3
Sample Output 1:
1
2

Sample Input 2:
2
1
4
Sample Output 2:
0
9

Apporach:
Check notes: 

We will implememt 4 apporachs again.
 */

#define MOD 1000000007

//Using Recursion:
//TS: Exponatial 
long long int solveRecursion(int n){
     if(n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }
    long long int ans = ((n-1)%MOD * (solveRecursion(n-1)%MOD + solveRecursion(n-2)%MOD)%MOD)%MOD;
    return ans;
}

// Using memoriation: 
// TS: O(n) SP: O(n)
long long int solveusingmemorization(int n, vector<long long int> &dp){
    if(n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    dp[n] = ((n-1)%MOD * (solveusingmemorization(n-1,dp)%MOD + solveusingmemorization(n-2,dp)%MOD)%MOD)%MOD;
    return dp[n];
}

//using Tabulation:
// TS: O(n) SP: O(n)
long long int solveusingtabulation(int n){
    vector<long long int> dp(n+1,0);
    dp[1] = 0;
    dp[2] = 1;
    for (int i = 3; i < n+1; i++)
    {
        dp[i] = ((i-1)%MOD * (dp[i-2]%MOD + dp[i-1]%MOD)%MOD)%MOD;
    }
    return dp[n];
}

// Space optimization:
// TS: O(n) SP: O(1)
long long int solveusingspaceopti(int n){
    long long int prev2 = 0;
    long long int prev1 = 1;

    for (int i = 3; i <= n; i++)
    {
        int ans =  ((i-1)%MOD * (prev2%MOD + prev1%MOD)%MOD)%MOD;
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}

long long int countDerangements(int n) {
   // Using just recursion:
//    long long int ans = solveRecursion(n);

   //using memorization:
    // vector<long long int> dp(n+1,-1);
    // long long int ans = solveusingmemorization(n,dp);

    //Using Tabulation:
    // long long int ans = solveusingtabulation(n);

    //using space optimization:
    // here the ans is dependent upon i -1 and i - 2 hence which can be done using a static variables:
    long long ans = solveusingspaceopti(n);

   return ans;
}

int main(){

return 0;
}