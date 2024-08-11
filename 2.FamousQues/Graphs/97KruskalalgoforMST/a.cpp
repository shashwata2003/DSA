#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  
Implementing Disjoint set 
1. sets
2. find Parent node
3. union
*/

void makeset(vector<int> &parent, vector<int> &set, int n){
    for (int i = 0; i < n; i++)
    {
        parent[i] = i; // init all the parent by it self as we saw in the explaination in note
        rank[i]= 0; // init all the ranks as 0
    }
    
}

int findparent(vector<int>&parent, int findnode){
    // if we find the node after traversing through all of its parent we return it
    if(parent[findnode] == findnode){
        return findnode;
    }
    // this to implement the compression algo to directly linking the long branchs to the direct parent
    return parent[findnode] = findparent(parent,parent[findnode]);
}

void unionset(int u , int v , vector<int> &parent, vector<int> & rank){
    // find the parents of both u and v 
    u = findparent(parent,u);
    v = findparent(parent,v);

    // find the rank of the parent and compare it:
    if(rank[u]<rank[v]){
        parent[u] = v;
    }
    else if(rank[u]> rank[v]){
        parent[v] = u;
    }
    else{
        // ranks are equal
        parent[v] = u;
        rank[u]++;
    }
}



int main(){
    // init the parent and the rank array and we need to populate these 
    int n = 5; // size of the input array of edges;
    vector<int> parent(n);
    vector<int> rank(n);
    makeset(parent,rank,n);
return 0;
}