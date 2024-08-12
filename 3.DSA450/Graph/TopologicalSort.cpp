#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* Topological sort:

Given an adjacency list for a Directed Acyclic Graph (DAG) where adj_list[i] contains a list of all vertices 
j such that there is a directed edge from vertex i to vertex j, with  V  vertices and E  edges, your task is 
to find any valid topological sorting of the graph.

 

In a topological sort, for every directed edge u -> v,  u must come before v in the ordering.
 */

/* using DFS traversal of the graph*/

void dfs(int node, stack<int> &st, vector<int> adj[], vector<bool> &visited) {
    visited[node] = true;
    for (auto i : adj[node]) {
        if (!visited[i]) {
            dfs(i, st, adj, visited);
        }
    }
    st.push(node);
}

vector<int> topoSort(int V, vector<int> adj[]) {
    stack<int> st;
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, st, adj, visited);
        }
    }

    vector<int> ans;
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}

/* Using BFS: */

vector<int> topoSort(int V, vector<int> adj[]) {
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++) {
        for (int j : adj[i]) {
            indegree[j]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> ans;
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        ans.push_back(front);
        for (int i : adj[front]) {
            indegree[i]--;
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
    }

    return ans;
}

int main(){

return 0;
}