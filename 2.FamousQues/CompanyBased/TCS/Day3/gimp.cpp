/*

Q7:
Problem Statement
Form the minimum number from the given sequence:
Given a pattern containing only I's and D's. I for increasing, and D for decreasing. Device an algorithm to print the minimum number following that pattern. Digits from 1–9 and digits can't repeat.

Examples:

Input format :
The input consists of a single line string input consisting of characters 'I' and 'D' only, where:
'I' stands for "Increasing".
'D' stands for "Decreasing".
Output format :
The output displays a single line string representing the minimum number that can be formed following the given sequence of 'I's and 'D's.

Refer to the sample output for the formatting specifications.
Code constraints :
1 ≤ length of string ≤ 8
Sample test cases :
Input 1 :
ID
Output 1 :
132
Input 2 :
D
Output 2 :
21
Input 3 :
IDDD
Output 3 :
15432
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void getfinalstr(string seq)
{
    string result;

    // create an empty stack of integers
    stack<int> stk;

    // run n+1 times where n is length of input sequence
    for (int i = 0; i <= seq.length(); i++)
    {
        // push number i+1 into the stack
        stk.push(i + 1);

        // if all characters of the input sequence are
        // processed or current character is 'I'
        // (increasing)
        if (i == seq.length() || seq[i] == 'I')
        {
            // run till stack is empty
            while (!stk.empty())
            {
                // remove top element from the stack and
                // add it to solution
                result += to_string(stk.top());
                result += " ";
                stk.pop();
            }
        }
    }

    cout << result << endl;
}

int main()
{
    string str;
    getline(cin, str);
    getfinalstr(str);
    return 0;
}
