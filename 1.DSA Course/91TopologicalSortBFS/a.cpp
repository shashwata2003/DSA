#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Implement Topological sort using Kahn algorith:
Kahn algo is Topological sort using BFS

Sol:
Apporach:
Here we are going to use stack and a indegree array
Stack: stores all the elements whos indegree is 0
Indegree: stores all the in arrows in a row

we will take the front of the stack and check its adj neighbours and reduces
there indegree val, 
if that val hit 0 we will push them in the stack 
and when we pop a val in the queue we push it in the ans

TS: O(N+E)
SP: O(N+E) Linear

 */

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges) {
  // Create adjacency list
  unordered_map<int, list<int>> adj;
  for (int i = 0; i < edges.size(); i++) {
    int u = edges[i].first;
    int v = edges[i].second;
    adj[u].push_back(v);
  }
  
  // Create indegrees:
  vector<int> indegrees(n + 1, 0);  // Adjusted for 1-based index
  for (auto i : adj) {
    for (auto j : i.second) {
      indegrees[j]++;
    }
  }

  queue<int> q;
  //starting form 1 because here we have 1 based indexing.
  for (int i = 1; i <= n; i++) {
    if (indegrees[i] == 0) {
      q.push(i);
    }
  }
  
  int cnt = 0;
  while (!q.empty()) {
    int front = q.front();
    q.pop();
    cnt++;

    for (auto i : adj[front]) {
      indegrees[i]--;
      if (indegrees[i] == 0) {
        q.push(i);
      }
    }
  }
  
  if (cnt == n) {
    // Valid topological sort, hence no cycle
    return 0;
  } else {
    return 1;
  }
}

int main(){
    vector<vector<int>> arr ={{0,1},{0,2}};
    int v = 3, e = 2;
    vector<int> ans = topologicalSort(arr,v,e);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
return 0;
}