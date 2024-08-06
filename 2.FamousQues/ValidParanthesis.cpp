#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*
Valid Parentheses:
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input 
string is valid.

An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true

Example 3:
Input: s = "(]"
Output: false 
 */

bool isValid(string s) {
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if(st.empty()){
            st.push(s[i]);
        }
        else if((st.top() == '(' && s[i] == ')') || (st.top() == '{' && s[i] == '}') || (st.top() == '[' && s[i] == ']')){
            st.pop();
        }
        else{
            st.push(s[i]);
        }
    }
    if(st.empty()){
        return true;
    }else{
        return false;
    }
            
}

int main(){
    string s = "()[]{}";
    cout<<isValid(s);
return 0;
}