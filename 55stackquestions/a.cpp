#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Reverse a string using a stack:
stack as the property of reversing every input due to it last in first out property
Time COmplexity: O(N)
Space COmplexity: O(N)
 */
int main(){
    string str = "SHASHWATA";
    stack<char> st;
    for (int i = 0; i < str.length(); i++)
    {
        st.push(str[i]);
    }
    string ans = "";
    for (int i = 0; i < str.length(); i++)
    {
        char ch = st.top();
        ans.push_back(ch);
        st.pop();
    }
    
    cout<<ans<<endl;
return 0;
}