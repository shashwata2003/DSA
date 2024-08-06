#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*
Rotate the matrix by 90:
given a matrix we need to rotate it by 90 degrees:
like
1 2 3
4 5 6
7 8 9
ans:
7 4 1
8 5 2
9 6 3

sol: we can do this by first transposing the matrix and the reverseing each row
 */
int main()
{
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int rows = arr.size();
    int cols = arr[0].size();
    // Transpose
    for (int i = 0; i < rows; i++)
    {
        for (int j = i + 1; j < cols; j++)
        {
            if (i != j)
            {
                swap(arr[i][j], arr[j][i]);
            }
        }
    }

    // Reverse each row
    for (int i = 0; i < rows; i++)
    {
        int k = 0;
        int j = rows - 1;
        while (k < j)
        {
            swap(arr[i][k], arr[i][j]);
            k++;
            j--;
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << " ";
        }
    }

    return 0;
}