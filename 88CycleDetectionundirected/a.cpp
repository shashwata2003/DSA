#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Cycle Detection in undirected Graph:
You have been given an undirected graph with 'N' vertices and 'M' edges. The vertices are labelled from 1 to 
'N'. 
Your task is to find if the graph contains a cycle or not.
A path that starts from a given vertex and ends at the same vertex traversing the edges only once is called a 
cycle.

EG:
1 2
1 2
2 3
Sample output 1:
No

Sol:
Apporach: (BFS method)
we need a visited array and a queue and parent data structure to keep track of the parent.
Steps:
1. convert the edges to adj matrix
2. check the adj matrix for the next node 
3. push that node in the queue and mark it as visited also marks its parents 
4. do this till we reach a node where visited = true and node ! = parent but still in th eadj list

To handle the disconnented graph we use a loop which traverse thriugh the no. of nodes and visits only the one
not visited.

TS: Linear
SP: Linear

Apporach 2: DFS
 TS and SP: Linear


 */

void createAdjMatrix(vector<vector<int>>& edges, unordered_map<int, list<int>>& adj) {
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}


// Traversing use BFS
bool isCyclicBFS(int start, unordered_map<int, list<int>>& adj, unordered_map<int, bool>& visited) {
    unordered_map<int, int> parent;
    parent[start] = -1;
    visited[start] = true;
    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int front = q.front();
        q.pop();
        
        // Traversing all the neighbors of the given node
        for (auto i : adj[front]) {
            // Check the loop condition
            if (visited[i] && i != parent[front]) {
                return true;
            }
            // If not then push the element in the queue
            // Update the visited matrix for i 
            // Set the current front as the parent of all the adj element in the queue
            else if (!visited[i]) {
                q.push(i);
                visited[i] = true;
                parent[i] = front;
            }
        }
    }
    return false;
}


// Now Traversing via DFS:

bool isCyclicDFS(int start, int parent, unordered_map<int, list<int>>& adj, unordered_map<int, bool>& visited){
    visited[start] = true;
    for(auto i : adj[start]){
        if(!visited[i]){
            // send the start as the parent and the start as the neighpur of teh current 
            bool detected = isCyclicDFS(i,start,adj,visited);
            if(detected){
                return true;
            }
        }
        else if(i != parent){
            // satisfices the loop cond that the adj nodes is not a parent 
            return true;
        }
    }
    return false;
}

string cycleDetection(vector<vector<int>>& edges, int n, int m) {
    unordered_map<int, list<int>> adj;

    createAdjMatrix(edges, adj);

    unordered_map<int, bool> visited;
    // To manage the non-continuous graph:
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            //bool ans = isCyclicBFS(i, adj, visited);
            bool ans = isCyclicDFS(i,-1,adj,visited);
            if (ans) {
                return "Yes";
            }
        }
    }
    return "No";
}


int main() {
    vector<vector<int>> edges = { {3, 2}, {1, 2}, {3,1}};
    int n = 2, m = 2;
    cout << cycleDetection(edges, n, m);
    return 0;
}