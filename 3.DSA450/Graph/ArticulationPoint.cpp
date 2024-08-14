#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Find the articulation point in the graph:
 */

void dfs(int node, int parent, int &timer, vector<int> &disc, vector<bool> &vis,
         vector<vector<int>> &graph, vector<int> &low, vector<int> &ap) {
    vis[node] = true;
    disc[node] = low[node] = timer++;
    int child = 0;

    for (auto i : graph[node]) {
        if (!vis[i]) {
            dfs(i, node, timer, disc, vis, graph, low, ap);
            low[node] = min(low[node], low[i]);

            // Check if the node is an articulation point
            if (low[i] >= disc[node] && parent != -1) {
                ap[node] = 1;
            }
            child++;
        } else if (i != parent) {
            // Back edge case
            low[node] = min(low[node], disc[i]);
        }
    }

    if (parent == -1 && child > 1) {
        // Check if the root node is an articulation point
        ap[node] = 1;
    }
}

vector<int> findArticulationPoints(vector<vector<int>> &graph) {
    int n = graph.size();
    vector<int> disc(n, -1);
    vector<bool> vis(n, false);
    vector<int> low(n, -1);
    int parent = -1;
    int timer = 0;
    vector<int> ap(n, 0);

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i, parent, timer, disc, vis, graph, low, ap);
        }
    }

    // Collect the articulation points
    vector<int> articulationPoints;
    for (int i = 0; i < n; i++) {
        if (ap[i] == 1) {
            articulationPoints.push_back(i);
        }
    }

    return articulationPoints;
}

int main(){

return 0;
}