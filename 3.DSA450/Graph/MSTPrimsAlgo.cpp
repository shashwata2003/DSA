#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Prims Algo to find min spanning tree in a undirected graph 

Given a weighted, undirected, and connected graph with V vertices and E edges, your task is to 
find the sum of the weights of the edges in the Minimum Spanning Tree (MST) of the graph. 
The graph is represented by an adjacency list, where each element adj[i] is a vector containing 
vector of integers. Each vector represents an edge, with the first integer denoting the endpoint of 
the edge and the second integer denoting the weight of the edge.

*/

/*
Steps:
1. Create keys, parent and mst, set mst to false and keys and parent to 0 and -1 for src
2. now traverse each node
3. find the min node in the keys
4. traverse the adj nodes of the min node 
5. check weather the new weather is less than the old weight if so then udate the weight.

*/

class Solution
{
public:
    // Function to find the sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        

        // Initialize the data structures:
        vector<int> keys(V, INT_MAX);   // Initialize keys to maximum value
        vector<bool> mst(V, false);     // To keep track of vertices included in MST
        vector<int> parent(V, -1);      // To store constructed MST

        // Starting from vertex 0 (assuming 0-based indexing)
        keys[0] = 0;

        // MST construction loop
        for (int i = 0; i < V; i++) {
            // Find the vertex with the minimum key value
            int u = -1;
            int mini = INT_MAX;

            for (int j = 0; j < V; j++) {
                if (!mst[j] && keys[j] < mini) {
                    mini = keys[j];
                    u = j;
                }
            }

            if (u == -1) {
                continue;  // If u remains -1, it means all remaining vertices are isolated
            }

            mst[u] = true;

            // Visit the adjacent vertices of u
            for (auto n : adj[u]) {
                int v = n[0];
                int w = n[1];
                if (!mst[v] && w < keys[v]) {
                    keys[v] = w;
                    parent[v] = u;
                }
            }
        }

        int ans = 0;
        for (int i = 1; i < V; i++) {
            if (keys[i] != INT_MAX) {
                ans += keys[i];
            }
        }

        return ans;
    }
};


int main(){

return 0;
}