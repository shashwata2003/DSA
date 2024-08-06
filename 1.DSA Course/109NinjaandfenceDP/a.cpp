#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Ninja And The Fence:
Ninja has given a fence, and he gave a task to paint this fence. The fence has 'N' posts, and Ninja has 
'K' colors. Ninja wants to paint the fence so that not more than two adjacent posts have the same color.

Ninja wonders how many ways are there to do the above task, so he asked for your help.

Your task is to find the number of ways Ninja can paint the fence. Print the answer modulo 10^9 + 7.

Example:
Input: 'N' = 3, 'K' = 2
Output: 6

Sample Input 1 :
2
1 1
3 2
Sample Output 1 :
1
6

 */


#define mod 1000000007
int add(int a, int b){
    return (a%mod + b%mod)%mod;
}
int multi(int a,int b){
    return ( (a%mod)* 1LL*(b%mod) )%mod;
}

//Using only recursion : TS: exponial 
int solverecursion(int n, int k) {
    if (n == 1) {
        // if there is 1 fence hence we can paint it in k different colors and ways
        return k;
    }

    if (n == 2) {
        return add(k, multi(k, k - 1));
    }

    int ans = add(multi(solverecursion(n - 2, k), k - 1), multi(solverecursion(n - 1, k), k - 1));
    return ans;
}

//Using memorization: TS: O(n) SP: O(n)
int solveusingmemorization(vector<int>&dp,int n, int k){
    // base case
    if(n == 1){
        return k;
    }
    if(n ==2){
        return add(k,multi(k,k-1) );
    }
    if(dp[n] != -1){
        return dp[n];
    }
    dp[n] = add( multi(solveusingmemorization(dp,n-2, k), k-1) , multi(solveusingmemorization(dp,n-1, k), k-1) );
    return dp[n];
}


//Using Tabluation:
// TS: O(n) SP: O(n)
int solveusingtabulation(int n, int k){
    vector<int> dp(n+1,-1);
    dp[1] = k;
    dp[2] = add(k,multi(k,k-1));

    for (int i = 3; i <= n; i++)
    {
        dp[i] = add( multi(dp[n-2], k-1) , multi(dp[n-1], k-1) );
    }
    
    return dp[n];
}

//OPtimising the space : TS: O(n) SP: O(1)
int solveusingspaceoptimiazation(int n, int k){
    int prev2 = k;
    int prev1 = add(k,multi(k,k-1));

    for (int i = 3; i <= n; i++)
    {
       int ans = add( multi(prev2, k-1) , multi(prev1, k-1) );
       prev2 = prev1;
       prev1 = ans;
    }
    return prev1;
}

int numberOfWays(int n, int k) {
    // Using only recursion:
    // int ans = solverecursion(n, k);

    //Using Memorization:
    // vector<int> dp(n+1, -1);
    // int ans = solveusingmemorization(dp,n,k);

    //Using Tabulation:
    // int ans = solveusingtabulation(n,k);

    //Using Space optimization:
    // here the output is dependent upon the i -1 and i -2 th element in the dp array, hence we can
    // create static variables to find the ans.

    int ans = solveusingspaceoptimiazation(n,k);

    return ans;
}

int main() {
    int n = 3; // number of fences
    int k = 2; // number of colors
    cout << "Number of ways to paint the fences: " << numberOfWays(n, k) << std::endl;
    return 0;
}