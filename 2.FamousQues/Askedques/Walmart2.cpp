#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  */
string removespcharandspaces(string s)
{
    unordered_set<char> st = {'\t', '+', '$', '-', '@', '!', '&', '*', '(', ')', '[', ']', '#', '^', ' '};
    string res;
    for (auto i : s)
    {
        if (st.find(i) == st.end())
        {
            res = res + i;
        }
    }
    return res;
}

bool isvowel(char c)
{
    if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'I' || c == 'i' || c == 'o' || c == 'O' || c == 'u' ||
        c == 'U')
    {
        return true;
    }
    return false;
}

string solve(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (i + 1 < s.length())
        {
            if (isvowel(s[i]) && !isvowel(s[i + 1]))
            {
                swap(s[i], s[i + 1]);
            }
        }
    }
    return s;
}

int main()
{
    string s;
    getline(cin, s);
    s = removespcharandspaces(s);
    string ans = solve(s);
    cout << ans;
    return 0;
}