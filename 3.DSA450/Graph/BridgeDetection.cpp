#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Bridges In A Graph:
Given an undirected graph of V vertices and E edges. Your task is to find all the bridges in the 
given undirected graph. A bridge in any graph is defined as an edge which, when removed, makes the graph 
disconnected (or more precisely, increases the number of connected components in the graph).
Sample Input 1 :
2
5 4
0 1
3 1
1 2
3 4
3 3
0 1
1 2
2 0
Sample Output 1 :
4
0 1
1 2    
1 3
3 4
0
 */

/*using DFS: 
Need data types:
1. vis
2. low
3. discovery

*/

void dfs(int node, int &timer, int parent, vector<int> &low, vector<int> &disc, unordered_map<int, bool> &vis,
         unordered_map<int, list<int>> &adj, vector<vector<int>> &ans) {
    vis[node] = true;
    low[node] = disc[node] = timer;
    timer++;

    for (auto i : adj[node]) {
        // Ignore the parent node
        if (parent == i) {
            continue;
        }
        // Check for unvisited node
        else if (!vis[i]) {
            dfs(i, timer, node, low, disc, vis, adj, ans);
            // For every adjacent node, update low and check for bridge
            low[node] = min(low[node], low[i]);
            if (low[i] > disc[node]) {
                ans.push_back({node, i});
            }
        }
        // Back edge case
        else {
            // Update low
            low[node] = min(low[node], disc[i]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    vector<vector<int>> ans;
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> vis;
    vector<int> disc(v, -1); // discovery time
    vector<int> low(v, -1);  // lowest discovery time reachable
    int parent = -1;

    int timer = 0;

    for (int i = 0; i < v; i++) {
        if (!vis[i]) {
            dfs(i, timer, parent, low, disc, vis, adj, ans);
        }
    }
    return ans;
}


int main(){

return 0;
}