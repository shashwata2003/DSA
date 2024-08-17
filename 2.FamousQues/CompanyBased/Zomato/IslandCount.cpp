#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Given a world map such that all the places covered via land are represented by ‘L’ and rest by ‘W’. 
Since world is spherical hence rows and columns are cyclic (before row 1 row n comes and after row n 
row 1 same for column). Count the number of islands

Input:
4
4 4
L W W L
L L W L
L W W W
L W L L
4 4
L W W L
L L W W
L W W W
L W L W
2 2
L L
L L
3 3
W W W
W L W
W W W
Output:
1
2
0
1

 */
void removeWater(vector<vector<char>> &arr, int i, int j, int n, int m, vector<vector<bool>> &vis) {
    // Handling cyclic nature of the map
    if (i >= n) i = 0;
    if (i < 0) i = n - 1;
    if (j >= m) j = 0;
    if (j < 0) j = m - 1;

    // If already visited or water, return
    if (vis[i][j] || arr[i][j] == 'W') {
        return;
    }

    // Mark this cell as visited
    vis[i][j] = true;

    // Recursively visit all connected land cells
    removeWater(arr, i, j + 1, n, m, vis);
    removeWater(arr, i + 1, j, n, m, vis);
    removeWater(arr, i, j - 1, n, m, vis);
    removeWater(arr, i - 1, j, n, m, vis);
}

int countIsland(vector<vector<char>> &arr, int n, int m) {
    int count = 0;
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 'L' && !visited[i][j]) {
                count++;
                removeWater(arr, i, j, n, m, visited);
            }
        }
    }

    return count;
}

int main() {
    vector<vector<vector<char>>> maps = {
        {{'L', 'W', 'W', 'L'},
         {'L', 'L', 'W', 'L'},
         {'L', 'W', 'W', 'W'},
         {'L', 'W', 'L', 'L'}},
        {{'L', 'W', 'W', 'L'},
         {'L', 'L', 'W', 'W'},
         {'L', 'W', 'W', 'W'},
         {'L', 'W', 'L', 'W'}},
        {{'L', 'L'},
         {'L', 'L'}},
        {{'W', 'W', 'W'},
         {'W', 'L', 'W'},
         {'W', 'W', 'W'}}
    };
    vector<int> n = {4, 4, 2, 3};
    vector<int> m = {4, 4, 2, 3};
    vector<int> expected_results = {1, 2, 1, 1};

    for (size_t i = 0; i < maps.size(); i++) {
        int result = countIsland(maps[i], n[i], m[i]);
        cout << "Number of islands in map " << i + 1 << ": " << result << " (expected: " << expected_results[i] << ")" << endl;
    }

    return 0;
}