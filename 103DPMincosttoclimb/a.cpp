#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Count Ways To Reach The N-th Stairs:
You have been given a number of stairs. Initially, you are at the 0th stair, and you need to reach the Nth 
stair.Each time, you can climb either one step or two steps.
You are supposed to return the number of distinct ways you can climb from the 0th step to the Nth step.



Sol:
Apporach 1:
using Recursion

Apporach 2:
Top down: Recursion and memorization

Apporach 3:
Buttom up tabluar

Sample Input 2 :
2
4
5
Sample Output 2 :
5
8

*/


//In question it is mentioned to find the mod of the final ans
#define MOD 10000000007;


// Using resursion apporach 1:
int solve(long long stairs, int st){

    if(st == stairs){
        return 1;
    }
    if(st > stairs){
        return 0;
    }

    return (solve(stairs,st+1)+solve(stairs,st+2)) % MOD;
}

int countstairsrecursion(long long stairs){
    int start = 0;
    int ans = solve(stairs, start);
    return ans;
}

// Apporach 2: Using top down:

int main(){
    long long stairs = 5;
    cout<<countstairsrecursion(stairs);
return 0;
}