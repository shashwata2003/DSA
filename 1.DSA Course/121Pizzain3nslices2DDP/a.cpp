#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Pizza With 3n Slices:
There is a pizza with 3n slices of varying size, you and your friends will take slices of pizza as follows:
You will pick any pizza slice.
Your friend Alice will pick the next slice in the anti-clockwise direction of your pick.
Your friend Bob will pick the next slice in the clockwise direction of your pick.
Repeat until there are no more slices of pizzas.

Given an integer array slices that represent the sizes of the pizza slices in a clockwise direction, return the
maximum possible sum of slice sizes that you can pick.

eg:
Input: slices = [1,2,3,4,5,6]
Output: 10
Explanation: Pick pizza slice of size 4, Alice and Bob will pick slices with size 3 and 5 respectively. 
Then Pick slices with size 6, finally Alice and Bob will pick slice of size 2 and 1 respectively. 
Total = 4 + 6.

Input: slices = [8,9,8,6,1,1]
Output: 16
Explanation: Pick pizza slice of size 8 in each turn. If you pick slice with size 9 your partners will pick 
slices of size 8.
 */

int solveusingrecursion(int s, int e, vector<int> & slice, int n){
    if(n==0 || s>e){
        //if all slices are eatten by us hence return o or s excides e.
        return 0;
    }
    //as we have eatten the current hence skip the next and take +2 and decreament n as we can have one less
    //now also add the size of the slice.
    int eatcurr = slice[s] + solveusingrecursion(s+2,e,slice,n-1);
    int donteatcurr = 0+  solveusingrecursion(s+1,e,slice,n);

    return max(eatcurr,donteatcurr);
}

int solveusingmemorization(int s, int e, vector<int> & slice, int n, vector<vector<int>> &dp){
    if(n==0 || s>e){
        //if all slices are eatten by us hence return o or s excides e.
        return 0;
    }
    if(dp[s][n] != -1){
        return dp[s][n];
    }
    //as we have eatten the current hence skip the next and take +2 and decreament n as we can have one less
    //now also add the size of the slice.
    int eatcurr = slice[s] + solveusingmemorization(s+2,e,slice,n-1,dp);
    int donteatcurr = 0+  solveusingmemorization(s+1,e,slice,n,dp);
    dp[s][n] = max(eatcurr,donteatcurr);
    return dp[s][n];
}

//TS: O(n2) sp:O(n2)
int solveusingtabulation(vector<int> &slice){
    int n = slice.size();

    //+2 to avoid out of bound errors
    vector<vector<int>> dp1(n+2,vector<int>(n+2,0));
    vector<vector<int>> dp2(n+2,vector<int>(n+2,0));

    //Starting form 1 : using dp1 : analysing the call function of eatthefirst slice in the previous method
    for (int i = n-1 ; i >= 0; i--)
    {
        for (int k = 1; k <= n/3; k++)
        {
            int take = slice[i] + dp1[i+2][k-1];
            int nottake = dp1[i+1][k];

            dp1[i][k] = max(take,nottake);
        }
    }
    
    int eatthefirstslice = dp1[0][n/3];

    //not eating the first slice: using dp2:
     for (int i = n-2 ; i >= 0; i--)
    {
        for (int k = 1; k <= n/3; k++)
        {
            int take = slice[i] + dp2[i+2][k-1];
            int nottake = dp2[i+1][k];

            dp2[i][k] = max(take,nottake);
        }
    }
    
    int noteatingthefirstslice = dp2[1][n/3];

    return max(eatthefirstslice,noteatingthefirstslice);
}

int solveusingspaceopti(vector<int> &slice){
        int n = slice.size();

    //+2 to avoid out of bound errors
    //just replace dp with the corresponding array
    vector<int> next1(n+2,0); //i+2 
    vector<int> curr1(n+2,0); //i+1
    vector<int> prev1(n+2,0);// i

    vector<int> next2(n+2,0); //i+2 
    vector<int> curr2(n+2,0); //i+1
    vector<int> prev2(n+2,0);// i

    //Starting form 1 : using dp1 : analysing the call function of eatthefirst slice in the previous method
    for (int i = n-1 ; i >= 0; i--)
    {
        for (int k = 1; k <= n/3; k++)
        {
            int take = slice[i] + next1[k-1];
            int nottake = curr1[k];

            prev1[k] = max(take,nottake);
        }
        next1 = curr1;
        curr1 = prev1;
    }
    //the final ans will be in curr
    int eatthefirstslice = curr1[n/3];

    //not eating the first slice: using dp2:
     for (int i = n-2 ; i >= 0; i--)
    {
        for (int k = 1; k <= n/3; k++)
        {
            int take = slice[i] + next2[k-1];
            int nottake = curr2[k];

            prev2[k] = max(take,nottake);
        }
    }
    
    int noteatingthefirstslice = curr2[n/3];

    return max(eatthefirstslice,noteatingthefirstslice);
}

int maxSizeSlices(vector<int>& slices) {
    int n = slices.size();
    //Using recursion ONly:
    //we take the first slice hence st = 0 and cannot take the 2nd and the last slice hence n - 2
    // int st = 0, ed = n-2;
    // int takefirstslice = solveusingrecursion(st,ed,slices,n/3); //n/3 states the no. of slice i can have from 3n
    // // we dont take the first slice hence st = 1 and can take the last slice:
    // st = 1, ed = n-1;
    // int donttakethefirstslice = solveusingrecursion(st,ed,slices,n/3);

    // //Using memorization:
    // vector<vector<int>> dp1(n,vector<int>(n,-1));
    // int st = 0, ed = n-2;
    // int takefirstslice = solveusingmemorization(st,ed,slices,n/3,dp1);
    // st = 1, ed = n-1;
    // vector<vector<int>> dp2(n,vector<int>(n,-1));
    // int donttakethefirstslice = solveusingmemorization(st,ed,slices,n/3,dp2);

    //Using tabulation:
    // int ans = solveusingtabulation(slices);

    //Using space optimization:
    // the ans depends upon dp[i + 2][n-1] dp[i+1][n] and dp[i] hence we need to create 3 vectors as curr, next
    //and prev
    int ans = solveusingspaceopti(slices);

    // return max(takefirstslice,donttakethefirstslice);
    return ans;
}

int main(){
    vector<int> arr = {8,9,8,6,1,1};
    cout<<maxSizeSlices(arr);
return 0;
}