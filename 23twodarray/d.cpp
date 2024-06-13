#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*
    :
 For a given two-dimensional integer array/list ‘ARR’ of size (N x M), print the ‘ARR’ in a sine wave order,
 i.e., print the first column top to bottom, next column bottom to top, and so on.
For eg:-
The sine wave for the matrix:-
1 2
3 4
will be [1, 3, 4, 2].
sol:
Here for every odd column no. we are going form bottom to top and for even we go top to bottom
time complexity: O(M*N)
 */
int main()
{
    int arr[2][2] = {{1, 2}, {3, 4}};
    int col = 2;
    int row = 2;
    vector<int> ans;
    for (int i = 0; i < col; i++)
    {
        if (i & 1)
        {
            // odd case
            for (int j = row - 1; j >= 0; j--)
            {
                ans.push_back(arr[j][i]);
            }
        }
        else
        {
            // 0 and even case:
            for (int j = 0; j < row; j++)
            {
                ans.push_back(arr[j][i]);
            }
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    

    return 0;
}