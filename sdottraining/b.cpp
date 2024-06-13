#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Validate parenthesis using stack
here we given a string of parenthesis we need to return the largest valid parenthesis for the given input
i/p: (() o/p: 2
i/p : )()()) o/p: 4
Approach:
we will check the top element of the stack and the next element of the str if they ar in the order ( ) then we will
pop the top from the stack and continue the loop, 
if this condition doesnot match we will push the incoming string in the stack.
 */

int longestvalidparenthesis(string str){
    stack<char> st ;
    int count =0;
    for (int i = 0; i < str.length(); i++)
    {
        if(st.empty()){
            st.push(str[i]);
        }
        else if(st.top() == '(' && str[i] == ')'){
            st.pop();
            count =count+2;
        }
        else{
            st.push(str[i]);
        }
    }
    return count;
}

int main(){
    string str = "(()())";
    int ans  = longestvalidparenthesis(str);
    cout<<ans;
return 0;
}