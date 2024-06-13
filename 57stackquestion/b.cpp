#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*
Max rectangle
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

Solution:
Here we are going to use the concept of largest area in histogram
to implement that we need to create a histograph form the N*N matrix given to us.
step1: compute the max area from the the first row.
step 2: run a for loop to traverse the rows and compute the max area after add the current row to the first row.
and find the max area using the largest area in a hostorgram method and continue by storing the max area value.
step 3: store the max area and return the area at the end.
 */

vector<int> nextSmallerElement(int *arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        // ans is stack ka top
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

vector<int> prevSmallerElement(int *arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        // ans is stack ka top
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

int largestRectangleArea(int *heights, int n)
{
    // int n= heights.size();

    vector<int> next(n);
    next = nextSmallerElement(heights, n);

    vector<int> prev(n);
    prev = prevSmallerElement(heights, n);

    int area = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int l = heights[i];

        if (next[i] == -1)
        {
            next[i] = n;
        }
        int b = next[i] - prev[i] - 1;
        int newArea = l * b;
        area = max(area, newArea);
    }
    return area;
}
int maxArea(int M[MAX][MAX], int n, int m)
{

    // compute area for first row
    int area = largestRectangleArea(M[0], m);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            // row udpate: by adding previous row's value
            if (M[i][j] != 0)
                M[i][j] = M[i][j] + M[i - 1][j];
            else
                M[i][j] = 0;
        }

        // entire row is updated now
        area = max(area, largestRectangleArea(M[i], m));
    }
    return area;
}

int main()
{

    return 0;
}