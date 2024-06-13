#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*
Infix and Postfix Conversion using stack:
Here we are given a expression we need to convert it to post fix expression
eg: (a+b)*(c-d) o/p: ab+cd-*
eg: a+b*c-d/e o/p: abc*+de/-
priority: *>+>-
 */

int priorityofop(char a)
{
    if (a == '+' || a == '-')
    {
        return 1;
    }
    if (a == '*' || a == '/')
    {
        return 2;
    }
    if (a == '^')
    {
        return 3;
    }
    return -1;
}

string converttopostfix(string str)
{
    stack<char> st;
    string postfix;
    int i = 0;
    while (str[i] != '\0') 
    {
        
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) 
        {
            postfix += str[i]; 
            i++;
        }
        // Now manage brackets
        else if (str[i] == '(')
        {
            st.push(str[i]);
            i++;
        }
        else if (str[i] == ')')
        {
            while (!st.empty() && st.top() != '(') 
            {
                postfix += st.top(); 
                st.pop();
            }
            if (!st.empty()) // Added condition !st.empty() to avoid popping from empty stack
                st.pop(); // to remove the '(' from the stack.
            i++;
        }
        // Now Operators
        else
        {
            while (!st.empty() && priorityofop(st.top()) >= priorityofop(str[i]))
            {
                postfix += st.top(); 
                st.pop();
            }
            st.push(str[i]);
            i++;
        }
    }
    while (!st.empty())
    {
        postfix += st.top(); 
        st.pop();
    }

    return postfix;
}


int main()
{
    string str = "(a+b)*(c-d)";
    string ans = converttopostfix(str);
    cout << ans;
    return 0;
}