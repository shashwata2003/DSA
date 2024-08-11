#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Count Strongly Connected Components (Kosaraju’s Algorithm):
You are given an unweighted directed graph having 'V' vertices and 'E' edges. Your task is to count the number of strongly connected components (SCCs) present in the graph.

A directed graph is said to be strongly connected if every vertex is reachable from every other vertex.
 The strongly connected components of a graph are the subgraphs which are themselves strongly connected


Sol:
Steps:
1. Create a adj matrix
2. find the topologocal sort 
3. Transpose the graph
4. using the topo sort run dfs

TS: O(N+E) 
SP: O(N+E) Linear

 */

void dfs(int node, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, stack<int> &st) {
    visited[node] = true;

    for (auto i : adj[node]) {
        if (!visited[i]) {
            dfs(i, adj, visited, st);
        }
    }
    st.push(node);
}

void revdfs(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &transpose) {
    visited[node] = true;
    for (auto i : transpose[node]) {
        if (!visited[i]) {
            revdfs(i, visited, transpose);
        }
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges) {
    // Create adjacency list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    // Calculate topological sort
    stack<int> st;
    unordered_map<int, bool> visited;
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, st);
        }
    }

    // Transpose the graph
    unordered_map<int, list<int>> transpose;
    for (int i = 0; i < v; i++) {
        // Reset the visited array
        visited[i] = false;
        for (auto nbr : adj[i]) {
            transpose[nbr].push_back(i);
        }
    }

    // Call the revDFS on the transposed graph
    int count = 0;
    while (!st.empty()) {
        int top = st.top();
        st.pop();
        if (!visited[top]) {
            count++;
            revdfs(top, visited, transpose);
        }
    }

    return count;
}

int main() {
    int v = 5; // Number of vertices
    vector<vector<int>> edges = {{0, 2}, {2, 1}, {1, 0}, {0, 3}, {3, 4}};

    cout << "Number of strongly connected components: " << stronglyConnectedComponents(v, edges) << endl;

    return 0;
}