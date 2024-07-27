#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Dice throw
Given N dice each with M faces, numbered from 1 to M, find the number of ways to get sum X. X is the 
summation of values on each face when all the dice are thrown.

Example 1:
Input:
M = 6, N = 3, X = 12
Output:
25
Explanation:
There are 25 total ways to get
the Sum 12 using 3 dices with
faces from 1 to 6.

Example 2:
Input:
M = 2, N = 3, X = 6
Output:
1
Explanation:
There is only 1 way to get
the Sum 6 using 3 dices with
faces from 1 to 2. All the
dices will have to land on 2.
 */

long long solveusingrecursion(int faces, int dices , int target){
    if(target < 0){
        // if the target becomes negative
        return 0;
    }
    if( dices == 0 && target != 0){
        // if the no. of dices to be used are 0 and the target is not met
        return 0;
    }
    if(target == 0 && dices != 0){
        // if target becomes zero and the dices are still left
        return 0;
    }
    if(target == 0 && dices == 0){
        // both the target gets 0 and the dices henc increment the count:
        return 1;
    }

    long long ans = 0;
    for (int i = 1; i <=  faces; i++)
    {
        //traversing each faces and finding the ans.
        // as one dice is used hence -1 and the target will also be reduced by the index of the face of the
        //dice
        ans = ans + solveusingrecursion(faces,dices-1,target-i);
    }
    return ans;   
}

int solveusingmemorization(int faces, int dices, int target, vector<vector<long long>> &dp){
    if(target < 0){
        // if the target becomes negative
        return 0;
    }
    if( dices == 0 && target != 0){
        // if the no. of dices to be used are 0 and the target is not met
        return 0;
    }
    if(target == 0 && dices != 0){
        // if target becomes zero and the dices are still left
        return 0;
    }
    if(target == 0 && dices == 0){
        // both the target gets 0 and the dices henc increment the count:
        return 1;
    }

    if(dp[dices][target] != -1){
        return dp[dices][target];
    }

    long long ans = 0;
    for (int i = 1; i <=  faces; i++)
    {
        //traversing each faces and finding the ans.
        // as one dice is used hence -1 and the target will also be reduced by the index of the face of the
        //dice
        ans = ans + solveusingmemorization(faces,dices-1,target-i,dp);
    }
    dp[dices][target] = ans;
    return dp[dices][target];  
}

long long solveusingtabulation(int faces, int dices, int target) {
    vector<vector<long long>> dp(dices + 1, vector<long long>(target + 1, 0));
    dp[0][0] = 1;

    for (int dice = 1; dice <= dices; dice++) {
        for (int tar = 1; tar <= target; tar++) {
            long long ans = 0;
            for (int i = 1; i <= faces; i++) {
                if (tar - i >= 0) {
                    ans += dp[dice - 1][tar - i];
                }
            }
            dp[dice][tar] = ans;
        }
    }
    return dp[dices][target];
}

// SP:O(X)
long long solveusingspaceoptimization(int faces, int dices, int target){
    vector<int> curr(target+1,0); //dice
    vector<int> prev(target+1,0); //dice-1
    prev[0] = 1;

    for (int dice = 1; dice <= dices; dice++) {
        for (int tar = 1; tar <= target; tar++) {
            long long ans = 0;
            for (int i = 1; i <= faces; i++) {
                if (tar - i >= 0) {
                    ans += prev[tar - i];
                }
            }
            curr[tar] = ans;
        }
        prev = curr;
    }
    return curr[target];
}

long long noOfWays(int M , int N , int X) {
    //Using recursion:
    // long long ans = solveusingrecursion(M,N,X);

    //Using memorization:
    // vector<vector<long long>> dp(N+1,vector<long long>(X+1,-1));
    // long long ans = solveusingmemorization(M,N,X,dp);

    //Using buttom up tabulation:
    // long long ans = solveusingtabulation(M,N,X);
    // return ans;

    //USing space optimization:
    //Here the curr ans depents upon the dice+1 and target -1, we can just use dice and dice+1 rows to find
    // the entire ans:
    long long ans = solveusingspaceoptimization(M,N,X);
}

int main(){
    int m =6, n = 3, x = 12;
    cout<<noOfWays(m,n,x);
return 0;
}