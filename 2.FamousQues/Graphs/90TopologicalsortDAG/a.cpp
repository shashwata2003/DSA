#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Topological Sort:
Given a DAG consisting of ‘V’ vertices and ‘E’ edges, you need to find out any topological sorting of 
this DAG. Return an array of size ‘V’ representing the topological sort of the vertices of the given DAG.

DAG: A Directed Acyclic Graph (DAG) is a directed graph that contains no cycles.

Topological Sorting: of DAG is a linear ordering of vertices such that for every directed edge from vertex 
‘u’ to vertex ‘v’, vertex ‘u’ comes before ‘v’ in the ordering. Topological Sorting for a graph is not possible
if the graph is not a DAG.

If we are not able to find a topological sort then there is a cycle present in the graph.

Eg:
2 // no. of test case
2 1 // V and E
1 0 

3 2 // V and E
0 1
0 2

Sample Output 1:
1 0
0 2 1

Sol:
Apporach : DFS:
We are going to use same odd visited data structure and a stack

SO we will run teh dfs call on each node form the adj matrix and mark it visited and once a node is return 
we will push it in the stack,
At the end the vals in the stack will be our ans.

TS: O(n+E
SP: O(linear)
 */

void toposort(int node, vector<bool> &visited, unordered_map<int,list<int>> &adj, stack<int> &st){
    visited[node] = true;

    for(auto i : adj[node]){
        if(!visited[i]){
            toposort(i,visited,adj,st);
        }
    }

    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // create a adj matrix from the edges
    unordered_map<int,list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }
    
    // we are using a vector in place of map to safe the code form TLA
    vector<bool> visited(v);
    stack<int> st;

    // running the topological sort for the non connected graph
    for (int i = 0; i < v; i++)
    {
        if(!visited[i]){
            toposort(i,visited,adj,st);
        }
    }

    vector<int> ans;
    int n = st.size();
    for (int i = 0; i < n; i++)
    {
        ans.push_back(st.top());
        st.pop();
    }
    
    return ans;
}

int main(){
    vector<vector<int>> arr ={{1,2},{2,3},{4,1},{4,2},{3,4}};
    int v = 4, e =5;
    vector<int> ans = topologicalSort(arr,v,e);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
return 0;
}