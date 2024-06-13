#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*
If the string is “bca”, then its permutations in lexicographically increasing order are
{ “abc”, “acb”, “bac”, “bca”, “cab”, “cba” }.
bc ans : bc and cb
for c ans: c
Sol:
here we are going to use the swap apporach, we will run a loop around the input string and we will swap the i index
with every other index
like : at i =0;
swap(i,i);
then swap(i,i+1);
then swap(i,i+2);
once this is done we will increment i.
*/

void solve(vector<int> arr, vector<vector<int>> &ans, int index)
{
    if (index >= arr.size())
    {
        ans.push_back(arr);
        return;
    }
    for (int i = 0; i < arr.size(); i++)
    {
        swap(arr[index], arr[i]);
        solve(arr, ans, index + 1);
        // backtracking : because after adding the value to the ans vector we need to change the orignal array to
        //  normal as this will change the output, as currently we are changing the existing array only
        swap(arr[index], arr[i]);
    }
}

int main()
{
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> ans;
    int index = 0;
    solve(arr, ans, index);
    // the output should be in lexilogical order
    sort(ans.begin(), ans.end());
    for (int i = index; i < ans.size(); i++)
    {
        cout << ans[0][0];
    }

    return 0;
}