#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Friends Pairing Problem:
Given N friends, each one can remain single or can be paired up with some other friend. 
Each friend can be paired only once. Find out the total number of ways in which friends can remain 
single or can be paired up.
Note: Since answer can be very large, return your answer mod 10^9+7.


Example 1:

Input:N = 3
Output: 4
Explanation:
{1}, {2}, {3} : All single
{1}, {2,3} : 2 and 3 paired but 1 is single.
{1,2}, {3} : 1 and 2 are paired but 3 is single.
{1,3}, {2} : 1 and 3 are paired but 2 is single.
Note that {1,2} and {2,1} are considered same.
Example 2: 

Input: N = 2
Output: 2
Explanation:
{1} , {2} : All single.
{1,2} : 1 and 2 are paired.
 */

/*
For n-th person there are two choices:1) n-th person remains single, 
we recur for f(n – 1)2) n-th person pairs up with any of the remaining n – 1 persons. 
We get (n – 1) * f(n – 2)Therefore we can recursively write f(n) as:
f(n) = f(n – 1) + (n – 1) * f(n – 2)
*/

int solve(int n){
    if(n <= 0){
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 2;
    }
    int ans = solve(n-1) + (n-1) * solve(n-2);
    return ans;
}

int countFriendsPairings(int n) 
{ 
    int ans = solve(n);
    return ans;
}

int main(){
    int n = 3;
    cout<<countFriendsPairings(n);
return 0;
}