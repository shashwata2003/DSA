#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Cut Into Segments
You are given an integer ‘N’ denoting the length of the rod. You need to determine the maximum number of 
segments you can make of this rod provided that each segment should be of the length 'X', 'Y', or 'Z'.
Sample Input 1:
2
7 5 2 2 // N , X, y, z
8 3 3 3
Sample Output 1:
2
0

Sol:
Same old 4 apporachs:
 */

//TS : exponiatial
int solverecursion(int n, int x, int y, int z){
    if(n == 0){
        // no. of segment needed for length 0 is 0
        return 0;
    }
    if(n<0){
        // if the segment is negative then return INT MIN
        return INT_MIN;
    }
    
    // check with each segment as the first, which ever one of them return maximum will be the ans
    int a = solverecursion(n-x,x,y,z) + 1; // +1 because we add need to add the current segment too
    int b = solverecursion(n-y,x,y,z) + 1;
    int c = solverecursion(n-z,x,y,z) + 1;

    return max(a,max(b,c));
}

// TS: O(n) Sp: O(n)
int solveusingmemorization(int n, int x, int y, int z,vector<int> &dp){
     if(n == 0){
        // no. of segment needed for length 0 is 0
        return 0;
    }
    if(n<0){
        // if the segment is negative then return INT MIN
        return INT_MIN;
    }
    if(dp[n] != -1){
        return dp[n];
    }

    int a = solveusingmemorization(n-x,x,y,z,dp) + 1; // +1 because we add need to add the current segment too
    int b = solveusingmemorization(n-y,x,y,z,dp) + 1;
    int c = solveusingmemorization(n-z,x,y,z,dp) + 1;
    
    dp[n] = max(a,max(b,c));
    return dp[n];
}

// TS: O(n) SP: O(n)
int solveusingtabulation(int n, int x, int y , int z){
    vector<int> dp(n+1,INT_MIN); // we are not init with -1 because in the future we do +1 in the dp arr
    // which can make it 0 and store the ans which we dont want, 
    // to make it work we need to check for if d[i-x] != -1 then only we move forward
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        if(i-x >= 0){
            dp[i] = max(dp[i],dp[i-x]+1);
        }
        if(i-y >= 0){
            dp[i] = max(dp[i],dp[i-y]+1);
        }
        if(i-z >= 0){
            dp[i] = max(dp[i],dp[i-z]+1);
        }
    }
    
    return dp[n];
}

int cutSegments(int n, int x, int y, int z) {
	// Uisng just recursion:
    // int ans = solverecursion(n,x,y,z);

    // //Now using Recursion and Memorization:
    // vector<int> dp(n+1,-1);
    // int ans = solveusingmemorization(n,x,y,z,dp);

    //Using Tabulation:
    int ans = solveusingtabulation(n,x,y,z);

    //Using SPace Optimiztion:
    /* We cannot implement space optimization here because here the ans depend upon n - x , n - y , n - z
    and we are not sure of the val of x , y, and z hence we cannot create three different static variables
    hence cannot improve the space complexity */

    if(ans < 0){
        return 0;
    }else{
        return ans;
    }
}

int main(){
    int n = 7, x = 5, y = 2, z = 2;
    cout<<cutSegments(n,x,y,z);
return 0;
}