#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements 
in both parts is the same.

Example 1:
Input: N = 4
arr = {1, 5, 11, 5}
Output: YES
Explanation: 
The two parts are {1, 5, 5} and {11}.

Example 2:
Input: N = 3
arr = {1, 3, 5}
Output: NO
Explanation: This array can never be 
partitioned into two such parts.
 */

bool solveusingrecursion(int index, int n, int arr[],int target){
    if(target < 0){
        // if the target becomes -ve
        return false;
    }
    if(target == 0){
        // if target becomes equal to 0 hence reached the desired val
        return true;
    }
    if(index>= n){
        // if the curr index passes the length of the arr
        return false;
    }
    
    //Including the curr element , hence increment the index and remove the curr val form the target
    bool inclu = solveusingrecursion(index+1,n,arr,target - arr[index]);
    //Excluding will just increment the index
    bool exclu = solveusingrecursion(index+1,n,arr,target - 0);

    return inclu || exclu;
}

bool solveusingmemorization(int index, int n, int arr[],int target,vector<vector<int>> &dp){
    if(target < 0){
        // if the target becomes -ve
        return false;
    }
    if(target == 0){
        // if target becomes equal to 0 hence reached the desired val
        return true;
    }
    if(index>= n){
        // if the curr index passes the length of the arr
        return false;
    }
    if(dp[index][target] != -1){
        return dp[index][target];
    }
    //Including the curr element , hence increment the index and remove the curr val form the target
    bool inclu = solveusingmemorization(index+1,n,arr,target - arr[index],dp);
    //Excluding will just increment the index
    bool exclu = solveusingmemorization(index+1,n,arr,target - 0,dp);
    dp[index][target] = inclu || exclu;
    return dp[index][target] ;
}

//Ts: O(sum*n) 
bool solveusingtabulation(int n , int arr[], int target){
    vector<vector<int>> dp(n+1,vector<int>(target+1,0));
    //first two base cases are handled by the init only
    //target == 0 ans = 1;
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }

    for (int index = n-1; index >= 0; index--)
    {
        for (int tar = 0; tar <= target; tar++)
        {
            //Including the curr element , hence increment the index and remove the curr val form the target
            bool inclu  = false;
            if(tar - arr[index] >= 0){
                inclu = dp[index+1][tar - arr[index]];
            }
            //Excluding will just increment the index
            bool exclu = dp[index+1][tar - 0];
            dp[index][tar] = inclu || exclu;
        }
        
        
    }
    return dp[0][target];
}

int solveusingspaceopti(int n, int arr[], int target){
    vector<int> curr(target+1,0); // index
    vector<int> next(target+1,0); //index+1

   
    curr[0] = 1;
    next[0] = 1;
    

    for (int index = n-1; index >= 0; index--)
    {
        for (int tar = 0; tar <= target; tar++)
        {
            //Including the curr element , hence increment the index and remove the curr val form the target
            bool inclu  = false;
            if(tar - arr[index] >= 0){
                inclu = next[tar - arr[index]];
            }
            //Excluding will just increment the index
            bool exclu = next[tar - 0];
            curr[tar] = inclu || exclu;
        }
        next = curr;
        
    }
    return next[target];

}

int equalPartition(int N, int arr[])
{
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum = sum + arr[i];
    }
    //checking weather the sum is even or not 
    if(sum % 2 != 0){
        return 0;
    }
    //if even cal. the target:
    int target = sum / 2;
    //Using only recursion:
    int index = 0;
    // int ans = solveusingrecursion(index,N,arr,target);

    //Using Memorization:
    // vector<vector<int>> dp(N+1,vector<int>(target+1,-1));
    // int ans = solveusingmemorization(index,N,arr,target,dp);

    //Using tabulation:
    //Earlier the n was going from o to n and target for target to 0
    // Here we will reverse it:
    // int ans = solveusingtabulation(N,arr,target);

    //Using space optimization:
    //The ans depents upon index + 1 and index also the target but we can make two arr of size targets:
    int ans = solveusingspaceopti(N,arr,target);

    return ans;
}

int main(){
    int n = 4;
    int arr[n] = {1, 5, 11, 5};
    cout<<equalPartition(n,arr);
return 0;
}