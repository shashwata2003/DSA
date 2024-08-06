#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 0 1 Knapsack:
A thief is robbing a store and can carry a maximal weight of W into his knapsack. There are N items and the 
ith item weighs wi and is of value vi. Considering the constraints of the maximum weight that a knapsack can 
carry, you have to find and return the maximum value that a thief can generate by stealing items.

Sample Input:
1 
4
1 2 4 5
5 4 8 6
5
Sample Output:
13

question:
Equal subset sum partitian, subset sum , count of subset sum , miinmum subset sum differencer, target sum
 */

//Using Recursion only:

int solverecursion(vector<int> &weight, vector<int> &value, int n, int capacity){
    if(n == 0){
        //when we reach the end of the array while traversing 
        // now we need need to check weather we can take the last index weight in the knap sack 
        // if yes then we return the val of that index else we return 0.
        if(weight[0] <= capacity){
            return value[0];
        }
        else{
            return 0;
        }
    }

    int include = 0;
    if(weight[n] <= capacity){
        // if the weight can be added in the bag then we find for the next element and we include the next 
        // current index val to the ans.
        include = solverecursion(weight,value,n-1,capacity-weight[n]) + value[n];
    }
    int exclude = solverecursion(weight,value,n-1,capacity);
    
    int ans = max(include,exclude);
    return ans;
}

//Using recursion and memorization: TS: O(n*W) Sp: O(n*w)
int solveusingmemorization(vector<int> &weight, vector<int> &value, int n, int capacity, vector<vector<int>> &dp){
    if(n == 0){
        //when we reach the end of the array while traversing that is 0 as we are traversing R to L 
        // now we need need to check weather we can take the last index weight in the knap sack 
        // if yes then we return the val of that index else we return 0.
        if(weight[0] <= capacity){
            return value[0];
        }
        else{
            return 0;
        }
    }

    if(dp[n][capacity] != -1){
        return dp[n][capacity];
    }

    int include = 0;
    if(weight[n] <= capacity){
        // if the weight can be added in the bag then we find for the next element and we include the next 
        // current index val to the ans.
        include = solveusingmemorization(weight,value,n-1,capacity-weight[n],dp) + value[n];
    }
    int exclude = solveusingmemorization(weight,value,n-1,capacity,dp);
    
    dp[n][capacity] = max(include,exclude);
    return dp[n][capacity];
}

//Using tabulation:
//TS: O(n*W) Sp: O(n*w)
int solveusingtabulation(vector<int> &weight, vector<int> &value, int n, int capacity){
    vector<vector<int>> dp(n,vector<int>(capacity+1,-1));
    // setting the first value for teh weight 0 Base case
    for (int i = weight[0]; i <= capacity; i++)
    {
        if(weight[0]<=i){
            dp[0][i] = value[0];
        }else{
            dp[0][i] = 0;
        }
    }

    //Filling the dp array by traverse both the indexes and the capacity 
    for (int i = 1; i < n; i++)
    {
        for (int cap = 0; cap <= capacity; cap++)
        {
            int include = 0;
            if(weight[i]<=cap){
                include = value[i] + dp[i-1][cap-weight[i]];
            }
            int exclude = dp[i-1][cap];
            dp[i][cap] = max(include,exclude);
        }
    }
    return dp[n-1][capacity];
    
}

//SPace optimizaed: TS: O(n*W) Sp: O(w)
int solveusingspaceoptimization(vector<int> &weight, vector<int> &value, int n, int capacity){
    vector<int> prev(capacity+1,0);
    vector<int> curr(capacity+1,0);

    for (int i = weight[0]; i <= capacity; i++)
    {
        if(weight[0]<=capacity){
            prev[i] = value[0];
        }else{
            prev[i] = 0;
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int cap = 0; cap <= capacity; cap++)
        {
            int include = 0;
            if(weight[i]<=cap){
                include = value[i] + prev[cap-weight[i]];
            }
            int exclude = prev[cap];
            curr[cap] = max(include,exclude);
        }
        prev = curr;
    }
    return prev[capacity];    
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    // we are traversing the val and weight array form right to left:

    //USing only recursion:
	// int ans  = solverecursion(weight,value,n-1,maxWeight);

    //Using Memorization:
    // Here the dp is 2d because here here we have two changing variable: capacity and index in each recursion.
    // vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
    // int ans = solveusingmemorization(weight,value,n-1,maxWeight,dp);

    // Using tabulation:
    // int ans = solveusingtabulation(weight,value,n-1,maxWeight);

    //Space ptimization:
    // here the ans depends upon i - 1 in the dp arr:
    int ans = solveusingspaceoptimization(weight,value,n-1,maxWeight);

    // Here we can try to improve the space complexity for by using only one array called the vector,
    /* as we can see that the curr ans only depents on prev[x] and prev[x-i]  hence the entire current 
    array except the current index and the right side of the prev are getting wasted */
    /* Hence we can create a single curr array which will trverse from right to left as it can update the 
    right side of the array but will not effect the future ans.*/

    return ans;
}

int main(){
    int n = 4;
    vector<int> weight = {1, 2, 4, 5};
    vector<int> val = {5, 4, 8, 6};
    int knap = 5;
    cout<<knapsack(weight,val,n, knap);
return 0;
}