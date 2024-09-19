#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*
Given a string s of lowercase letters, you need to find the maximum number of non-empty substrings of s
that meet the following conditions:

The substrings do not overlap, that is for any two substrings s[i..j] and s[x..y], either j < x or i > y is
true.
A substring that contains a certain character c must also contain all occurrences of c.
Find the maximum number of substrings that meet the above conditions. If there are multiple solutions with
the same number of substrings, return the one with minimum total length. It can be shown that there exists
a unique solution of minimum total length.

Notice that you can return the substrings in any order.



Example 1:

Input: s = "adefaddaccc"
Output: ["e","f","ccc"]
Explanation: The following are all the possible substrings that meet the conditions:
[
  "adefaddaccc"
  "adefadda",
  "ef",
  "e",
  "f",
  "ccc",
]
If we choose the first string, we cannot choose anything else and we'd get only 1. If we choose "adefadda", we are left with "ccc" which is the only one that doesn't overlap, thus obtaining 2 substrings. Notice also, that it's not optimal to choose "ef" since it can be split into two. Therefore, the optimal way is to choose ["e","f","ccc"] which gives us 3 substrings. No other solution of the same number of substrings exist.
Example 2:

Input: s = "abbaccd"
Output: ["d","bb","cc"]
Explanation: Notice that while the set of substrings ["d","abba","cc"] also has length 3, it's considered incorrect since it has larger total length.
 */

/*
We can solve this question using either a graph or using greedy method.
*/

/*
Using Greedy apporach:
steps:
1. Create left and right vector pointer to store the leftmost and rightmost indices
of all possible characters of the given string respectively.
2. now traverse the string and populate the left and right pointer
3. Traverse the string using the variable i and check if i is the leftmost index of str[i],
check if the substring starting from the ith position consisting of all occurrences of str[i] does
not overlap with any of the substrings consisting of characters up to str[i -1] or not. If found to be
true, then append the current substring into res[].
*/

// Function to check the validity of the substring starting at index 'i'
int checkvalid(int i, string s, vector<int> &left, vector<int> &right)
{
    // Get the rightmost index of the current character
    int rightindex = right[s[i] - 'a'];

    // Traverse from the current index 'i' to the rightmost index of the character
    for (int j = i; j < rightindex; j++)
    {
        // If the leftmost index of character s[j] is less than 'i', the substring is invalid
        // If it is, this means that the character s[j] appears earlier in the string than the starting index i, making it impossible to form a valid, self-contained substring that starts at i. Therefore, the function returns -1, indicating that the substring is invalid.
        if (left[s[j] - 'a'] < i)
            return -1;

        // Update the rightmost index if needed
        // rightindex = max(rightindex, right[s[j] - 'a']) ensures that rightindex always reflects the farthest right occurrence of any character encountered so far in the substring.
        // This step is necessary because characters encountered later in the substring might extend the boundaries of the substring if they appear further to the right than previously considered.
        rightindex = max(rightindex, right[s[j] - 'a']);
    }

    // Return the updated rightmost index
    return rightindex;
}

// Function to find the maximum number of non-overlapping substrings
vector<string> maxNumOfSubstrings(string s)
{
    // Arrays to store the leftmost and rightmost indices of each character
    vector<int> left(26, -1);
    vector<int> right(26, -1);
    vector<string> ans;
    int n = s.length();

    // Fill in the leftmost and rightmost indices for each character
    for (int i = 0; i < n; i++)
    {
        if (left[s[i] - 'a'] == -1)
        {
            left[s[i] - 'a'] = i;
        }
        right[s[i] - 'a'] = i;
    }

    int rightindex = -1;

    // Iterate through the string to find valid substrings
    for (int i = 0; i < n; i++)
    {
        // If the current index is the leftmost index of the character
        if (i == left[s[i] - 'a'])
        {
            // Check if the substring starting at 'i' is valid
            int newright = checkvalid(i, s, left, right);

            // If valid, create the substring
            if (newright != -1)
            {
                string sub = s.substr(i, newright - i + 1);
                // Check for overlapping with the previous substring
                if (newright < rightindex)
                {
                    // Replace the last substring if overlapping
                    ans.back() = sub;
                }
                else
                {
                    // Add the new substring to the answer list
                    ans.push_back(sub);
                }

                // Update the rightmost index for the next iteration
                rightindex = newright;
            }
        }
    }

    return ans;
}

/*Using Graphs: kosaraju algo*/

vector<string> maxNumOfSubstrings(string S)
{
    // some nasty pre-compute in order to build the graph in O(N) time
    vector<int> mins(26, INT_MAX);
    vector<int> maxs(26, -1);
    vector<bool> exists(26, false);
    vector<vector<int>> prefixSum(S.length() + 1, vector<int>(26, 0));

    for (int i = 0; i < S.length(); i++)
    {
        copy(prefixSum[i].begin(), prefixSum[i].end(), prefixSum[i + 1].begin());
        prefixSum[i + 1][S[i] - 'a'] += 1;
        mins[S[i] - 'a'] = min(mins[S[i] - 'a'], i);
        maxs[S[i] - 'a'] = max(maxs[S[i] - 'a'], i);
        exists[S[i] - 'a'] = true;
    }

    // build graph, using adjacency matrix
    vector<vector<bool>> graph(26, vector<bool>(26, false));
    for (int i = 0; i < 26; i++)
    {
        if (exists[i])
        {
            for (int j = 0; j < 26; j++)
            {
                if (prefixSum[maxs[i] + 1][j] - prefixSum[mins[i]][j] > 0)
                {
                    graph[i][j] = true;
                }
            }
        }
    }

    // kosaraju algorithm to find SCC
    stack<int> st;
    vector<bool> visited(26, false);
    for (int i = 0; i < 26; i++)
    {
        if (exists[i] && !visited[i])
        {
            dfs(i, graph, st, visited);
        }
    }

    int batch = 0; // 'id' of each SCC
    vector<int> batches(26, -1);
    vector<int> degree(26, 0); // out-degree of each SCC
    while (!st.empty())
    {
        int v = st.top();
        st.pop();
        if (batches[v] < 0)
        {
            dfs(v, graph, batches, batch, degree);
            batch++;
        }
    }

    vector<string> res;
    for (int i = batch - 1; i >= 0; i--)
    {
        if (degree[i] == 0)
        {
            int min = INT_MAX, max = -1;
            for (int j = 0; j < 26; j++)
            {
                if (batches[j] == i)
                {
                    min = std::min(mins[j], min);
                    max = std::max(maxs[j], max);
                }
            }
            res.push_back(S.substr(min, max - min + 1));
        }
    }

    return res;
}

void dfs(int v, vector<vector<bool>> &graph, stack<int> &st, vector<bool> &visited)
{
    if (!visited[v])
    {
        visited[v] = true;
        for (int i = 0; i < 26; i++)
        {
            if (graph[v][i] && !visited[i])
            {
                dfs(i, graph, st, visited);
            }
        }
        st.push(v);
    }
}

void dfs(int v, vector<vector<bool>> &graph, vector<int> &batches, int batch, vector<int> &degree)
{
    if (batches[v] < 0)
    {
        batches[v] = batch;
        for (int i = 0; i < 26; i++)
        {
            if (graph[i][v])
            {
                dfs(i, graph, batches, batch, degree);
            }
        }
    }
    else
    {
        if (batches[v] != batch)
        {
            degree[batches[v]] += 1;
        }
    }
}

int main()
{

    return 0;
}