#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* BFS of graph:
Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.
Note: One can move from node u to node v only if there's an edge from u to v. Find the BFS traversal 
of the graph starting from the 0th vertex, from left to right according to the input graph. Also, you 
should only take nodes directly or indirectly connected from Node 0 in consideration.
 */

void bfs(vector<bool> &vis, vector<int> &adj, vector<int> &ans, int node){
    queue<int> q;
    q.push(node);
    vis[node]= true;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        ans.push_back(front);
        for(auto i : adj[front]){
            if(!vis[i]){
                vis[i] = true;
                q.push(i);
            }
        }
    }
}

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    vector<int> ans;
    vector<bool> visited(V,false);

    for (int i = 0; i < V; i++)
    {
        if(!visited[i]){
            bfs(visited,adj,ans,i);
        }
    }
    

}

int main(){

return 0;
}