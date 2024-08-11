#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Dijkstra's Algorithm:(No directed graph)
Given a non directed weighted graph and the src node, we need to find the shortest distance form src to all the 
nodes

Sol:
Apporach:
Here we will use a new set called which will store a pair<int(distanc),int(node)> which will tell which node 
has the shortest distance.
Now when we take the top form this set we will take the one whos dist is the smallest.
If we update the distance of any node hence we need to update the same in the set can create a new pair and 
also remove the old one 

Also we need a dist array which will keep all the dist and we will update it when we find a smaller than the 
existing

Check the video and notes

TS: O(E log V)
SP:O(N+E) : Linear log
 */


vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Create an adjacency list for the graph
    unordered_map<int, list<pair<int, int>>> adj;
    for(int i = 0; i < edges; i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        // as this is an undirected graph
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    // Create distance vector and initialize it
    vector<int> dist(vertices, INT_MAX);
    dist[source] = 0;

    // Create a set to store the nodes to be processed
    set<pair<int, int>> st;
    st.insert(make_pair(0, source));

    // Process the distance vector
    while(!st.empty()){
        // Take the top of the set
        auto top = *(st.begin());
        int node = top.second;
        int dis = top.first;

        st.erase(st.begin());

        // Check its neighbors
        for(auto &i : adj[node]){
            if(dis + i.second < dist[i.first]){
                // Hence we need to update the node
                // 1. Find the node in the set if present
                // 2. Update that pair or create a new one if not present and push it in the set
                // 3. Update the distance vector
                auto record = st.find(make_pair(dist[i.first], i.first));
                if(record != st.end()){
                    // Hence that record is found in the set, erase it
                    st.erase(record);
                }

                // Now update the distance
                dist[i.first] = dis + i.second;
                // Insert a new pair in the set with the updated distance
                st.insert(make_pair(dist[i.first], i.first));
            }
        }
    }

    return dist;
}

int main() {
    int t = 2; // Number of test cases

    // Test case 1
    int vertices1 = 5;
    int edges1 = 7;
    vector<vector<int>> vec1 = {
        {0, 1, 7},
        {0, 2, 1},
        {0, 3, 2},
        {1, 2, 3},
        {1, 3, 5},
        {1, 4, 1},
        {3, 4, 7}
    };
    int source1 = 0;

    // Test case 2
    int vertices2 = 4;
    int edges2 = 5;
    vector<vector<int>> vec2 = {
        {0, 1, 5},
        {0, 2, 8},
        {1, 2, 9},
        {1, 3, 2},
        {2, 3, 6}
    };
    int source2 = 0;

    vector<int> distances1 = dijkstra(vec1, vertices1, edges1, source1);
    vector<int> distances2 = dijkstra(vec2, vertices2, edges2, source2);

    for(int i = 0; i < vertices1; i++) {
        if (distances1[i] == INT_MAX) {
            cout << "INF ";
        } else {
            cout << distances1[i] << " ";
        }
    }
    cout << endl;

    for(int i = 0; i < vertices2; i++) {
        if (distances2[i] == INT_MAX) {
            cout << "INF ";
        } else {
            cout << distances2[i] << " ";
        }
    }
    cout << endl;

    return 0;
}