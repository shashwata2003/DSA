#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Course Schedule:
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given 
an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if 
you want to take course ai.

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
To take course 1 you should have finished course 0, and to take course 0 you should also have finished 
course 1. So it is impossible.


 */

/*
This question is solved by the logic of cycle detection in directed graphs using DFS:
*/
bool iscyclic(int node, int parent, vector<bool> &vis, unordered_map<int,list<int>> &adj, vector<bool> &dfsvisited){
    vis[node] = true;
    dfsvisited[node] = true;
    for(auto i : adj[node]){
        if(!vis[i]){
            bool ans = iscyclic(i,node,vis,adj,dfsvisited);
            if(ans){
                return true;
            }
        }
        else if(dfsvisited[i]){
            return true;
        }
    }
    return false;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    unordered_map<int,list<int>> adj;
    for (int i = 0; i < numCourses; i++)
    {
        int u = prerequisites[i][0];
        int v = prerequisites[i][1];

        adj[u].push_back(v);
    }

    vector<bool> visited(numCourses,false);
    vector<bool> dfsvisited(numCourses,false);

    for (int i = 0; i < numCourses; i++)
    {
        if(!visited(i)){
            bool ans = iscyclic(i,-1,visited,adj,dfsvisited);
            if(ans){
                return false;
            }
        }
    }
    return true;
            
}

/*Using BSF:
Here we will check for topological sort if there is a topological then we will have no loop if we find a loop 
then we cannot take all the courses
*/

bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    unordered_map<int, list<int>> adj;
    for (const auto& pre : prerequisites) {
        int u = pre[0];
        int v = pre[1];
        adj[u].push_back(v);
    }
    
    vector<int> indegree(numCourses, 0);
    for (const auto& pair : adj) {
        for (int neighbor : pair.second) {
            indegree[neighbor]++;
        }
    }

    queue<int> q;

    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    int cnt = 0;
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        cnt++;
        for (int neighbor : adj[front]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    return cnt == numCourses;
}

int main(){

return 0;
}