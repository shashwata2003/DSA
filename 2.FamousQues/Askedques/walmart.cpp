#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  */

vector<int> solve(int n, vector<int> &arr)
{
    vector<int> ans;
    ans.reserve(n);  // Reserve space for the result to avoid multiple reallocations

    for (int i = 0; i < n; i++)
    {
        int num = arr[i];
        int cnt = 0;

        // Iterate up to the square root of num
        for (int j = 1; j * j <= num; j++)
        {
            if (num % j == 0)
            {
                cnt++; // Count the divisor j
                if (j != num / j)
                {
                    cnt++; // Count the divisor num / j if it's different from j
                }
            }
        }
        ans.push_back(cnt);
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> ans = solve(n, arr);
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}