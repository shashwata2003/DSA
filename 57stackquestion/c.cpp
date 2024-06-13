/*
Max rectangle: Optimized apporach to remove TLA 
Given a binary matrix M of size n X m. Find the maximum area of a rectangle formed only of 1s in the given matrix
Input:
n = 4, m = 4
M[][] = {{0 1 1 0},
         {1 1 1 1},
         {1 1 1 1},
         {1 1 0 0}}
Output: 8
Explanation: For the above test case the
matrix will look like
0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0
the max size rectangle is
1 1 1 1
1 1 1 1
and area is 4 *2 = 8.
*/



class Solution {
private:
    int largestRectangleArea(int* heights, int n) {
        stack<int> s;
        int maxArea = 0;
        
        for (int i = 0; i <= n; i++) {
            while (!s.empty() && (i == n || heights[s.top()] >= heights[i])) {
                int height = heights[s.top()];
                s.pop();
                int width;
                if (s.empty()) {
                    width = i;
                } else {
                    width = i - s.top() - 1;
                }
                maxArea = max(maxArea, height * width);
            }
            s.push(i);
        }
        return maxArea;
    }
    
public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        int area = largestRectangleArea(M[0], m);
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (M[i][j] != 0) {
                    M[i][j] += M[i-1][j];
                } else {
                    M[i][j] = 0;
                }
            }
            area = max(area, largestRectangleArea(M[i], m));
        }
        return area;
    }
};
