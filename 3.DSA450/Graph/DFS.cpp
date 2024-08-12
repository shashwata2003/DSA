#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
DFS of Graph:

You are given a connected undirected graph. Perform a Depth First Traversal of the graph.
Note: Use the recursive approach to find the DFS traversal of the graph starting from the 0th vertex 
from left to right according to the graph.
 */

void dfs(const vector<int> adj[], vector<int> &ans, vector<bool> &vis, int node)
{
    vis[node] = true;
    ans.push_back(node);
    for (auto i : adj[node])
    {
        if (!vis[i])
        {
            dfs(adj, ans, vis, i);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    vector<int> ans;
    vector<bool> vis(V, false);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(adj, ans, vis, i);
        }
    }
    return ans;
}

int main()
{

    return 0;
}