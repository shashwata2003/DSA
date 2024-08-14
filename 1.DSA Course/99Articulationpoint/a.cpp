#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Find Articulation points:


Check notes and video:
TS: O(N+E)
SP: O(N)
 */

void dfs(int node, int parent, vector<int> &disc, vector<int> &low, unordered_map<int, bool> &vis, vector<int> &ap, int &timer, unordered_map<int, list<int>> &adj) {
    vis[node] = true;
    low[node] = disc[node] = timer;
    timer++;
    int child = 0;

    for(auto i: adj[node]){
        if(!vis[i]){
            dfs(i, node, disc, low, vis, ap, timer, adj);
            low[node] = min(low[i], low[node]);
            if(low[i] >= disc[node] && parent != -1){
                ap[node] = 1;
            }
            child++;
        }
        else if(i != parent){
            // back edge
            low[node] = min(low[node], disc[i]);
        }
    }
    // this handles the speacial case which is different form the previous question: 
    // This cond is to check weather the parent node is a articulation point or not.
    if(parent == -1 && child > 1){
        ap[node] = 1;
    }
}

int main() {
    // The graph is created using edges
    int e = 5;
    int n = 5;
    vector<pair<int, int>> edges;
    edges.push_back(make_pair(0, 3));
    edges.push_back(make_pair(3, 4));
    edges.push_back(make_pair(0, 4));
    edges.push_back(make_pair(0, 1));
    edges.push_back(make_pair(1, 2));

    // Create an adjacency list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Create required data structures
    vector<int> low(n);
    vector<int> disc(n);
    int timer = 0;
    unordered_map<int, bool> vis;
    vector<int> ap(n, 0);

    for (int i = 0; i < n; i++) {
        low[i] = -1;
        disc[i] = -1;
        vis[i] = false;
    }

    // DFS
    for (int i = 0; i < n; i++) {
        if(!vis[i]){
            dfs(i, -1, disc, low, vis, ap, timer, adj);
        }
    }

    for (int i = 0; i < ap.size(); i++) {
        if(ap[i] != 0){
            cout << i << " ";
        }
    }

    return 0;
}