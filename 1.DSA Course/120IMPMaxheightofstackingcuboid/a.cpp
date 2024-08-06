#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Maximum Height by Stacking Cuboids:
Given n cuboids where the dimensions of the ith cuboid is cuboids[i] = [widthi, lengthi, heighti] (0-indexed).
 Choose a subset of cuboids and place them on each other.

You can place cuboid i on cuboid j if widthi <= widthj and lengthi <= lengthj and heighti <= heightj. You can 
rearrange any cuboid's dimensions by rotating it to put it on another cuboid.

Return the maximum height of the stacked cuboids.

Input: cuboids = [[50,45,20],[95,37,53],[45,23,12]]
Output: 190
Explanation:
Cuboid 1 is placed on the bottom with the 53x37 side facing down with height 95.
Cuboid 0 is placed next with the 45x20 side facing down with height 50.
Cuboid 2 is placed next with the 23x12 side facing down with height 45.
The total height is 95 + 50 + 45 = 190.
Example 2:

Input: cuboids = [[38,25,45],[76,35,3]]
Output: 76
Explanation:
You can't place any of the cuboids on the other.
We choose cuboid 1 and rotate it so that the 35x3 side is facing down and its height is 76.
Example 3:

Input: cuboids = [[7,11,17],[7,17,11],[11,7,17],[11,17,7],[17,7,11],[17,11,7]]
Output: 102
Explanation:
After rearranging the cuboids, you can see that all cuboids have the same dimension.
You can place the 11x7 side down on all cuboids so their heights are 17.
The maximum height of stacked cuboids is 6 * 17 = 102.
 */

bool check(vector<int> b, vector<int> a){
    if(a[0] <= b[0] && a[1] <= b[1] && a[2] <= b[2]){
        return true;
    }
    return false;
}

int solveLongestIncreasing(vector<vector<int>>& cub, int n) {
    vector<int> curr(n + 1, 0);
    vector<int> next(n + 1, 0);

    for (int cur = n - 1; cur >= 0; cur--) {
        for (int prev = cur - 1; prev >= -1; prev--) {
            int taken = 0;
            // check function checks the condition about w,l and h in the question:
            if (prev == -1 || check(cub[cur], cub[prev])) {
                // as it is not size of the arr, but the max height hence adding the height
                taken = cub[cur][2] + next[cur + 1];
            }
            int nottake = next[prev + 1];
            curr[prev + 1] = max(taken,nottake);
        }
        next = curr;
    }
    return next[0];
}

int solveUsingMemorization(int n, vector<vector<int>> a, int currIndex, int ansIndex, vector<vector<int>> &dp) {
    if (currIndex == n) {
        return 0;
    }
    //+1 because we are starting the index of ans form -1 which is a invalid index.
    if (dp[currIndex][ansIndex + 1] != -1) {
        return dp[currIndex][ansIndex + 1];
    }

    // Include the current element
    int taken = 0;
    if (ansIndex == -1 || check(a[currIndex],a[ansIndex])) {
        // Including the current element in the answer, hence ansIndex becomes currIndex
        // 1+ to increment the size of the answer vector
        taken = a[currIndex][2] + solveUsingMemorization(n, a, currIndex + 1, currIndex, dp);
    }

    // Exclude the current element
    // As the current element is not included, the ansIndex remains the same and currIndex becomes currIndex + 1
    int notTaken = solveUsingMemorization(n, a, currIndex + 1, ansIndex, dp);

    dp[currIndex][ansIndex + 1] = max(taken, notTaken);
    return dp[currIndex][ansIndex + 1]; // Max of the two will be the answer
}

int maxHeight(vector<vector<int>>& cuboids) {
    // Sort each cuboid:
    for (auto& i : cuboids) {
        sort(i.begin(), i.end());
    }

    // Sort based on the width, and if equal, then height, and if equal, then depth
    sort(cuboids.begin(), cuboids.end());

    // Implement the longest increasing subsequence DP solution:
    int n = cuboids.size();
    // vector<vector<int>> dp(n,vector<int> (n+1,-1));
    return solveLongestIncreasing(cuboids,n);
}

int main(){
    vector<vector<int>> arr = {{50, 45, 20}, {95, 37, 53}, {45, 23, 12}};;
    cout<<maxHeight(arr);
return 0;
}