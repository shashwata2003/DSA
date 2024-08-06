#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*
Rat in a Maze Problem - I
Given a n * n matrix with 0 and 1, we need to find all the paths which start at 0,0 and ends at (n-1,n-1).
0 -> blocked way
1 -> opened way
Movements:
D: Down
U: Up
R: Right
L: Left
eg:
Input:
N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1},
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
Output:
DDRDRR DRDDRR
Sol:
the movements: This is used to move the pointer.
up:(x-1,y)
down:x+1,y
left: x,y-1
right: x,y+1
2. Using a new array of n*n called visited: this array will be updated when we visit that element hence will remove
the infinite loop case
3. Safety factor to move the index:
i. the position should be in the matrix
ii. the position should be 1
iii.in the visited array that position should be 0
hence we are clear to move.

4. after the recursion call we need to reset the visited matrix.
*/

bool issafe(int x, int y, int n, vector<vector<int>>& visited, vector<vector<int>>& m)
{
    return (x >= 0 && x < n && y >= 0 && y < n && visited[x][y] == 0 && m[x][y] == 1);
}

void solve(vector<vector<int>>& m, int n, vector<string>& ans, int x, int y, vector<vector<int>>& visited, string path)
{
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }

    visited[x][y] = 1;

    // Down
    int newx = x + 1, newy = y;
    if (issafe(newx, newy, n, visited, m))
    {
        path.push_back('D');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    // Left
    newx = x, newy = y - 1;
    if (issafe(newx, newy, n, visited, m))
    {
        path.push_back('L');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    // Right
    newx = x, newy = y + 1;
    if (issafe(newx, newy, n, visited, m))
    {
        path.push_back('R');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    // Up
    newx = x - 1, newy = y;
    if (issafe(newx, newy, n, visited, m))
    {
        path.push_back('U');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    visited[x][y] = 0; // Revert the visited array // this is done after the function is returned
}

int main()
{
    int N = 4;
    int srcx = 0;
    int srcy = 0;
    vector<vector<int>> m = {{1, 0, 0, 0},
                             {1, 1, 0, 1},
                             {1, 1, 0, 0},
                             {0, 1, 1, 1}};
    vector<vector<int>> visited(N, vector<int>(N, 0)); // Initialize visited array

    vector<string> ans;
    if (m[0][0] == 0)
    {
        cout << "not possible";
        return 0;
    }

    string path = "";
    solve(m, N, ans, srcx, srcy, visited, path);
    // to return the ans in lxilogical order.
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
