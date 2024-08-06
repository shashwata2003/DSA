#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* Creating and Printing
You are given an undirected graph of 'N' nodes and 'M' edges. Your task is to create the graph and print 
the adjacency list of the graph. It is guaranteed that all the edges are unique, i.e., if there is an edge 
from 'X' to 'Y', then there is no edge present from 'Y' to 'X' and vice versa. Also, there are no self-loops 
present in the graph.

In graph theory, an adjacency list is a collection of unordered lists used to represent a finite graph. 
Each list describes the set of neighbors of a vertex in the graph.

For Example:
If 'N' = 3 and edges = {{2,1}, {2,0}}.

Sample Input 1:
4 3
1 2
0 3
2 3
Sample Output 1:
0 3
1 2
2 1 3
3 0 2

 */

vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    vector<int> ans[n]; // it stores all the neighbours of a node
    for (int i = 0; i < m; i++)
    {
        /* it is given oin the formante 
              u v       
          0.  4 3
          1.  1 2
        */
        int u = edges[i][0];
        int v = edges[i][1];

        ans[u].push_back(v);
        ans[v].push_back(u);
    }

    // printing the adj list:
    vector<vector<int>> adj[n];
    for (int i = 0; i < n; i++)
    {
        adj[i].push_back(i);

        // push all teh neighot form the ans
        for (int j = 0; j < ans[i].size(); j++)
        {
            adj[i].push_back(ans[i][j]);
        }
    }
        return adj;
    
    
}

int main(){

return 0;
}