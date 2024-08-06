#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
DFS traversal:

Given No. of vertexs and no. of edges and the edges matrix 
find the DFS traversal vector.

eg:
5 4
0 2
0 1
1 2
3 4
Sample Output 1:
2 // no. of DFS possible as there are disconnected
0 1 2 // first one
3 4 // second one.

SOl:
Check notes
TS:o(1)
SP: O(1)

 */
// Depth First Search function to explore a component
void dfs(int startnode, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, vector<int> &comp) {
    comp.push_back(startnode);
    visited[startnode] = true;

    // Recursively visit all adjacent nodes
    for (auto i : adj[startnode]) {
        if (!visited[i]) {
            dfs(i, adj, visited, comp);
        }
    }
}

// Function to perform Depth First Search on the graph
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges) {
    // Convert the edges to adjacency list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Vector to store the components
    vector<vector<int>> ans;
    unordered_map<int, bool> visited;

    // Visit each node and perform DFS if not already visited
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            vector<int> component;
            dfs(i, adj, visited, component);
            ans.push_back(component);
        }
    }

    return ans;
}

int main() {
    // Input: Number of vertices and edges
    int V = 5; // Number of vertices
    int E = 4; // Number of edges

    // Input: Edges of the graph
    vector<vector<int>> edges = {
        {0, 2},
        {0, 1},
        {1, 2},
        {3, 4}
    };

    // Get the connected components using DFS
    vector<vector<int>> components = depthFirstSearch(V, E, edges);

    // Print the connected components
    cout << "Connected components:" << endl;
    for (const auto &component : components) {
        for (int node : component) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}