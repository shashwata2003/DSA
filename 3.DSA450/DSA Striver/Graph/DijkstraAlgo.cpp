#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Dijkstra Algorithm: Shortest Distance in undirected graph:
Given a weighted, undirected and connected graph of V vertices and an adjacency list adj where adj[i] 
is a list of lists containing two integers where the first integer of each list j denotes there is edge 
between i and j , second integers corresponds to the weight of that  edge . You are given the source vertex 
S and You to Find the shortest distance of all the vertex's from the source vertex S. You have to return a 
list of integers denoting shortest distance between each node and Source vertex S.
 

Note: The Graph doesn't contain any negative weight cycle.

 

Example 1:

Input:
V = 2
adj [] = {{{1, 9}}, {{0, 9}}}
S = 0
Output:
0 9

Example 2:

Input:
V = 3, E = 3
adj = {{{1, 1}, {2, 6}}, {{2, 3}, {0, 1}}, {{1, 3}, {0, 6}}}
S = 2
Output:
4 3 0
 */

/*
Steps:
1. create a set and pusj the source;
2. pop the top of the set and check its adj node, if the updated distance is less than the current distance
then update the distance.
3. return distance
*/

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
    vector<int> dist(V, INT_MAX);
    // The given graph is an adjacency list with vectors containing pairs {node, weight}
    dist[S] = 0;

    // Pair between distance and node
    set<pair<int, int>> st;
    st.insert({0, S});

    while (!st.empty()) {
        auto top = *(st.begin());
        int currdist = top.first;
        int node = top.second;
        st.erase(st.begin());

        for (auto &neighbor : adj[node]) {
            int adjNode = neighbor[0];
            int weight = neighbor[1];

            if (currdist + weight < dist[adjNode]) {
                auto record = st.find({dist[adjNode], adjNode});
                if (record != st.end()) {
                    // Delete the old record
                    st.erase(record);
                }

                // Update the distance and insert the new record
                dist[adjNode] = currdist + weight;
                st.insert({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}

int main(){

return 0;
}