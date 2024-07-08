#include<iostream>
#include <bits/stdc++.h>
#include <array>
template <typename T>
using namespace std;
/* 
Implement a graph:
1. Insert a edge
2. Print the graph in adjjasent list pattern
 */

class graph{
    public:
    unordered_map<int,list<int>> mp;

    void insertedge(int n1, int n2 , int direction){
        //n1 and n2 are the node b/w which we are creating the edge
        // direction = 1 means directed graph hence map only n1 to n2 
        // direction = 0 means undriected graph hence map n1 to n2 and n2 to n1.
        mp[n1].push_back(n2);
        if(direction == 0){
            mp[n2].push_back(n1);
        }
    }

    void printgraph(){
        for(auto i: mp){
            cout<<i.first<<" -> ";
            for(auto j : i.second){
                cout<<j<<", ";
            }
        }
    }
};

int main(){
    graph g;
    int n = 3, m = 3;
    for (int i = 0; i < m; i++)
    {
        int v , u;
        cin>>v;
        cin>>u;
        //undirected graph
        g.insertedge(v,u,0);
    }

    g.printgraph();
    
return 0;
}