#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
 Minimum Elements
You are given an array of ‘N’ distinct integers and an integer ‘X’ representing the target sum. 
You have to tell the minimum number of elements you have to take to reach the target sum ‘X’.
Note:
You have an infinite number of elements of each type.

eg:
Sample Input 1 :
2
3 7
1 2 3
1 0
1
Sample output 1 :
3
0

Sol:

Apporach 1: recursion
This solution will give TLA, to save time we need to use memorization.

apporach 2: add memorization to implement top down

apporach 3: adding tabulation and reducing complexity:

apporach 4:Optimizing space
*/


//APporach 1: 
// TS: exponeitional
int solverec(vector<int> &num, int x){
    if(x == 0){
        return 0;
    }
    if(x<0){
        return INT_MAX;
    }

    int mini = INT_MAX;
    // traverse all the coins in the nums array and checj which combination gives the output:
    for (int i = 0; i < num.size(); i++)
    {
        int ans = solverec(num,x-num[i]);
        if(ans != INT_MAX){
            // 1+ because we are count the current coin also 
            mini = min(1+ans,mini);
        }
    }
    return mini;
}

// using recursion + memorization:
//TS: X*n SP: x
int solvememorization(vector<int> &num, int x, vector<int> &dp){
    if(x == 0){
        return 0;
    }
    if(x < 0){
        return INT_MAX;
    }
    if(dp[x] != -1){
        return dp[x];
    }

    int mini = INT_MAX;

    for (int i = 0; i < num.size(); i++)
    {
        int ans = solvememorization(num,x-num[i],dp);
        if(ans != INT_MAX){
            mini = min(mini,1+ans);
        }  
    }
    dp[x] = mini;
    return mini;
}


// Apporach 3: using tabularization:
//TS: x*n SP: x
int solvetable(vector<int> &num, int x){
    // for x = 7 we will store all the min ways to make each x val like 0, 1 2 3 .... 7
    vector<int> dp(x+1,INT_MAX);
    dp[0] = 0; //base case
    
    for (int i = 1; i <= x; i++)
    {
        // here we are cal. each x val till targer x
        for (int j = 0; j < num.size(); j++)
        {
            // this will be cal using all the coins present in the nums:
            if(i-num[j]>=0 && dp[i-num[j]] != INT_MAX){
                dp[i] = min(dp[i],1 + dp[i-num[j]]); // we are implement 1+ and x-num[i](removing the coin val
                //form the x)
            }
        }
    }
    return dp[x];
}

int minimumElements(vector<int> &num, int x)
{
    int n = num.size();
    // Using just recursion apporach1:
    // int ans = solverec(num,x);

    // Using dp memorization:
    // The vector size should be equal to the 
    // vector<int> dp(x+1,-1);
    // int ans = solvememorization(num,x,dp);

    //Using Tabularization:
    int ans = solvetable(num,x);
    if(ans == INT_MAX){
        return -1;
    }
    return ans;
}

//Apporach 4: Space optimization:
// Here we the current ans depents on the previous x values hence we need to create x indepentaed variables
// to solve via this apporach, hence we will end up using O(x) space , hence no need of optimization

int main(){
    vector<int> num = {1, 2, 3};
    int x = 7;
    cout<<minimumElements(num,x);
return 0;
}