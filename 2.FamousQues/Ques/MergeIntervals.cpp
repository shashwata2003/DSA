#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*
Merge Intervals:
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and
return an array of the non-overlapping intervals that cover all the intervals in the input.

Example 1:
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

Example 2:
Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
*/

bool compair(const vector<int> &a, const vector<int> &b)
{
    return a[0] < b[0];
}
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> ans;
    if (intervals.size() == 0)
    {
        return ans;
    }

    sort(intervals.begin(), intervals.end(), compair);

    stack<vector<int>> st;
    st.push(intervals[0]);
    for (int i = 1; i < intervals.size(); i++)
    {
        vector<int> curr = intervals[i];
        vector<int> top = st.top();
        // consider curr = [2,3] and top = [1,2]
        if (top[1] >= curr[0])
        {
            st.pop();
            top[1] = max(top[1], curr[1]);
            st.push(top);
        }
        else
        {
            st.push(curr);
        }
    }

    // finding the ans:
    int size = st.size();
    for (int i = 0; i < size; i++)
    {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> merged = merge(intervals);
    for (const vector<int> &interval : merged)
    {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;
    return 0;
}