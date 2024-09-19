#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  */

#include <vector>
#include <algorithm>
using namespace std;

#include <vector>
#include <algorithm>
#include <climits> // For INT_MIN
using namespace std;

int solve(int n, vector<int> &coins, int x, int i, int score, bool even) {
    if (i >= n) { // Base case: if index is out of bounds
        return score;
    }

    int inclu = INT_MIN; // Initialize with a very low value to handle the maximum logic
    int exclu = INT_MIN;

    // Current level coin parity
    bool currentEven = coins[i] % 2 == 0;

    if (even) {
        // If you are on a level with even coins
        for (int j = i + 1; j < n; ++j) {
            bool nextEven = coins[j] % 2 == 0;
            if (nextEven) {
                // Move to next level with even coins without penalty
                inclu = max(inclu, solve(n, coins, x, j, score + coins[i], true));
            } else {
                // Move to next level with odd coins with penalty
                inclu = max(inclu, solve(n, coins, x, j, score + coins[i] - x, false));
            }
        }
    } else {
        // If you are on a level with odd coins
        for (int j = i + 1; j < n; ++j) {
            bool nextEven = coins[j] % 2 == 0;
            if (nextEven) {
                // Move to next level with even coins with penalty
                inclu = max(inclu, solve(n, coins, x, j, score + coins[i] - x, true));
            } else {
                // Move to next level with odd coins without penalty
                inclu = max(inclu, solve(n, coins, x, j, score + coins[i], false));
            }
        }
    }

    return max(inclu, exclu); // Return the maximum score obtainable
}

int findMaxScore(int n, vector<int> &coins, int x) {
    int i = 0;
    int score = 0;
    bool even = coins[0] % 2 == 0; // Determine the parity of the starting level

    return solve(n, coins, x, i, score, even);
}


int main(){
    vector<int> arr = {7,2,1,10};
    int n = arr.size();
    int x = 5;
    cout<<findMaxScore(n,arr,x);
return 0;
}