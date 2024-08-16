#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  Missing Number:
You are given an array/list ‘BINARYNUMS’ that consists of ‘N’ distinct strings which represent all
integers from 0 to N in binary representation except one integer. This integer between 0 to ‘N’ whose
binary representation is not present in list ‘BINARYNUMS’ is called ‘Missing Integer’.

Your task is to find the binary representation of that ‘Missing Integer’. You should return a string
that represents this ‘Missing Integer’ in binary without leading zeros.

Note
1. There will be no leading zeros in any string in the list ‘BINARYNUMS’.
Example:
Consider N = 5 and the list ‘binaryNums’=  [“0”, “01”, “010”, “100”, “101”].  This list consists of the binary
 representation of numbers [0, 1, 2, 4, 5]. Clearly, the missing number is 3 and its binary representation
will be “11”. So you should return string “11”.
 */

string convert(int num)
{
    string ans = "";
    while (num)

    {
        ans = to_string(num % 2) + ans;
        num /= 2;
    }

    if (ans.empty())

        return "0";

    else

        return ans;
}

string findMissingNumber(vector<string> &binaryNums, int n)
{
    int total = 0;
    total = n * (n + 1) / 2;
    int sum = 0;
    for (i i = 0; i < n; i++)
    {
        sum = sum + stoi(binaryNums[i], nullptr, 2);
    }
    int missing = total - sum;
    string ans = convert(missing);

    return ans;
}

int main()
{

    return 0;
}