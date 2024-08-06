#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Reducing Dishes:
A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.

Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes 
multiplied by its satisfaction level i.e. time[i] * satisfaction[i].

Return the maximum sum of like-time coefficient that the chef can obtain after preparing some amount of dishes.

Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.

 

Example 1:
Input: satisfaction = [-1,-8,0,5,-9]
Output: 14
Explanation: After Removing the second and last dish, the maximum total like-time coefficient will be equal to (-1*1 + 0*2 + 5*3 = 14).
Each dish is prepared in one unit of time.

Example 2:
Input: satisfaction = [4,3,2]
Output: 20
Explanation: Dishes can be prepared in any order, (2*1 + 3*2 + 4*3 = 20)

Example 3:
Input: satisfaction = [-1,-4,-5]
Output: 0
Explanation: People do not like the dishes. No dish is prepared.

 */

//Using just recursion:
int solveusingrecursion(vector<int>& sat, int index, int time){
    int size = sat.size();
    if(index == size){
        //out of bound
        return 0;
    }

    int include = sat[index]*(time+1) + solveusingrecursion(sat,index+1,time+1);
    int exclude = 0 + solveusingrecursion(sat,index+1, time);

    return max(include,exclude);
}

//using recursion+memorization:
int solveusingmemorization(vector<int>& sat, int index, int time, vector<vector<int>> &dp){
    int size = sat.size();
    if(index == size){
        //out of bound
        return 0;
    }
    if(dp[index][time] != -1){
        return dp[index][time];
    }
    int include = sat[index]*(time+1) + solveusingmemorization(sat,index+1,time+1,dp);
    int exclude = 0 + solveusingmemorization(sat,index+1, time,dp);
    dp[index][time] = max(include,exclude);
    return dp[index][time];
}

//Using tabulation: Sp: O(n2)
int solveusingtabulation(vector<int> &sat){
    int n = sat.size();
    //Init at 0 hence the base case is covered:
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    
    //starting from n -1 becase n is already set
    for (int index = n-1; index >= 0; index--)
    {
        for (int time = index; time >= 0 ; time--)
        {
            int include = sat[index]*(time+1) + dp[index+1][time+1];
            int exclude = 0 + dp[index+1][time];
            dp[index][time] = max(include,exclude);
        }
        
    }
    
    //final ans will be stored in dp[0][0] as we are implementing buttom up apporach:
    return dp[0][0];
}

//Space optimizied: O(n);
int solveusingspaceopti(vector<int> &sat){
    int n = sat.size();
    vector<int> curr(n+1,0); // index
    vector<int> next(n+1,0); // Index +1
     //starting from n -1 becase n is already set
    for (int index = n-1; index >= 0; index--)
    {
        for (int time = index; time >= 0 ; time--)
        {
            int include = sat[index]*(time+1) + next[time+1];
            int exclude = 0 + next[time];
            curr[time] = max(include,exclude);
        }
        next  = curr;
    }
    
    //final ans will be stored in dp[0][0] as we are implementing buttom up apporach:
    return next[0];
}

int maxSatisfaction(vector<int>& satisfaction) {
    int index = 0 , time = 0;
    int n = satisfaction.size();
    sort(satisfaction.begin(),satisfaction.end());
    //Using recursion:
    // int ans = solveusingrecursion(satisfaction,index, time);  

    //using memorization:
    // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    // int ans = solveusingmemorization(satisfaction,index,time,dp);    

    //Using buttom up apporach in tabulation:
    // int ans = solveusingtabulation(satisfaction);

    //Using space optimization:
    //the final ans depends upon index+1 time+1 and index+1 time 
    // hence we need two rows to find the ans:
    int ans = solveusingspaceopti(satisfaction);

    return ans;  
}

int main(){
    vector<int> arr = {-1,-8,0,5,-9};
    cout<<maxSatisfaction(arr);
return 0;
}