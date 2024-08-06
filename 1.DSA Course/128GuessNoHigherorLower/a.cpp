#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* Guess Number Higher or Lower II
We are playing the Guessing Game. The game will work as follows:

I pick a number between 1 and n.
You guess a number.
If you guess the right number, you win the game.
If you guess the wrong number, then I will tell you whether the number I picked is higher or lower, and 
you will continue guessing.
Every time you guess a wrong number x, you will pay x dollars. If you run out of money, you lose the game.
Given a particular n, return the minimum amount of money you need to guarantee a win regardless of what number 
I pick.

Example 1:
Input: n = 10
Output: 16
Explanation: The winning strategy is as follows:
- The range is [1,10]. Guess 7.
    - If this is my number, your total is $0. Otherwise, you pay $7.
    - If my number is higher, the range is [8,10]. Guess 9.
        - If this is my number, your total is $7. Otherwise, you pay $9.
        - If my number is higher, it must be 10. Guess 10. Your total is $7 + $9 = $16.
        - If my number is lower, it must be 8. Guess 8. Your total is $7 + $9 = $16.
    - If my number is lower, the range is [1,6]. Guess 3.
        - If this is my number, your total is $7. Otherwise, you pay $3.
        - If my number is higher, the range is [4,6]. Guess 5.
            - If this is my number, your total is $7 + $3 = $10. Otherwise, you pay $5.
            - If my number is higher, it must be 6. Guess 6. Your total is $7 + $3 + $5 = $15.
            - If my number is lower, it must be 4. Guess 4. Your total is $7 + $3 + $5 = $15.
        - If my number is lower, the range is [1,2]. Guess 1.
            - If this is my number, your total is $7 + $3 = $10. Otherwise, you pay $1.
            - If my number is higher, it must be 2. Guess 2. Your total is $7 + $3 + $1 = $11.
The worst case in all these scenarios is that you pay $16. Hence, you only need $16 to guarantee a win.
Example 2:

Input: n = 1
Output: 0
Explanation: There is only one possible number, so you can guess 1 and not have to pay anything.
Example 3:

Input: n = 2
Output: 1
Explanation: There are two possible numbers, 1 and 2.
- Guess 1.
    - If this is my number, your total is $0. Otherwise, you pay $1.
    - If my number is higher, it must be 2. Guess 2. Your total is $1.
The worst case is that you pay $1.
 */

int solveusingrecursion( int s, int e){
    if(s>=e){
        //Checking if the pointers overlap 
        return 0;
    }
    int ans = INT_MAX;
    for (int i = s; i < e; i++)
    {  
        // traverse each element in the range and find its ans, the min of all will the final ans 
        // Check notes
        ans = min(ans,i+max(solveusingrecursion(s,i-1),solveusingrecursion(i+1,e)));
    }
    return ans;
}

//Using recursion + memorization: 
int solveusingmemorization( int s, int e, vector<vector<int>> &dp){
    if(s>=e){
        return 0;
    }
    if(dp[s][e] != -1){
        return dp[s][e];
    }
    int ans = INT_MAX;
    for (int i = s; i < e; i++)
    {
        ans = min(ans,i+max(solveusingmemorization(s,i-1,dp),solveusingmemorization(i+1,e,dp)));
    }
    return dp[s][e] = ans;
}

//TS: O(n2) SP:O(n2)
int solveusingtabulation(int n){
    vector<vector<int>> dp(n+2,vector<int>(n+2,0)); // Base case is handle by the init

    for (int start = n; start >= 1; start--)
    {
        for (int end = start; end <= n; end++)
        {
            if(start == end){
                continue; //as the base case is already handled in the init
            }else{
                int ans = INT_MAX;
                for (int i = start; i <= end; i++)
                {
                    ans = min(ans,i+max(dp[start][i-1],dp[i+1][end]));
                }
                dp[start][end] = ans;
            }
        }
    }
    return dp[1][n];// return the first indexs which we send in the recursion and memorization
}

int getMoneyAmount(int n) {
    int start = 1 , end = n;

    //Using only recursion:
    // int ans = solveusingrecursion(start,end);

    //Using memorization:
    // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    // int ans = solveusingmemorization(start,end,dp);

    //Using tabulation:
    int ans = solveusingtabulation(n);

    //Using space optimization:
    // we cannot implement space optimzation here as the ans depends upons whole range of 1 to n
    // as ans -> [s][i-1] and [i+1][e] hence no space opti
    return ans;
}

int main(){
    int n = 10;
    cout<<getMoneyAmount(n);
return 0;
}