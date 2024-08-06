#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Shortest path in an unweighted graph:
Given the edges of a undirected graph, n no. of nodes and m as no. of edges
Also given start and end points we need to find the smallest path b\w start and end:

eg:
1 // no. of testcases
4 4 // n and m 
1 4 // start and end
1 2 // m no. of edges:
2 3
3 4
1 3
Sample Output 1 :
( 1 , 3 , 4 )

Sol:
Apporach: BFS:
Here we are going to use a visited array, a parent array to store all the parent and as usual for BFS a queue
1. Create the adj matrix:
2. push the first node in the queue
3. take the front and mark it visited and set the parent of first as -1
4. now take the front of queue and find its adj neighbours and marks them visited if they are not 
5. if not visited the push them in the queue and set front as ther parent in the parent matrix
6. after successful creating the parent matrix , find the parent of then dest node and follow it to the start 
node
7. return the final ans by reversing it at the end

Check notes for the diagram and explaination 

TS: O(N+E)
SP: O(N+E)
 */

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
    //create the adj matrix:
    unordered_map<int,list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        // undirected graph:
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // run BFS to create the parent matrix:
    unordered_map<int,int> parent;
    unordered_map<int,bool> visited;
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while(!q.empty()){
        int front = q.front();
        q.pop();
        for(auto i: adj[front]){
            if(!visited[i]){
                parent[i] = front;
                visited[i] = true;
                q.push(i);
            }
        }
    }

    // now that we have a completed parent matrix find the shortest path:
    int currentnode = t; // as we start form the end;
    vector<int> ans;
    ans.push_back(t);
    while(currentnode != s){
        currentnode = parent[currentnode];
        ans.push_back(currentnode);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){


return 0;
}