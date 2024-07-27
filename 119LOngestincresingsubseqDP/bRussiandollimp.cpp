#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* Russian Doll Envelopes:
You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the 
height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope are greater than 
the other envelope's width and height.

Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).

Note: You cannot rotate an envelope.
Also u cannot same length and width envolope.

Example 1:

Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
Example 2:

Input: envelopes = [[1,1],[1,1],[1,1]]
Output: 1
 */

// Comparison function to sort the envelopes
bool compare(const vector<int>& a, const vector<int>& b) {
    if (a[0] == b[0]) {
        return a[1] > b[1];
    }
    return a[0] < b[0];
}

int solveUsingDpUsingBinary(vector<vector<int>>& env, int n) {
    if (n == 0) {
        return 0;
    }
    // Sort on the basis of width and if the same, then push the larger height element first
    sort(env.begin(), env.end(), compare);

    // Implement the longest increasing subsequence on the height
    vector<int> ans;
    ans.push_back(env[0][1]);  // Initialize with the first height

    for (int i = 1; i < n; i++) {  // Start from 1 because ans is initialized with env[0][1]
        if (env[i][1] > ans.back()) {
            ans.push_back(env[i][1]);
        } else {
            int index = lower_bound(ans.begin(), ans.end(), env[i][1]) - ans.begin();
            ans[index] = env[i][1];
        }
    }
    return ans.size();
}

int maxEnvelopes(vector<vector<int>>& envelopes) {
    int n = envelopes.size();
    int ans = solveUsingDpUsingBinary(envelopes,n);
}

int main(){
    vector<vector<int>> arr = {{5,4},{6,4},{6,7},{2,3}};
    cout<<maxEnvelopes(arr);
return 0;
}