#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the 
image.

You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting 
from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the 
starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those 
pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.

Return the modified image after performing the flood fill.

 

Example 1:

Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2

Output: [[2,2,2],[2,2,0],[2,0,1]]
 */

#include <vector>
using namespace std;

class Solution {
private:
    void solve(vector<vector<int>>& image, int sr, int sc, int color, int m, int n, int originalColor) {
        // Check boundary conditions and if current cell is not of the original color
        if (sr < 0 || sr >= m || sc < 0 || sc >= n || image[sr][sc] != originalColor) {
            return;
        }

        // Update color
        image[sr][sc] = color;

        // Recursively fill in all four directions
        solve(image, sr + 1, sc, color, m, n, originalColor); // Down
        solve(image, sr - 1, sc, color, m, n, originalColor); // Up
        solve(image, sr, sc + 1, color, m, n, originalColor); // Right
        solve(image, sr, sc - 1, color, m, n, originalColor); // Left
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int originalColor = image[sr][sc];
        
        if (originalColor == color) {
            return image;
        }

        solve(image, sr, sc, color, m, n, originalColor);
        return image;
    }
};


int main(){

return 0;
}