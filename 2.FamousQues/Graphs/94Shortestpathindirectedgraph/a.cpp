#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*
To find the shorted distance in a weighted directed graph:
Given a adj matrix of a weighted directed graph, our job is to find the shortest distance between
the start node : 1 and the rest of the nodes in the grapg.

Sol:
Apporach: DFS:
1. we are given the sdj matrix hence using that we will create a topological sort using DFS
2. we will create a distance matrix init with infinite except the src node once done
3. we will update this distance array to find the final answer.

Check notes and the video once again.

TS:
SP:

 */

class Graph
{
public:
    // adj matix between node, neigbours and neighbours weights:
    unordered_map<int, list<pair<int, int>>> adj;

    void addedges(int u, int v, int weight)
    {
        pair<int, int> p = make_pair(v, weight);
        adj[u].push_back(p);
    }

    void printadj()
    {
        for (auto i : adj)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << "(" << j.first << ", " << j.second << ")";
            }
            cout << endl;
        }
    }

    void dfs(unordered_map<int, int> &visited, stack<int> &st, int node)
    {
        visited[node] = true;

        for (auto i : adj[node])
        {
            if (!visited[i.first])
            {
                dfs(visited, st, i.first);
            }
        }
        st.push(node);
    }

    void getshortestdist(vector<int> &dist, int src, stack<int> &st)
    {
        //setting the start as 0 
        dist[src] = 0;
        while (!st.empty())
        {
            int top = st.top();
            st.pop();

            if (dist[top] != 99999)
            {
                // if the top is not changes from infinity skip it
                for (auto i : adj[top]){
                    // compare the new distance with the new one, if the new one is smaller update it 
                    if(dist[top]+ i.second< dist[i.first]){
                        dist[i.first] = dist[top]+ i.second;
                    }
                }
            }
        }
    }
};

int main()
{
    Graph g;
    g.addedges(0, 1, 5);
    g.addedges(0, 2, 3);
    g.addedges(1, 2, 2);
    g.addedges(1, 3, 6);
    g.addedges(2, 3, 7);
    g.addedges(2, 4, 4);
    g.addedges(2, 5, 2);
    g.addedges(3, 4, -1);
    g.addedges(4, 5, -2);

    // g.printadj();

    // Create Topological sort:
    unordered_map<int, int> visited;
    // st stores the topological sort
    stack<int> st;
    int n = 6; // no. of node:
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            g.dfs(visited, st, i);
        }
    }

    // Creating the distance matrix and updating it according;
    vector<int> dist(n);
    for (int i = 0; i < n; i++)
    {
        dist[i] = 99999;
    }

    // start point:
    int src = 1;

    g.getshortestdist(dist, src, st);

    for(int i= 0 ; i<dist.size(); i++){
        cout<<dist[i]<<" ";
    }
    return 0;
}