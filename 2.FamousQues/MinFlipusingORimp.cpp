#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*
Minimum Flips to Make a OR b Equal to c:
Given 3 positives numbers a, b and c. Return the minimum flips required in some bits of a and b to make
( a OR b == c ). (bitwise OR operation).Flip operation consists of change any single bit 1 to 0 or
change the bit 0 to 1 in their binary representation.

Input: a = 2, b = 6, c = 5
Output: 3
Explanation: After flips a = 1 , b = 4 , c = 5 such that (a OR b == c)

Example 2:
Input: a = 4, b = 2, c = 7
Output: 1

Example 3:
Input: a = 1, b = 2, c = 3
Output: 0

SOL
Condition
C = 0 and a = 1 b = 1: set a = 0 b = 0
C = 0 and a = 1 b = 0 set a = 0
C = 0 and a = 0 b = 1 set b = 0
C = 0 and a = 0 b = 0 no change
C = 1 and a = 0 and b = 0 then set either a or b = 1;
else fine

if((a&(1<<i))>0) ai = true;
this lines of code is basically printing the method of converting to binary
consider a = 4
the it will be 0 0 4
a = 2: 0 2
a = 7 = 1 2 4


 */

string intToBinary(int n)
{
    if (n == 0)
        return "0";

    string binary = "";
    while (n > 0)
    {
        binary += (n % 2 == 0 ? "0" : "1");
        n /= 2;
    }

    reverse(binary.begin(), binary.end());
    return binary;
}

int findflips(int a, int b, int c)
{

    int ans = 0;
    for (int i = 0; i < 32; i++)
    { // Change `<=` to `<` to iterate only through valid bit positions
        bool ai = false, bi = false, ci = false;
        if ((a & (1 << i)) > 0)
            ai = true;
        else
            ai = false; // Reset ai to false if the bit is not set

        if ((b & (1 << i)) > 0)
            bi = true;
        else
            bi = false; // Reset bi to false if the bit is not set

        if ((c & (1 << i)) > 0)
            ci = true;
        else
            ci = false; // Reset ci to false if the bit is not set

        if (ci)
        {
            if (!ai && !bi)
                ans++;
        }
        else
        {
            if (ai && bi)
            {
                ans = ans + 2;
            }
            else if (ai && !bi)
            {
                ans++;
            }
            else if (!ai && bi)
            {
                ans++;
            }
        }
    }
    return ans;
}

int main()
{
    int a = 2, b = 6, c = 5;
    cout << findflips(a, b, c);
    return 0;
}