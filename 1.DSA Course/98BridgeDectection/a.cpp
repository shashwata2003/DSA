#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Bridges In A Graph:
Given an undirected graph of V vertices and E edges. Your task is to find all the bridges in the given 
undirected graph. A bridge in any graph is defined as an edge which, when removed, makes the graph disconnected
(or more precisely, increases the number of connected components in the graph).

Sample Input 1 :
2
5 4
0 1
3 1
1 2
3 4
3 3
0 1
1 2
2 0
Sample Output 1 :
4
0 1
1 2    
1 3
3 4
0
Explanation for Sample Input 1 :
For the first test case, the graph will be represented as 

There are four bridges((0-1),(1-2),(1-3),(3-4)) in the above-given graph denoted by red lines.
For the second test case, there is no bridge present in the given graph.
Sample Input 2 :
1
6 7
1 2
1 0
0 2
0 4
5 4
5 3
3 4
Sample Output 2 :
1
0 4


Check notes and video:

TS: O(N+E)
SP: O(N)
 */

void dfs(int node, int parent, int &timer, vector<int> &dics, vector<int> &low, vector<vector<int>> &result,
          nordered_map<int,list<int>> &adj, unordered_map<int,bool> &vis){
    
    // set the visited true and set the val of dics and low
    vis[node] = true;
    dics[node] = low[node] = timer;
    timer++;

    // check the neighbour:
    for(auto i : adj[node]){
        if(i == parent){
            //ignore:
            continue;
        }
        if(!vis[i]){
            //run dfs to next node and once return:
            // update low and check for bridge:
            dfs(i,node,timer,dics,low,result,adj,vis);
            // update low :
            low[node] = min(low[node],low[i]);
            //check brige cond:
            if(low[i]> dics[node]){
                // bridge present hence push it in result:
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(i);
                result.push_back(ans);
            }
        }
        else{
            //back edge case:
            low[node] = min(low[node],dics[i]);
        }
    }
}


vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    // Create a adj list:
    unordered_map<int,list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //define the require DS:
    vector<int> dics(v);
    vector<int> low(v);
    int parent = -1;
    vector<vector<int>> result;
    unordered_map<int,bool> vis;
    int timer = 0;

    // initialize the DS:
    for (int i = 0; i < v; i++)
    {
        dics[i] = -1;
        low[i] = -1;
        vis[i] = false;
    }

    //traverse each node DFS wise:
    for (int i = 0; i < v; i++)
    {
        if(!vis[i]){
            dfs(i,parent,timer,dics,low,result,adj,vis);
        }
    }
    
    return result;
    
}

int main(){

return 0;
}