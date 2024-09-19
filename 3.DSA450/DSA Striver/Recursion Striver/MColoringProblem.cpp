#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 

 */

/*
Steps:
1. use a colot datatype to store what color is stored for which node
2. Now  we will traverse each node and assign a color to that node
3. of we reach the last node then we have completed colored the graph.
4. if that is not the case then we will place each color on each node, hence we will tevarse each color and
use recursion to traverse each node
5/ check if it is safe to place that color there or not 
*/

bool issafe(bool graph[101][101], vector<int> &color, int c, int node, int n){
    for (int k = 0; k < n; k++){
        // Check if k is not the current node, k and node are adjacent, and k has the same color
        if(k != node && graph[k][node] == 1 && color[k] == c){
            return false;
        }
    }
    return true;
}

bool solve(bool graph[101][101], int m, int n, vector<int> &color, int index){
    if(index == n){
        return true;
    }

    for (int i =  1; i <= m; i++){
        if(issafe(graph, color, i, index, n)){
            color[index] = i;
            if(solve(graph, m, n, color, index + 1)){
                return true;
            }
            color[index] = 0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int n) {
    vector<int> color(n, 0);
    int index = 0; // Added the missing semicolon
    return solve(graph, m, n, color, index);
}


int main(){

return 0;
}