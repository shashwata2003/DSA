#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*
Given a given a string which tells the letter priority of each letter, Now we are given a two other strings in
we need to compare them if s1[i]>s2[i] swap(s1[i],s2[i]);
eg: order = "qwertyuioplkjhgfdsazxcvbnm"
int n = 2 -> length of the below error
code:{{"abc","acg"}}
 */
void solve(string order, int n, vector<string>& arr)
{
    for (int j = 0; j < n - 1; j++) // Iterate through pairs of strings
    {
        int i = 0; // Reset i for each pair of strings
        while (i < arr[j].length() && i < arr[j + 1].length()) // Iterate up to the length of the shorter string
        {
            if (arr[j][i] != arr[j + 1][i])
            {
                char s = arr[j][i];
                char t = arr[j + 1][i];
                int in1 = 0, in2 = 0; // Initialize indices
                for (int k = 0; k < order.length(); k++)
                {
                    if (s == order[k])
                    {
                        in1 = k;
                    }
                    if (t == order[k])
                    {
                        in2 = k;
                    }
                }
                if (in1 > in2) // Compare indices
                {
                    swap(arr[j][i], arr[j + 1][i]);
                }
            }
            i++; // Move to the next character
        }
    }
}


int main()
{
    int n = 3;
    string order = "qwertyuioplkjhgfdsazxcvbnm";
    vector<string> codes = {"abc", "acg","abg"};
    solve(order, n, codes);
    for (int i = 0; i < codes.size(); i++)
    {
        cout<<codes[i]<<" ";
    }
    

    return 0;
}