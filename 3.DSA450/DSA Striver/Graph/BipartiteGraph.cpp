#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*
Given a graph, we need to color the graph each vertex  need to be color with only two colors and same color
vertex should not be adjacent
Hence if it is possible return true else return false:

Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
Output: false
Explanation: There is no way to partition the nodes into two independent sets such that every edge
connects a node in one and a node in the other.

Input: graph = [[1,3],[0,2],[1,3],[0,2]]
Output: true
Explanation: We can partition the nodes into two sets: {0, 2} and {1, 3}.
 */

/*
Using DFS:
all linear non cyclid graphs are bipartite.
also even cyclic graphs are also bipartite

Only old cyclic graphs are non bipartite.
*/

bool dfs(int node, int col, vector<vector<int>> &graph, vector<int> &color)
{
    // Color the current node with the given color
    color[node] = col;

    // Traverse all adjacent nodes
    for (auto i : graph[node])
    {
        // If the adjacent node is not colored, recursively color it with the opposite color
        if (color[i] == -1)
        {
            bool ans = dfs(i, 1 - col, graph, color);
            if (!ans)
            {
                return false; // If the recursive call returns false, the graph is not bipartite
            }
        }
        // If the adjacent node is already colored with the same color, the graph is not bipartite
        else if (color[i] == col)
        {
            return false;
        }
    }
    return true; // If all adjacent nodes are properly colored, return true
}

bool isBipartiteDFS(vector<vector<int>> &graph)
{
    vector<int> color(graph.size(), -1); // Initialize all nodes as uncolored (-1)
    int n = graph.size();

    // Check all components of the graph
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1) // If the node is uncolored, start a DFS from it
        {
            bool ans = dfs(i, 0, graph, color);
            if (!ans)
            {
                return false; // If any component is not bipartite, return false
            }
        }
    }
    return true; // If all components are bipartite, return true
}

/*BFS:*/
bool isBipartiteBFS(vector<vector<int>> &graph)
{
    vector<int> color(graph.size(), -1); // Initialize all nodes as uncolored (-1)
    int n = graph.size();

    // Check all components of the graph : this takes care of the non connected graphs
    for (int start = 0; start < n; start++)
    {
        if (color[start] == -1) // If the node is uncolored, start a BFS from it
        {
            queue<int> q;
            q.push(start);
            color[start] = 0; // Color the starting node with color 0

            while (!q.empty())
            {
                int front = q.front();
                q.pop();

                // Traverse all adjacent nodes
                for (int i : graph[front])
                {
                    if (color[i] == -1) // If the adjacent node is not colored, color it with the opposite color
                    {
                        color[i] = 1 - color[front];
                        q.push(i);
                    }
                    else if (color[i] == color[front]) // If the adjacent node is colored with the same color, the graph is not bipartite
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true; // If all components are bipartite, return true
}

int main()
{

    return 0;
}