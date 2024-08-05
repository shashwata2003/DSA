#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  Minimum Cost Tree From Leaf Values:

Given an array arr of positive integers, consider all binary trees such that:

Each node has either 0 or 2 children;
The values of arr correspond to the values of each leaf in an in-order traversal of the tree.

The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree,
respectively.

Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf 
node. It is guaranteed this sum fits into a 32-bit integer.

A node is a leaf if and only if it has zero children.

Input: arr = [6,2,4]
Output: 32
Explanation: There are two possible trees shown.
The first has a non-leaf node sum 36, and the second has non-leaf node sum 32.

Input: arr = [4,11]
Output: 44


// The most optimial sol will be made using the Greedy algorithm
*/

//Solving using only recursion:
int solveusingrecursion(vector<int> &arr, map<pair<int,int>,int> &maxi, int l, int r){
    if(l == r){
        return 0;
    }

    int ans = INT_MAX;

    for (int i = l; i < r; i++)
    {
        ans = min(ans, maxi[{l,i}]*maxi[{i+1,r}] + solveusingrecursion(arr,maxi,l,i) + solveusingrecursion(arr,maxi,i+1,r));
    }
       
    return ans;
}

int solveusingmemorization(vector<int> &arr, map<pair<int,int>,int> &maxi, int l, int r, vector<vector<int>> &dp){
    if(l == r){
        return 0;
    }
    if(dp[l][r] != -1){
        return dp[l][r];
    }
    int ans = INT_MAX;

    for (int i = l; i < r; i++)
    {
        ans = min(ans, maxi[{l,i}]*maxi[{i+1,r}] + solveusingmemorization(arr,maxi,l,i,dp) + solveusingmemorization(arr,maxi,i+1,r,dp));
    }
       
    return dp[l][r] = ans;
}

//TS: O(n3)
int solveusingtabulation(vector<int> &arr, map<pair<int,int>,int> &maxi){
    int n = arr.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));

   for (int left = n-1; left >= 0 ; left--)
   {
        for (int right = left+1; right < n; right++)
        {
            int ans = INT_MAX;

            for (int i = left; i < right; i++)
            {
                ans = min(ans, maxi[{left,i}]*maxi[{i+1,right}] + dp[left][i] + dp[i+1][right]);
            }
            
            dp[left][right] = ans;
        }
        
   }
   return dp[0][n-1];
}

int mctFromLeafValues(vector<int>& arr) {
    //In this question we need to find the max element b/w a range. we can make that easier by just 
    // pre calulating the maximum in every range using a map:
    int n = arr.size();
    map<pair<int,int>,int> maxi;
    for (int i = 0; i < n; i++)
    {
        // In the range 1,1 the max will be the 1th index itself
        maxi[{i,i}] = arr[i];
        for (int j = i+1; j < n; j++)
        {
            //Comparing every coming element with the prev element
            maxi[{i,j}] = max(arr[j],maxi[{i,j-1}]);
        }
    }

    int left = 0, right = n-1;
    //Using recursion only:
    // int ans = solveusingrecursion(arr,maxi,left, right);

    //Using Memorization:
    // vector<vector<int>> dp(n+1,vector<int>(n+1, -1));
    // int ans = solveusingmemorization(arr,maxi,left,right,dp);

    //Using tabulation:
    int ans = solveusingtabulation(arr,maxi);

    return ans;
    
}

int main(){
    vector<int> arr = {6,2,4};
    cout<<mctFromLeafValues(arr);
return 0;
}