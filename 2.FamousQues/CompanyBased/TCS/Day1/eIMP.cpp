/*Question 2:
You have planned your visits to a recreational park one year in advance. The days of the year on which you will visit the park are given as an integer array visitDays. Each day is an integer from 1 to 365. 
Membership passes for the park are sold in three different ways:

A 1-day pass is sold for membershipCosts[0] dollars.
A 7-day pass is sold for membershipCosts[1] dollars.
A 30-day pass is sold for membershipCosts[2] dollars.


The passes allow that many days of consecutive park visits. For example, if you get a 7-day pass on day 2, you can visit the park for 7 days: 2, 3, 4, 5, 6, 7, 8. 
Return the minimum number of dollars you need to spend to cover all your planned park visits given in the list visitDays.

Example 

Input:
visitDays = {1, 4, 6, 7, 8, 20}
membershipCosts = {2, 7, 15}
Output: 
11
Explanation: 
Here is one way to buy passes that cover your visit plan:
On day 1, you buy a 1-day pass for membershipCosts[0] = $2, which covers day 1.
On day 3, you buy a 7-day pass for membershipCosts[1] = $7, which covers days 3, 4, ..., 9.
On day 20, you buy a 1-day pass for membershipCosts[0] = $2, which covers day 20.
In total, you spent $11 and covered all the days of your park visits.



Company Tags: Google, Microsoft

Input format :
The first line of input consists of an integer N, representing the number of days planned to visit the park.

The second line consists of N integers, each representing visiting days, in strictly increasing order.

The third line consists of three space-separated integers, representing the membership cost of 1-day, 7-day, and 30-day passes, respectively.

Output format :
The output prints the minimum number of dollars that need to be spent to cover all the planned park visits.



Refer to the sample output for formatting specifications.

Code constraints :
1 ≤ N ≤ 365

1 ≤ visiting days ≤ 365

1 ≤ membershipCosts[i] ≤ 1000

Sample test cases :
Input 1 :
6
1 4 6 7 8 20
2 7 15
Output 1 :
11
Input 2 :
12
1 2 3 4 5 6 7 8 9 10 30 31
2 7 15
Output 2 :
17
*/

#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  */

class Solution {
private:
    int dfs(int i, int n, vector<int> &durations,vector<int>& days, vector<int>& costs){
        if(i>=n){
            return 0;
        }
        int mincost = INT_MAX;
        for(int k = 0; k<3; k++){
            int j = lower_bound(days.begin(), days.end(), durations[k]+days[i]) - days.begin();
            mincost = min(mincost,costs[k] + dfs(j,n,durations,days,costs));
        }
        return mincost;
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> durations = {1,7,30};
        int i = 0;
        int n = days.size();
        return dfs(i,n,durations,days,costs);
    }
};


//Using memorization:
class Solution {
private:
    int dfs(int i, int n, vector<int> &durations,vector<int>& days, vector<int>& costs,vector<int> &dp){
        if(i>=n){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int mincost = INT_MAX;
        for(int k = 0; k<3; k++){
            int j = lower_bound(days.begin(), days.end(), durations[k]+days[i]) - days.begin();
            mincost = min(mincost,costs[k] + dfs(j,n,durations,days,costs,dp));
        }
        return dp[i]=mincost;
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> durations = {1,7,30};
        int i = 0;
        int n = days.size();
        vector<int> dp(n, -1);
        return dfs(i,n,durations,days,costs,dp);
    }
};

int main(){

return 0;
}