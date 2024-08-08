#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
0 - 1 Knapsack Problem:
You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum 
total value in the knapsack. Note that we have only one quantity of each item.
In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights 
associated with N items respectively. Also given an integer W which represents knapsack capacity, find out 
the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. 
You cannot break an item, either pick the complete item or dont pick it (0-1 property).

Example 1:

Input:
N = 3
W = 4
values[] = {1,2,3}
weight[] = {4,5,1}
Output: 3
Explanation: Choose the last item that weighs 1 unit and holds a value of 3. 

Example 2:

Input:
N = 3
W = 3
values[] = {1,2,3}
weight[] = {4,5,6}
Output: 0
Explanation: Every item has a weight exceeding the knapsack's capacity (3).

https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
*/

/*
Using same inclu and exclu mathod
*/

int solve(int W, int wt[], int val[], int n){
    if(n <= 0 || W < 0){
        return 0;
    }
     // If weight of the nth item is more
    // than Knapsack capacity W, then
    // this item cannot be included
    // in the optimal solution
     if (wt[n - 1] > W) {
        return solve(W, wt, val, n - 1);
    }
    // Return the maximum of two cases:
    // (1) nth item included
    // (2) not included
    int inclu = val[n] + solve(W-wt[n-1],wt,val,n-1);
    int exclu = solve(W,wt,val,n-1);
    return max(inclu,exclu);
    
}

int knapSack(int W, int wt[], int val[], int n) 
{ 
    int ans = solve(W,wt,val,n);
    return ans;
}

int main(){
    int N = 3;
int W = 3;
int values[N] = {1,2,3};
int weight[N] = {4,5,6};
cout<<knapSack(W,weight,values,N);
return 0;
}