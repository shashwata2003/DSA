#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
City With the Smallest Number of Neighbors at a Threshold Distance:
There are n cities labeled from 0 to n-1 with m edges connecting them. Given the array edges where 
edges[i] = [fromi , toi ,weighti]  represents a bidirectional and weighted edge between cities fromi 
and toi, and given the integer distanceThreshold. You need to find out a city with the smallest number 
of cities that are reachable through some path and whose distance is at most Threshold Distance. If there 
are multiple such cities, our answer will be the city with the greatest label.

Note: The distance of a path connecting cities i and j is equal to the sum of the edge's weights along 
that path.

Example 1:

Input:
n = 4, m = 4
edges = [[0, 1, 3],
         [1, 2, 1], 
         [1, 3, 4],  
         [2, 3, 1]]
distanceThreshold = 4
Output:
3 */

class Solution {
public:
    /*
    Steps:
    1. find the shortest distance between all the points 
    2. now traverse each of the distances and find the distances less than or equal to the threshold
    */
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        for (auto& edge : edges) {
            dist[edge[0]][edge[1]] = edge[2];
            dist[edge[1]][edge[0]] = edge[2];
        }

        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        int cntcity = n;
        int city = -1;
        //i = city 
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            //j  = adj city
            for (int j = 0; j < n; j++) {
                if (i != j && dist[i][j] <= distanceThreshold) {
                    cnt++;
                }
            }
            if (cnt <= cntcity) {
                cntcity = cnt;
                city = i;
            }
        }
        return city;
    }
};

int main(){

return 0;
}