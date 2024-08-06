#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Loop detection in a Directed Graph:
You are given a directed graph having ‘N’ nodes. A matrix ‘EDGES’ of size M x 2 is given which represents 
the ‘M’ edges such that there is an edge directed from node EDGES[i][0] to node EDGES[i][1].

Find whether the graph contains a cycle or not, return true if a cycle is present in the given directed 
graph else return false.

eg:
1 //no. of test case
5 -> Node
6 -> edges
1 2
4 1
2 4
3 4
5 2
1 3
Sample Output 1 :
true
Explanation For Input 1 :
The given graph contains cycle 1 -> 3 -> 4 -> 1 or the cycle 1 -> 2 -> 4 -> 1.

SOl:
Apporach : DFS:
Here we will use same old visited matrix and a new data struction called DFS visited
DFSVisted: Stores the nodes on which the dfs recursive calls are called and we need to set it to false once 
that node returns a ans

The cond for loop detect is: if(Vsisted == true && dfs visited ==  true) hence loop detected.

TS: O(N+E)
SP: O(Linear)
 */


bool isCyclicDFS(int node, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited) {
    // Mark the current node as visited and part of the current DFS path
    visited[node] = true;
    dfsVisited[node] = true;

    for (auto neighbor : adj[node]) {
        // If the neighbor is not visited, recursively check for cycles
        if (!visited[neighbor]) {
            bool isCyclePresent = isCyclicDFS(neighbor, adj, visited, dfsVisited);
            if (isCyclePresent) {
                return true;
            }
        }
        // If the neighbor is visited and part of the current DFS path, a cycle is detected
        else if (dfsVisited[neighbor]) {
            return true;
        }
    }
    // Remove the node from the current DFS path before returning
    dfsVisited[node] = false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges) {
    // Create the adjacency list from the edges
    unordered_map<int, list<int>> adj;
    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);
    }

    // Declare visited and dfsVisited maps
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;

    // Handle disconnected graphs by checking all nodes
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            bool hasCycle = isCyclicDFS(i, adj, visited, dfsVisited);
            if (hasCycle) {
                return 1;  // Cycle detected
            }
        }
    }
    return 0;  // No cycle detected
}
int main(){

return 0;
}