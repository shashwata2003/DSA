#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  
Detect Cycle in directed graph using BFS:
Given edges for a directed graph we need to tell weather it have any cycles present in it or not

Sol:
We need topological sort using BFS, hence we will use the same logic.
If we donot find a topological sort then we say we have a cycle in the graph
else there is no cycle present

Cond: 
if the topological sort leng == no. of no , hence no cycle present , return false
else return true

TS: O(N+E)
SP: O(N+E) Linear
*/

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  //create adj matrix:
  unordered_map<int,list<int>> adj;
  for (int i = 0; i < edges.size(); i++)
  {
    int u = edges[i].first;
    int v = edges[i].second;

    adj[u].push_back(v);
  }
  
  // create indegrees:
  vector<int> indegrees(n);
  for(auto i : adj){
    for(auto j : i.second){
        indegrees[j]++;
    }
  }

  queue<int> q;

  for (int i = 0; i < n; i++)
  {
    if(indegrees[i] == 0){
        q.push(i);
    }
  }
  int cnt = 0;
  while (!q.empty())
  {
    int front = q.front();
    q.pop();
    cnt++;

    for(auto i: adj){
        indegrees[i]--;
        if(indegrees[i]==0){
            q.push(i);
        }
    }
  }
  
  if(cnt == n){
    // valid topological sort hence no loop
    return 0;
  }else{
    return 1;
  }


}

int main(){

return 0;
}