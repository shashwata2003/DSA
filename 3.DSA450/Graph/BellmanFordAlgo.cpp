#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*
Bellanford algo for directed graphs and with negative edges:

Given a weighted and directed graph of V vertices and E edges,
Find the shortest distance of all the vertex's from the source vertex S. If a vertices can't be
reach from the S then mark the distance as 10^8. Note: If the Graph contains a negative cycle then return
an array consisting of only -1.
 */

/*
Steps:
1. Create a distance matrix
2. update the distance matrix for n -1 times
3. Update one more time, if there is any changes then return false else return the dist matrix:
*/

vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
{
    //1e8 is used in place of INT_Max as given in the question.
    vector<int> dist(V, 1e8);
    dist[S] = 0;

    int n = edges.size();

    //Update the distance matrix n - 1 times 
    for (int i = 1; i <= V - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if (dist[u] != 1e8 && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Run one more time to check for negative weight cycles
    // if the val gets changed then return {-1} else the distance
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        if (dist[u] != 1e8 && dist[u] + w < dist[v])
        {
            flag = true;
        }
    }

    if (flag)
    {
        return {-1};
    }

    return dist;
}

int main()
{

    return 0;
}