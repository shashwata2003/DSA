#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Space OPtimization:
 */


class Solution {
  public:
    int lengthOfLongestAP(vector<int>& A) {
        int n = A.size();
         if (n <= 2) {
            return n;
        } 
        int ans = 0;
        vector<vector<int>>dp(n, vector<int>(A[n-1] - A[0] + 1, 1));
        for (int i=0;i<n;i++) {
            for (int j=i+1;j<n;j++) {
                int diff = A[j] - A[i];
                dp[j][diff] = max(dp[j][diff], dp[i][diff] + 1);
                ans = max(ans, dp[j][diff]);
            }
        }
        return ans;
    }
    
};
int main(){

return 0;
}