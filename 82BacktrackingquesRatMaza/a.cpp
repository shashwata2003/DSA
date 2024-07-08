#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Backtracking is method in which we check all the possible ways and we discard or remember the results given by
a previous iteration.

Rat in a Maza:
You are given a starting position for a rat which is stuck in a maze at an initial point (0, 0)
(the maze can be thought of as a 2-dimensional plane). The maze would be given in the form of a square 
matrix of order 'N' * 'N' where the cells with value 0 represent the maze’s blocked locations while value
1 is the open/available path that the rat can take to reach its destination. The rat's destination is at 
('N' - 1, 'N' - 1). 

we need to find the ans in sorted order that mean we will check the possible paths in the order (D,L,R,U);

Sample Input 1:
4
1 0 0 0 
1 1 0 1
1 1 0 0
0 1 1 1
Sample Output 1:
DDRDRR DRDDRR
Explanation For Sample Input 1:
The rat can reach the destination at (3, 3) from (0, 0) by two paths, i.e. DRDDRR and DDRDRR
when printed in sorted order, we get DDRDRR DRDDRR.

Apporach: Backtracking:
we are going to use a n*n matrix called the visited which will keep track of the nodes with will done visiting

init = mark 0,0 as visited and ans = " "

** a box is considered safe when:
1. visited to that box != 1
2. when the box is in N*N
3. and when matrix val of that box == 1

1. first check weather it is safe to make D motion from the current position and if not then check for 
L, R and U
2. do this till be reach the N * N the destination else return null


If needed see the video once again.

TS: O(4^n^2)
SP: O(n*m)

 */

bool issafe(vector<vector<int>> arr , vector<vector<bool>> &visited,int n , int newx , int newy){
    // checks weather the next box is safe to move on according to the condition provided in the question:
    if((newx >= 0 && newx < n) && (newy >= 0 && newy < n) && arr[newx][newy] == 1 && !visited[newx][newy]){
        return true;
    }
    return false;
}

void solve(vector<vector<int>> arr , vector<vector<bool>> &visited, string path, vector<string> &ans,
            int x, int y, int n){
    // base case: if we reach the destination:
    if(x == n-1 && y == n-1){
        ans.push_back(path);
        return;
    }
    
    // account for 4 movements: D, L, R, U

    // setting the visited for the current node true
    visited[x][y] = true;

    // down: x = x+1 y = y
    if(issafe(arr, visited, n, x+1, y)){
        solve(arr, visited, path+'D', ans, x+1, y, n);
    }

    // left: x = x y = y-1
    if(issafe(arr, visited, n, x, y-1)){
        solve(arr, visited, path+'L', ans, x, y-1, n);
    }

    // right: x = x y = y+1
    if(issafe(arr, visited, n, x, y+1)){
        solve(arr, visited, path+'R', ans, x, y+1, n);
    }

    // up: x = x-1 y = y
    if(issafe(arr, visited, n, x-1, y)){
        solve(arr, visited, path+'U', ans, x-1, y, n);
    }

    // backtracking the visited nodes to set it back to 0
    visited[x][y] = false;
}

vector<string> findpaths(vector<vector<int>> arr, int n){
    vector<string> ans;
    // Initialize the two-dimensional vector visited with dimensions n x n, initially set to 0
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    string path = "";
    
    // Edge case where the first box to start is only 0 0
    if(arr[0][0] == 0){
        return ans;
    }
    int x = 0, y = 0;
    solve(arr, visited, path, ans, x, y, n);
    return ans;
}

int main(){
    vector<vector<int>> arr = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    int n = arr.size();
    vector<string> ans = findpaths(arr, n);
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    
    return 0;
}