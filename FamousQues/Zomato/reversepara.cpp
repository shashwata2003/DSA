#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* Reverse individual words:
Given string str, we need to print the reverse of individual words.

Input : Hello World
Output : olleH dlroW
*/

void reversepara(string str){
    stack<char> st;
    for (int i = 0; i < str.length(); i++)
    {
        if(str[i] != ' '){
            st.push(str[i]);
        }else{
            while (!st.empty())
            {
                cout<<st.top();
                st.pop();
            }
            cout<<" ";
        }
    }

    while (!st.empty())
    {
        cout<<st.top();
        st.pop();
    }
    
    
}

int main(){
    string str = "Hello World";
    reversepara(str);
return 0;
}