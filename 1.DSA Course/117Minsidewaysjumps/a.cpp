#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Minimum Sideway Jumps:
There is a 3 lane road of length n that consists of n + 1 points labeled from 0 to n. 
A frog starts at point 0 in the second lane and wants to jump to point n. However, there could be obstacles
along the way.

You are given an array obstacles of length n + 1 where each obstacles[i] (ranging from 0 to 3) describes an
 obstacle on the lane obstacles[i] at point i. If obstacles[i] == 0, there are no obstacles at point i. There
  will be at most one obstacle in the 3 lanes at each point.

For example, if obstacles[2] == 1, then there is an obstacle on lane 1 at point 2.
The frog can only travel from point i to point i + 1 on the same lane if there is not an obstacle on the 
lane at point i + 1. To avoid obstacles, the frog can also perform a side jump to jump to another lane 
(even if they are not adjacent) at the same point if there is no obstacle on the new lane.

For example, the frog can jump from lane 3 at point 3 to lane 1 at point 3.
Return the minimum number of side jumps the frog needs to reach any lane at point n starting from lane 2 
at point 0.

Note: There will be no obstacles on points 0 and n.

eg:
Input: obstacles = [0,1,2,3,0]
Output: 2 
Explanation: The optimal solution is shown by the arrows above. There are 2 side jumps (red arrows).
Note that the frog can jump over obstacles only when making side jumps (as shown at point 2).

Input: obstacles = [0,1,1,3,3,0]
Output: 0
Explanation: There are no obstacles on lane 2. No side jumps are required.

Input: obstacles = [0,2,1,0,3,0]
Output: 2
Explanation: The optimal solution is shown by the arrows above. There are 2 side jumps.
 */

int solveusingrecursion(vector<int>& obs, int n,int currpos, int currlane){
    if(currpos == n-1){
        return 0;
    }

    // can we move straigth:
    if(obs[currpos+1] != currlane){
        //move the pos to the next one on the same lane as there is not obs
        return solveusingrecursion(obs,n,currpos+1,currlane);
    }
    else{
        // as the same lane has a obs at next pos we need to jump
        int ans =INT_MAX;
        //we have only three option
        for (int i = 1; i <= 3; i++)
        {
            // checking that we should not move straight and checking that the lane we are going to jump should
            //not have any obs:
            if(currlane != i && obs[currpos] != i){
                //finding the min jumps so :
                // also the pos will not change just the lane:
                // and +1 to increment the jump
                ans = min(ans,1+solveusingrecursion(obs,n,currpos,i));
            }
        }
        return ans;
    }
}

int solveusingmemorization(vector<int>& obs, int n,int currpos, int currlane, vector<vector<int>> &dp){
    if(currpos == n-1){
        return 0;
    }

    if(dp[currpos][currlane] != -1){
        return dp[currpos][currlane];
    }

    // can we move straigth:
    if(obs[currpos+1] != currlane){
        //move the pos to the next one on the same lane as there is not obs
        dp[currpos][currlane] = solveusingmemorization(obs,n,currpos+1,currlane,dp);
    }
    else{
        // as the same lane has a obs at next pos we need to jump
        int ans =INT_MAX;
        //we have only three option
        for (int i = 1; i <= 3; i++)
        {
            // checking that we should not move straight and checking that the lane we are going to jump shoul
            //not have any obs:
            if(currlane != i && obs[currpos] != i){
                //finding the min jumps so :
                // also the pos will not change just the lane:
                // and +1 to increment the jump
                ans = min(ans,1+solveusingmemorization(obs,n,currpos,i,dp));
            }
        }
        dp[currpos][currlane] = ans;
        return dp[currpos][currlane];
    }
}

int solveusingtabulation(vector<int>& obs, int n) {
    vector<vector<int>> dp(4, vector<int>(n + 1, INT_MAX));

    // Initialize the end position for all lanes
    dp[1][n] = 0;
    dp[2][n] = 0;
    dp[3][n] = 0;

    // Traverse each lane and position from the end to the start
    for (int currpos = n - 1; currpos >= 0; currpos--) {
        for (int currlane = 1; currlane <= 3; currlane++) {
            // If the current lane is not blocked
            if (currlane != obs[currpos + 1]) {
                dp[currlane][currpos] = dp[currlane][currpos + 1];
            } else {
                // Calculate the minimum jumps required to switch lanes
                int ans = INT_MAX;
                for (int i = 1; i <= 3; i++) {
                    if (currlane != i && obs[currpos] != i) {
                        // Here we need to check currpos+1 because when we are traversing the dp buttom up :
                        // we are check forn i = 1 so conside:
                        // we are i = 2 and i = 1 has a obs and curpos+1 also has a opt
                        // so we jumped to i = 3 but i = 3 for currpos is not calculated yet as we have not 
                        // reached there yet and it is INTMAX there so we check the next box of it that is
                        // [i,pos+1]
                        ans = min(ans, 1 + dp[i][currpos + 1]);
                    }
                }
                dp[currlane][currpos] = ans;
            }
        }
    }

    // Return the minimum jumps required to reach the start from lane 2
    //As we have ans for all three of them, we need to find the min of the tree
    // But as we need to end in lane 2 only so we need to add 1 to both the ans for lane 1 and 3
    return min(dp[2][0], min(1 + dp[1][0], 1 + dp[3][0]));
}
//SP: O(1)
int solveusingspaceopti(vector<int>& obs, int n) {
    vector<int> curr(4, INT_MAX); // currpos
    vector<int> next(4, INT_MAX); // currpos + 1

    // Initialize the end position for all lanes
    next[1] = 0;
    next[2] = 0;
    next[3] = 0;

    for (int currpos = n - 1; currpos >= 0; currpos--) {
        for (int currlane = 1; currlane <= 3; currlane++) {
            // If the current lane is not blocked
            if (currlane != obs[currpos + 1]) {
                curr[currlane] = next[currlane];
            } else {
                // Calculate the minimum jumps required to switch lanes
                int ans = INT_MAX;
                for (int i = 1; i <= 3; i++) {
                    if (currlane != i && obs[currpos] != i) {
                        ans = min(ans, 1 + next[i]);
                    }
                }
                curr[currlane] = ans;
            }
        }
        // Update the next position with the current position values
        next = curr;
    }

    // Return the minimum jumps required to reach the start from lane 2
    return min(next[2], min(1 + next[1], 1 + next[3]));
}

int minSideJumps(vector<int>& obstacles) {
    //Obstacles array consists of which lane the obtacle is and index of the vector tells the pos
    int n = obstacles.size();
    //Using recursion only:
    int currpos = 0, currlane = 2;
    // int ans = solveusingrecursion(obstacles,n,currpos,currlane);

    //using memorization:
    //dp: lane * obs
    // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    // int ans = solveusingmemorization(obstacles,n,currpos,currlane,dp);

    //Using tabulation:
    // int ans = solveusingtabulation(obstacles,n);

    //Using Space Optimization:
    // Here the ans depends in the two cols for the current pos as:
    //dp[currlane][pos+1] and dp[i][pos+1] hence depends on 4 lanes and 2 cols 
    // Matrix will be of 4*2
    int ans = solveusingspaceopti(obstacles,n);

    return ans;        
}

int main(){
    vector<int> obs = {0,1,2,3,0};
    cout<<minSideJumps(obs);
return 0;
}