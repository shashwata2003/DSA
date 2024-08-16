#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*
You are given two Strings 'P' and 'Q' of equal length.

Your task is to return 1 if String 'P' can be converted into String 'Q' by cyclically rotating it to the
right any number of times ( Possibly Zero ), else return 0.

A cyclic rotation to the right on String 'A' consists of taking String 'A' and moving the rightmost
character to the leftmost position. For example, if 'A' = "pqrst", then it will be "tpqrs" after one
cyclic rotation on 'A'.

For example:
Consider the two strings 'P' = "abfyg" and 'Q' = "gabfy"

If we cyclically rotate String 'P' to the right once. The resulting string P becomes "gabfy" which is
equal to String 'Q'.

Therefore it is possible to convert String 'P' to String 'Q'.
 */

/*Apporach 1:
USing queue: o(n2)
If the size of both strings is not equal, then it can never be possible.
Push the original string into a queue q1.
Push the string to be checked inside another queue q2.
Keep popping q2‘s and pushing it back into it till the number of such operations is less than the size of
    the string.
If q2 becomes equal to q1 at any point during these operations, it is possible. Else not.
*/

int isCyclicRotation(string &p, string &q)
{
    if (p.length() != q.length())
    {
        return 0;
    }
    queue<char> q1;
    queue<char> q2;
    int n = p.length();
    int m = q.length();

    for (int i = 0; i < n; i++)
    {
        q1.push(p[i]);
        q2.push(q[i]);
    }

    for (int i = 0; i < m; i++)
    {
        // take from the front ans push at the back hence creating a rotation
        char ch = q2.front();
        q2.pop();
        q2.push(ch);
        if (q1 == q2)
        {
            return 1;
        }
    }
    return 0;
}

/*Apporach 2: Optimal O(n)
Create a temp string and store concatenation of str1 to str1 in temp, i.e temp = str1.str1
If str2 is a substring of temp then str1 and str2 are rotations of each other.
*/

int isCyclicRotation(string &p, string &q)
{
    if (p.length() != q.length())
    {
        return 0;
    }
    string temp = p + q;

    return temp.find(q) != string::npos;
}

/* same apporach but finding substring is done manually*/

int isCyclicRotation(string &p, string &q)

{

    if (p.length() != q.length())

        return false;

    int a = 0, b = 0;

    string val = p + p;

    while (a < val.length())
    {

        if (val[a] == q[b])
        {
            //Char matched
            a++;
            b++;

            if (b == q.length())
                return true;
                // if q ends hence fully found in temp
        }
        else if (b != 0)
        {
            //reset the counter
            b = 0;
        }
        else
        {
            // and move on
            a++;
        }
    }

    return false;
}
int main()
{

    return 0;
}