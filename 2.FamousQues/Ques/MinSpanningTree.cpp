#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
There are n cities and there are roads in between some of the cities. Somehow all the roads are damaged 
simultaneously. We have to repair the roads to connect the cities again. There is a fixed cost to repair 
a particular road. Find out the minimum cost to connect all the cities by repairing roads. Input is in 
matrix(city) form, if city[i][j] = 0 then there is not any road between city i and city j, if city[i][j] 
= a > 0 then the cost to rebuild the path between city i and city j is a. Print out the minimum cost to 
connect all the cities. 
It is sure that all the cities were connected before the roads were damaged.

Examples: 

Input : {{0, 1, 2, 3, 4},
         {1, 0, 5, 0, 7},
         {2, 5, 0, 6, 0},
         {3, 0, 6, 0, 0},
         {4, 7, 0, 0, 0}};
Output : 10
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <climits>

using namespace std;

void findCost(int n, vector<vector<int>> city) {
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int u = i;
            int v = j;
            int w = city[i][j];
            if (w != 0) { // Avoid adding zero-weight edges
                adj[u].push_back(make_pair(v, w));
                adj[v].push_back(make_pair(u, w));
            }
        } 
    }

    vector<int> keys(n, INT_MAX);
    vector<int> parent(n, -1);
    vector<bool> mst(n, false);

    keys[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < n - 1; i++) {
        int mini = INT_MAX;
        int u = -1;
        // Find the smallest in the key which is not visited
        for (int j = 0; j < n; j++) {
            if (!mst[j] && keys[j] < mini) {
                u = j;
                mini = keys[j];
            }
        }

        // Mark it visited
        mst[u] = true;
        
        for (auto it : adj[u]) {
            int v = it.first;
            int w = it.second;
            if (!mst[v] && w < keys[v]) {
                keys[v] = w;
                parent[v] = u;
            }
        }
    }
    
    // Calculate the total cost of the MST
    int cost = 0;
    for (int i = 1; i < n; i++) {
        if (parent[i] != -1) {
            cost += keys[i];
        }
    }
    cout << "Total cost of the Minimum Spanning Tree: " << cost << endl;
}

int main() {
    int n1 = 5;
    vector<vector<int>> city1 = {{0, 1, 2, 3, 4},
                                 {1, 0, 5, 0, 7},
                                 {2, 5, 0, 6, 0},
                                 {3, 0, 6, 0, 0},
                                 {4, 7, 0, 0, 0}};
    findCost(n1, city1);
    return 0;
}
