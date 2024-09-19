#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
The problem is to find the shortest distances between every pair of vertices in a given edge-weighted 
directed graph. The graph is represented as an adjacency matrix of size n*n. Matrix[i][j] denotes the 
weight of the edge from i to j. If Matrix[i][j]=-1, it means there is no edge from i to j.
Note : Modify the distances for every pair in-place.
 */

/*
Steps:
1. Set all the self distance like 0-0 1-1 2-2 to zero and the empty place to 1e9 or max
2. find the difference distance by traversing each mid point b/w i and j
3. set all the 1e9 back to -1
*/

void shortest_distance(vector<vector<int>>& matrix) {
    //as matrix is sq matrix
    int n = matrix.size();

    // Set diagonal to zero and replace -1 with a large value
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == -1) {
                matrix[i][j] = INT_MAX;
            }
            if (i == j) {
                matrix[i][j] = 0;
            }
        }
    }

    // Update the distances using Floyd-Warshall algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][k] != INT_MAX && matrix[k][j] != INT_MAX) {
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }
    }

    // Reset large values back to -1
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == INT_MAX) {
                matrix[i][j] = -1;
            }
        }
    }
}

int main(){

return 0;
}