#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
BFS, Breadth-First Search, is a vertex-based technique for finding the shortest path in the graph. 
It uses a Queue data structure that follows first in first out. In BFS, one vertex is selected at a time 
when it is visited and marked then its adjacent are visited and stored in the queue.

BFS in Graph:
Given an adjacency list representation of a directed graph with ‘n’ vertices and ‘m’ edges. Your task is 
to return a list consisting of Breadth-First Traversal (BFS) starting from vertex 0.

In this traversal, one can move from vertex 'u' to vertex 'v' only if there is an edge from 'u' to 'v'. 
The BFS traversal should include all nodes directly or indirectly connected to vertex 0.

Note:
The traversal should proceed from left to right according to the input adjacency list.

Sample Input 1:
8 7
0 1
0 2
0 3
1 4
1 7
2 5
3 6
Sample Output 1:
0 1 2 3 4 7 5 6

Sol: (using queue)
-> Here we are going to use the given adjacency list , a visisted array (storing all the nodes already visited)
and start node letting us know the starting node

The following step concurrently occur:
1. pop the first element from the queue and store in a variable
2. print that variable and mark that visited in the visited array
3. push all the neighbour of that variable form the adj vector, only the non visited once and mark the neighbour
which makes the cut true

Also handle the disconnected case.

TS: O(N+E)
SP : O(N+E)
 */
void prepareAdjmatrix(unordered_map<int, set<int>> &adj, vector<pair<int,int>> edges){
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].insert(v);
        adj[v].insert(u);
    }
}

void bfs(unordered_map<int, set<int>> &adj, unordered_map<int,bool> &visited, vector<int> &ans, int startnode){
    queue<int> q;
    q.push(startnode);
    visited[startnode] = true;
    while (!q.empty())
    {
        int frontnode = q.front();
        ans.push_back(frontnode);

        q.pop();

        for(auto i: adj[frontnode]){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int,int>> edges){
    unordered_map<int, set<int>> adj;
    vector<int> ans;
    unordered_map<int,bool> visited;

    prepareAdjmatrix(adj, edges);

    for (int i = 0; i < vertex; i++)
    {
        if(!visited[i]){
            bfs(adj, visited, ans, i);
        }
    }

    return ans;
}

int main(){
    int vertex = 8; // Number of vertices
    vector<pair<int,int>> edges = {
        {0, 1},
        {0, 2},
        {0, 3},
        {1, 4},
        {1, 7},
        {2, 5},
        {3, 6}
    };

    vector<int> result = BFS(vertex, edges);

    cout << "BFS traversal starting from node 0: ";
    for(int node : result){
        cout << node << " ";
    }
    cout << endl;

    return 0;
}