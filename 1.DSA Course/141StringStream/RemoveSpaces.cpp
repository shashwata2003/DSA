#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 

Given a string, remove spaces from it. 

Example 1:

Input:
S = "geeks  for geeks"
Output: geeksforgeeks
Explanation: All the spaces have been 
removed.
Example 2:

Input: 
S = "    g f g"
Output: gfg
Explanation: All the spaces including
the leading ones have been removed.
 */

class Solution
{
  public:
    string modify(string s)
    {
        stringstream str(s);  // Initialize stringstream with input string 's'
        string ans = "";
        string temp;
        while (str >> temp) {  // Extract words from the stream
            ans += temp;  // Concatenate words without spaces
        }
        return ans;  // Return the modified string
    }
};

int main(){

return 0;
}