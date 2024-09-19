#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
To find the Strongly connected point in a directed graph:


here are going to finf the no. of strogly connected points are present in the graph
Using kosaraju's Algo:
 */

/*
Steps:
1. find topological sort
2. transpose the adj matrix
3. run reversedfs and increment the count:
*/

void dfs(int node, unordered_map<int, list<int>> &adj, stack<int> &st, unordered_map<int, bool> &visited) {
    visited[node] = true;

    for (auto i : adj[node]) {
        if (!visited[i]) {
            dfs(i, adj, st, visited);
        }
    }
    st.push(node); // Push the node onto the stack after visiting all its adjacent nodes
}

void revdfs(int node, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited) {
    visited[node] = true;

    for (auto i : adj[node]) {
        if (!visited[i]) {
            revdfs(i, adj, visited); // Use revdfs for the reverse DFS traversal
        }
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges) {
    unordered_map<int, list<int>> adj;
    // Construct the adjacency list for the graph
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }
    
    // Step 1: Perform DFS to get the nodes in the order of their finishing times
    stack<int> st;
    unordered_map<int, bool> visited;

    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            dfs(i, adj, st, visited);
        }
    }

    // Step 2: Transpose the graph
    unordered_map<int, list<int>> transpose;

    for (int j = 0; j < v; j++) {
        // Reverse visited status for all nodes
        visited[j] = false;
        for (auto i : adj[j]) {
            transpose[i].push_back(j); // Reverse the edges
        }
    }
    
    // Step 3: Perform DFS based on the finishing time in decreasing order from the stack
    int count = 0;
    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (!visited[node]) {
            count++;
            revdfs(node, transpose, visited);
        }
    }

    return count; // Return the number of strongly connected components
}

int main(){

return 0;
}