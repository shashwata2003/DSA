#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Buttom up appraoch:

This is also giving TLE

It can be done by using SPace optimization:
TS: O(n2) SP: O(n2)
 */

int lengthOfLongestAP(vector<int>& arr) {
    //base case:
    int n = arr.size();
    if(n<=2){
        return n;
    }

    int ans = 0;
    unordered_map<int,int> dp[n+1];

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            // J is moving in the opp. direction:
            int diff = arr[i] - arr[j]; // ans i will always be ahead in the arr unlike the previous apporach
            // here j is moving back from 0 to i not from i to end
            int cnt = 1; // 1 because in the ap seq the curr element will also be added

            if(dp[j].count(diff)){
                cnt = dp[j][diff];
            }
            dp[i][diff] = 1 + cnt;
            ans  = max(ans,dp[i][diff]);
        }
        
    }
    return ans;
}

int main(){
    vector<int> arr = {1, 7, 10, 13, 14, 19};
    cout<<lengthOfLongestAP(arr);
return 0;
}