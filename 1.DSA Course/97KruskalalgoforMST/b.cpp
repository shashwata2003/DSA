#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Kruskal's Algorithm:

Check notes:

TS: O(Mlog m)
SP: O(n)
*/


//costome compareator for the sorting based on the weights:
bool cmp(vector<int> &a, vector<int> &b){
    // index 2 holds the weight
    return a[2] < b[2];
}

// this is the part to creating a disjoint set as done in previos file
void makeset(vector<int> & parent, vector<int> &rank, int n){
    for(int i = 0; i<n ;i++){
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(vector<int> &parent , int findnode){
    if(parent[findnode] == findnode){
        return findnode;
    }

    return parent[findnode] = findParent(parent,parent[findnode]);
}

void unionset(int u, int v, vector<int> &parent, vector<int> &rank){
    u = findParent(parent,u);
    v = findParent(parent,v);

    if(rank[u] < rank[v]){
        parent[u] = v;
    }
    if(rank[u] > rank[v]){
        parent[v] = u;
    }else{
        //equal case;
        parent[v] = u;
        rank[v]++;
    }

}

int minimumSpanningTree(vector<vector<int>>& edges, int n){
    // sort the edges:
    sort(edges.begin(),edges.end(),cmp);
    vector<int> parent(n);
    vector<int> rank(n);
    makeset(parent,rank,n);
    
    int minweight = 0;
    //Now travese each node in the sorted edges:
    for (int i = 0; i < n; i++)
    {
        //find parents of u and v;
        int u = findParent(parent,edges[i][0]);
        int v = findParent(parent,edges[i][1]);
        int wt = edges[i][2];
        if(u ! = v){
            //if parent not equal then merge u and v
            minweight += wt;
            unionset(u,v,parent,rank);
        }
    }
    return minweight;
}

int main(){

return 0;
}