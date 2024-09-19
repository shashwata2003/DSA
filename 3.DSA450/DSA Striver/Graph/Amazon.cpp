#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  */
int solve(int N, vector<int>& A) {
    if (N == 1) return 0;  // Already at the last brick

    // Create a map to store the positions of each value (0-9)
    unordered_map<int, vector<int>> value_map;
    for (int i = 0; i < N; i++) {
        value_map[A[i]].push_back(i);
    }

    // Queue for BFS: stores the current position and the number of moves
    queue<pair<int, int>> q;
    q.push({0, 0});  // Start from the first brick (index 0, 0 moves made)

    // Visited array to mark which bricks have been visited
    vector<bool> visited(N, false);
    visited[0] = true;

    // Set to keep track of which value groups have already been used for jumping
    unordered_set<int> used_values;

    while (!q.empty()) {
        int idx = q.front().first;
        int moves = q.front().second;
        q.pop();

        // If we have reached the last brick, return the number of moves
        if (idx == N - 1) return moves;

        // Move to the next brick (i + 1)
        if (idx + 1 < N && !visited[idx + 1]) {
            q.push({idx + 1, moves + 1});
            visited[idx + 1] = true;
        }

        // Move to the previous brick (i - 1)
        if (idx - 1 >= 0 && !visited[idx - 1]) {
            q.push({idx - 1, moves + 1});
            visited[idx - 1] = true;
        }

        // Move to any brick with the same value as A[idx]
        if (used_values.find(A[idx]) == used_values.end()) {
            for (int same_value_idx : value_map[A[idx]]) {
                if (!visited[same_value_idx]) {
                    q.push({same_value_idx, moves + 1});
                    visited[same_value_idx] = true;
                }
            }
            // Mark this value group as used
            used_values.insert(A[idx]);
        }
    }

    // If we somehow don't reach the last brick, return -1 (shouldn't happen)
    return -1;
}

int main(){
    vector<int> arr = {1,2,3,4,5,1,6,7,8,5};
    int n = arr.size();
    cout<<solve(n,arr);
return 0;
}