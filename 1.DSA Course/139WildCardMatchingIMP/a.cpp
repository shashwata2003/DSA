#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*
Wildcard Matching:
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for
 '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:
Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.

Example 3:
Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
 */

bool solveusingrecursion(string s, string p, int i, int j)
{
    if (i < 0 && j < 0)
    {
        // When both the pattern and the string are over hence both the string matched completely
        return true;
    }
    if (i >= 0 && j < 0)
    {
        // this means the string is not over but the pattern is hence there is no way to match the two :
        return false;
    }
    if (i < 0 && j >= 0)
    {
        // when the string is over but pattern pattern is not, Two case:
        // 1. if there is * in the pattern then we can replace it with the remaining string
        // 2. else if there is any other char then we cannot do anything
        for (int k = 0; k <= j; k++)
        {
            if (p[k] != '*')
            {
                // if the last char is not * return false
                return false;
            }
        }
        return true;
    }

    if (s[i] == p[j] || p[j] == '?')
    {
        return solveusingrecursion(s, p, i - 1, j - 1);
    }
    else if (p[j] == '*')
    {
        return (solveusingrecursion(s, p, i - 1, j) || solveusingrecursion(s, p, i, j - 1));
    }
    else
    {
        return false;
    }
}

bool solveusingmemorization(string s, string p, int i, int j, vector<vector<int>> &dp)
{
    if (i < 0 && j < 0)
    {
        // When both the pattern and the string are over hence both the string matched completely
        return true;
    }
    if (i >= 0 && j < 0)
    {
        // this means the string is not over but the pattern is hence there is no way to match the two :
        return false;
    }
    if (i < 0 && j >= 0)
    {
        // when the string is over but pattern pattern is not, Two case:
        // 1. if there is * in the pattern then we can replace it with the remaining string
        // 2. else if there is any other char then we cannot do anything
        for (int k = 0; k <= j; k++)
        {
            if (p[k] != '*')
            {
                // if the last char is not * return false
                return false;
            }
        }
        return true;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    if (s[i] == p[j] || p[j] == '?')
    {
        return dp[i][j] = solveusingmemorization(s, p, i - 1, j - 1, dp);
    }
    else if (p[j] == '*')
    {
        return dp[i][j] = (solveusingmemorization(s, p, i - 1, j, dp) || solveusingmemorization(s, p, i, j - 1, dp));
    }
    else
    {
        return dp[i][j] = false;
    }
}
// TS: O(n*m) Sp: O(n*m)
bool solveusingtabulation(string s, string p)
{
    int n = s.length(), m = p.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    dp[0][0] = true;

    // Initialize dp for the case when the string is empty but the pattern is not
    for (int j = 1; j <= m; j++)
    {
        bool flag = true;
        for (int k = 1; k <= j; k++)
        {
            if (p[k - 1] != '*')
            {
                flag = false;
                break;
            }
        }
        dp[0][j] = flag;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (p[j - 1] == '*')
            {
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }
            else
            {
                dp[i][j] = false;
            }
        }
    }

    return dp[n][m];
}

bool solveusingspaceopti(string s, string p)
{
    int n = s.length(), m = p.length();
    vector<int> prev(m + 1, 0); // i-1
    vector<int> curr(m + 1, 0); // i
    prev[0] = true;

    // Dry run this part
    // Initialize dp for the case when the string is empty but the pattern is not
    for (int j = 1; j <= m; j++)
    {
        bool flag = true;
        for (int k = 1; k <= j; k++)
        {
            if (p[k - 1] != '*')
            {
                flag = false;
                break;
            }
        }
        prev[j] = flag;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
            {
                curr[j] = prev[j - 1];
            }
            else if (p[j - 1] == '*')
            {
                curr[j] = prev[j] || curr[j - 1];
            }
            else
            {
                curr[j] = false;
            }
        }
        prev = curr;
    }

    return prev[m];
}

bool isMatch(string s, string p)
{
    int n = s.length();
    int m = p.length();

    // Using recursion:
    //  bool ans = solveusingrecursion(s,p,n-1,m-1);

    // Using memorization:
    //  vector<vector<int>> dp(n,vector<int>(m,-1));
    //  bool ans = solveusingmemorization(s,p,n-1,m-1,dp);

    // Using tabulation:
    // bool ans = solveusingtabulation(s, p);

    // using space optimization:
    // Here the ans depends upon i-1 and i
     bool ans = solveusingspaceopti(s,p);
    return ans;
}
int main()
{
    string s = "abcde", p = "a*ce";
    cout << isMatch(s, p);
    return 0;
}