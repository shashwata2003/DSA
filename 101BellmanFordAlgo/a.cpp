#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*
You have been given a directed weighted graph of ‘N’ vertices labeled from 1 to 'N' and ‘M’ edges.
Each edge connecting two nodes 'u' and 'v' has a weight 'w' denoting the distance between them.
Your task is to calculate the shortest distance of all vertices from the source vertex 'src'.
Note:
If there is no path between 'src' and 'ith' vertex, the value at 'ith' index in the answer array will be 10^8.
eg:
Sample Input 1 :
4 4 1 // n, v, src
1 2 4
1 3 3
2 4 7
3 4 -2
Sample Output 1 :
0 4 3 1

Check nODe:

TS:O(n*m)
Sp:

*/

// just returning the min distance:
int bellmonFord(int n, int m, int src,int distination, vector<vector<int>> &edges)
{
    vector<int> dist(n + 1, 1e9);
    dist[src] = 0;
    // updating edges n -1 times
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if (dist[u] + wt < dist[v] && dist[u] != 1e9)
            {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // checking for negative cycle
    bool flag = false;
    // runing the dist minimization one more time:
    for (int j = 0; j < m; j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];

        if (dist[u] + wt < dist[v] && dist[u] != 1e9)
        {
           flag = true;
        }
    }
    if(!flag){
        return dist[distination];
    }
    return -1;
}


// to return all the shortes distance form src:
vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {

    vector<int> answer;

    vector<int> distance(n+1, 1e8);

 

    distance[src] = 0;  

    for(int i=1;i<n;i++){

        for(int j=0;j<m;j++){

            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];
            if((distance[u] + wt) < distance[v])

                distance[v] = distance[u] + wt;

        }

    }  

    return distance;

}


int main()
{

    return 0;
}