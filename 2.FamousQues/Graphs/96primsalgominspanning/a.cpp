#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 

In spanning tree each node is able to be visted by other
also nodes = n and edges = n-1

Minimum spanning tree is the one where the weights are minimum 

Prim's Algo:
You are given an undirected connected weighted graph having ‘N’ nodes numbered from 1 to 'N'. 
A matrix ‘E’ of size M x 2 is given which represents the ‘M’ edges such that there is an edge directed 
from node E[i][0] to node E[i][1]. You are supposed to return the minimum spanning tree where you need to
return weight for each edge in the MST.

Sample Input 1 :
1
5 14
1 2 2
1 4 6
2 1 2
2 3 3
2 4 8
2 5 5
3 2 3
3 5 7
4 1 6
4 2 8
4 5 9
5 2 5
5 3 7
5 4 9
Sample Output 1 :
1 2 2
1 4 6
2 3 3
2 5 5


SOL: Check notes and video

if we use min heap we can find the min in O(1)

TS: O(N2)
SP: 


*/


vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g) {
    // create adj list
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < m; i++) {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    // create the necessary data structures
    vector<int> keys(n + 1, INT_MAX);
    vector<bool> mst(n + 1, false);
    vector<int> parent(n + 1, -1);

    // initialize with the source (1-based index)
    keys[1] = 0;
    parent[1] = -1;

    // process the nodes
    for (int i = 1; i < n; i++) {
        int mini = INT_MAX;
        int u = -1;

        // find the minimum key in the keys array i.e. u
        for (int v = 1; v <= n; v++) {
            if (!mst[v] && keys[v] < mini) {
                u = v;
                mini = keys[v];
            }
        }

        // mark the node u as included in MST
        mst[u] = true;

        // check the adjacent nodes of u
        for (auto it : adj[u]) {
            int v = it.first;
            int w = it.second;
            if (!mst[v] && w < keys[v]) {
                keys[v] = w;
                parent[v] = u;
            }
        }
    }

    // create the result array
    vector<pair<pair<int, int>, int>> result;
    for (int i = 2; i <= n; i++) {
        result.push_back({{parent[i], i}, keys[i]});
    }
    return result;
}

int main() {
    int n = 5; // number of vertices
    int m = 6; // number of edges
    vector<pair<pair<int, int>, int>> g = {
        {{1, 2}, 2},
        {{1, 3}, 3},
        {{2, 3}, 1},
        {{2, 4}, 4},
        {{3, 4}, 5},
        {{4, 5}, 7}
    };

    vector<pair<pair<int, int>, int>> mst = calculatePrimsMST(n, m, g);

    for (auto edge : mst) {
        cout << edge.first.first << " - " << edge.first.second << " : " << edge.second << endl;
    }

    return 0;
}