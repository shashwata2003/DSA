#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*
Remove all adjacent duplicates  in string:
given a string s, we need to remove all the adjacent suplicates in the stringlike
s= abbaca
remove bb -> aaca
then remove aa -> ca
hence ans: ca
sol:

 */
int main()
{
    string s = "abbaca";
    int i = 0;
    while (i < s.length() - 1)
    {
        if (s[i] == s[i + 1])
        {
            s.erase(i, 2);
            i = 0;
        }
        else
        {
            i++;
        }
    }
    cout << s;
    return 0;
}