#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must
 take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have 
finished course 1. So it is impossible.


Cycle Detection for undirected graph:
 */

/* using DFS:*/

bool dfs(int node, int parent, vector<bool> &visited, unordered_map<int, list<int>> &adj) {
    visited[node] = true;

    for (auto i : adj[node]) {
        if (!visited[i]) {
            bool ans = dfs(i, node, visited, adj);
            if (ans) {
                return true;
            }
        } else if (i != parent) {
            return true;
        }
    }
    return false;
}

bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    unordered_map<int, list<int>> adj;
    for (const auto& pre : prerequisites) {
        int u = pre[0];
        int v = pre[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(numCourses, false);

    for (int i = 0; i < numCourses; i++) {
        if (!visited[i]) {
            bool isCycle = dfs(i, -1, visited, adj);
            if (isCycle) {
                return false;
            }
        }
    }

    return true;
}


/*
Cycle detection using BFS in undirected graphs:
*/

bool bfs(int node, unordered_map<int, list<int>> &adj, vector<bool> &visited) {
    unordered_map<int, int> parent;
    parent[node] = -1;
    visited[node] = true;
    queue<int> q;
    q.push(node);
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        for (auto i : adj[front]) {
            if (visited[i] && i != parent[front]) {
                return true; // Cycle detected
            } else if (!visited[i]) {
                q.push(i);
                visited[i] = true;
                parent[i] = front;
            }
        }
    }
    return false;
}

bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    unordered_map<int, list<int>> adj;
    for (const auto& pre : prerequisites) {
        int u = pre[0];
        int v = pre[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(numCourses, false);

    for (int i = 0; i < numCourses; i++) {
        if (!visited[i]) {
            bool isCycle = bfs(i, adj, visited);
            if (isCycle) {
                return false; // Cycle detected, cannot finish all courses
            }
        }
    }

    return true; // No cycle detected, can finish all courses
}

int main(){

return 0;
}