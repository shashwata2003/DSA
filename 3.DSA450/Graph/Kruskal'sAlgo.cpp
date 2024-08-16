#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Minimum Spanning tree using Kruskal Algorithm:

 */

/*
Steps:
1. sort the given graph by weather, here we dont need to create a adj matrix
2. we will create set for each node as it own parent
3. now we will treverse each node and find the parent of each node if the parent u and v are not same then we
will merge them together.

*/

// Comparator function to sort edges by their weight
bool cmp(vector<int> &a, vector<int> &b) {
    return a[2] < b[2];
}

// Function to initialize the parent and rank vectors
void makeset(vector<int> &parent, vector<int> &rank, int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i; // Each node is its own parent initially
        rank[i] = 0;   // Rank is initialized to 0
    }
}

// Function to find the parent of a node with path compression
int findparent(vector<int> &parent, int node) {
    if (parent[node] == node) {
        return node; // If node is its own parent, return node
    }
    return parent[node] = findparent(parent, parent[node]); // Path compression
}

// Function to unite two sets u and v
void unionset(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findparent(parent, u); // Find the parent of u
    v = findparent(parent, v); // Find the parent of v
    
    // Union by rank
    if (rank[u] > rank[v]) {
        parent[v] = u; // Make u the parent of v
    } else if (rank[u] < rank[v]) {
        parent[u] = v; // Make v the parent of u
    } else {
        parent[v] = u; // Make u the parent of v and increase the rank of u
        rank[u]++;
    }
}

// Function to calculate the minimum spanning tree using Kruskal's algorithm
int minimumSpanningTree(vector<vector<int>>& edges, int n) {
    sort(edges.begin(), edges.end(), cmp); // Sort edges by weight
    
    vector<int> parent(n);
    vector<int> rank(n);
    makeset(parent, rank, n); // Initialize the parent and rank vectors
    
    int minweight = 0;
    for (int i = 0; i < edges.size(); i++) { // Iterate over sorted edges
        int u = findparent(parent, edges[i][0]); // Find the parent of the first vertex
        int v = findparent(parent, edges[i][1]); // Find the parent of the second vertex
        int w = edges[i][2]; // Get the weight of the edge
        
        if (u != v) { // If u and v are in different sets
            minweight += w; // Add the weight of the edge to the total weight
            unionset(u, v, parent, rank); // Union the sets
        }
    }
    
    return minweight; // Return the total weight of the minimum spanning tree
}

int main(){

return 0;
}