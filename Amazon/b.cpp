#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*
This is the optimized code of the a.cpp
Preprocessing order: Instead of iterating through the order string repeatedly inside the nested loop, preprocess it into a map where the key is the character and the value is its index. This will allow constant time lookup rather than linear time search.

Early termination: If two consecutive strings have no differing characters in the first i characters (where i is the index of the current character being compared), there's no need to continue comparing the rest of the characters. We can break out of the loop in such cases.

Optimized loop condition: Rather than looping up to the length of the shorter string every time, you can simply loop up to the length of the longest string. Since you are already checking if i exceeds the length of the shorter string in the loop, it ensures you won't access out-of-bounds characters.
*/

#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

void solve(string order, int n, vector<string>& arr) {
    unordered_map<char, int> charIndexMap;
    for (int k = 0; k < order.length(); ++k) {
        charIndexMap[order[k]] = k;
    }

    for (int j = 0; j < n - 1; ++j) {
        int maxLen = max(arr[j].length(), arr[j + 1].length());
        int i = 0;
        while (i < maxLen) {
            if (i >= arr[j].length() || i >= arr[j + 1].length() || arr[j][i] != arr[j + 1][i]) {
                if (i < arr[j].length() && i < arr[j + 1].length()) {
                    char s = arr[j][i];
                    char t = arr[j + 1][i];
                    int in1 = charIndexMap[s];
                    int in2 = charIndexMap[t];
                    if (in1 > in2) {
                        swap(arr[j][i], arr[j + 1][i]);
                    }
                }
                break; // No need to continue if characters differ or end of strings reached
            }
            ++i;
        }
    }
}


int main()
{
    int n = 2;
    string order = "qwertyuioplkjhgfdsazxcvbnm";
    vector<string> codes = {"abc", "acg"};
    solve(order, n, codes);
    for (int i = 0; i < codes.size(); i++)
    {
        cout << codes[i] << " ";
    }

    return 0;
}