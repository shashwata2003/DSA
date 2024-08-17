#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
The second question was given a string and an integer N, reverse N letters from the string. 
 */

string reverseNstring(string str, int n) {
    stack<char> st;
    int len = str.length();
    
    for (int i = 0; i < n; i++) {
        st.push(str[i]);
    }
    
    string ans;
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    
    for (int i = n; i < len; i++) {
        ans.push_back(str[i]);
    }
    
    return ans;
}

int main() {
    cout << reverseNstring("abcd", 4) << endl; // Output should be "bacd"
    return 0;
}