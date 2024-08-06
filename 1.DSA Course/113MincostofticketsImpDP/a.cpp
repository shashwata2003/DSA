#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
 Ninja's Trip:
Ninja is willing to take some time off from his training and planning a year-long tour. 
You are given a DAYS array consisting of ‘N’ days when Ninjas will be traveling during the year. 
Each Day is an integer between 1 to 365 (both inclusive). Train tickets are sold in three different ways:
A 1-day pass is sold for 'COST'[0] coins,
A 7-day pass is sold for 'COST'[1] coins, and
A 30-day  pass is sold for 'COST'[2] coins.
The passes allow for many days of consecutive travel.
Your task is to help the Ninja to find the minimum number of coins required to complete his tour.

Sample Input 1:
2
2 
2 5
1 4 25    
7
1 3 4 5 7 8 10
2 7 20
Sample Output 1:
2
11
 */

//Using only recursion: TS: exponiatial
int solveusingrecursion(int n, vector<int> days, vector<int> cost, int st){
    if(st >= n){
        return 0;
    }
    
    //one day pass: hence we start the recursion in the next element:
    int op1 = cost[0] + solveusingrecursion(n,days,cost,st+1);

    //7 day pass
    int i;
    // we need to take the ith pointer to the +7 index from the current day eg:
    // if we are at 3 then we need to take till 10 in that days array.
    for( i = st; i<n && days[i] < days[st] + 7; i++);
    int op2 = cost[1] + solveusingrecursion(n,days,cost,i);

    //30 day pass:
    for(i = st; i<n && days[i] < days[st] + 30; i++);
    int op3 = cost[2] + solveusingrecursion(n,days,cost,i);

    int ans = min(op1,min(op2,op3));
    return ans;
}

//Using memorization: Ts: O(n) SP: O(n)
int solveusingmemorization(int n, vector<int> days, vector<int> cost, int st,vector<int> &dp){
    if(st >= n){
        return 0;
    }

    if(dp[st] != -1){
        return dp[st];
    }
    //one day pass: hence we start the recursion in the next element:
    int op1 = cost[0] + solveusingmemorization(n,days,cost,st+1,dp);

    //7 day pass
    int i;
    // we need to take the ith pointer to the +7 index from the current day eg:
    // if we are at 3 then we need to take till 10 in that days array.
    for( i = st; i<n && days[i] < days[st] + 7; i++);
    int op2 = cost[1] + solveusingmemorization(n,days,cost,i,dp);

    //30 day pass:
    for(i = st; i<n && days[i] < days[st] + 30; i++);
    int op3 = cost[2] + solveusingmemorization(n,days,cost,i,dp);

    dp[st] = min(op1,min(op2,op3));
    return dp[st];
}

//Using tabulation: Ts: O(n) SP: O(n)
int solveusingtabulation(int n, vector<int> days, vector<int> cost){
    vector<int> dp(n+1,INT_MAX);
    dp[n] = 0;

    //As it is a buttom up apporach we will start form the back of the array
    for (int k = n-1; k >= 0; k--)
    {
        //one day pass: hence we start the recursion in the next element:
        int op1 = cost[0] + dp[k+1];

        //7 day pass
        int i;
        // we need to take the ith pointer to the +7 index from the current day eg:
        // if we are at 3 then we need to take till 10 in that days array.
        for( i = k; i<n && days[i] < days[k] + 7; i++);
        int op2 = cost[1] + dp[i];

        //30 day pass:
        for(i = k; i<n && days[i] < days[k] + 30; i++);
        int op3 = cost[2] + dp[i];

        dp[k] = min(op1,min(op2,op3));
    }
    return dp[0];
}

//Using Space optimization:
/* Here we are going to use two queue for weekly and monthly pass, Not for days because we can easily estimate 
that by adding 1 to the ans, 
->Another question comes if we are using queue then how the space complexity is constant, it is constant as 
we know the exect size of both the queue as weekly will be 7 and monthly will be 30. Hnece constant
-> the queue will me made for a pair of days and cost
-> Now we will traverse the days array and remove all the expired days from the montly and weekly queue
Expires means that which ever day we are standing on current + 30, remove all the days after this and before 
the current same go for the weekly queue
-> now we will push the pair of current cost(including the cost for the current element) and the current day
-> Update the ans , which will be init ad int_max
ans = min(ans+cost[0],min(montly.front.second, weekly.front.second))
return ans;

TS: O(n) SP: O(1);
*/
int solveusingspaceoptimization(int n, vector<int> days, vector<int> cost){
    int ans = 0;
    //pair< day, cost>
    queue<pair<int,int>> weeks;
    queue<pair<int,int>> months;

    for(int day : days){
        //Removing expired days
        while (!months.empty() && months.front().first + 30 <= day)
        {
           months.pop();
        }
        while (!weeks.empty() && weeks.front().first + 7 <= day)
        {
           weeks.pop();
        }

        //step 2: push cost 
        weeks.push(make_pair(day,ans+cost[1]));
        months.push(make_pair(day,ans+cost[2]));

        //Updating the ans:
        ans = min(ans+cost[0],min(weeks.front().second,months.front().second));

        
    }
    return ans;
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    int i = 0;
    //using recursion only:
    // int ans = solveusingrecursion(n,days,cost,i);

    //Using memorization:
    // vector<int> dp(n+1,-1);
    // int ans = solveusingmemorization(n,days,cost,i,dp);

    //using tabulation:
    // int ans = solveusingtabulation(n,days,cost,i);

    //Using Space optimizatio:
    int ans = solveusingspaceoptimization(n,days,cost);

    return ans;
}

int main(){
    vector<int> days = {1, 3, 4, 5, 7, 8, 10};
    int n = days.size();
    vector<int> cost = {2,7,20};
    cout<<minimumCoins(n,days,cost);
return 0;
}