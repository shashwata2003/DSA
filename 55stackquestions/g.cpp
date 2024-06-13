#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Given valid mathematical expressions in the form of a string. You are supposed to return true if the given 
expression contains a pair of redundant brackets, else return false. The given string only contains 
‘(‘, ’)’, ‘+’, ‘-’, ‘*’, ‘/’ and lowercase English letters.
Redundant brackets means that there is a bracket which is not complete or useless like: ((a+b)) the second one is 
redundant.
Sample Input 1 :
2
(a+b)
(a+c*b)+(c))
Sample Output 1 :
No
Yes
Sample Input 2 :
2
(a*b+(c/d))
((a/b))
Sample Output 2 :
No
Yes
Solution:
we are going to use stack for this question.
now if there is (  and operator we will push the val in the stack.
now when we encounter a ) we will need to check for operator between ) and the ( 
 if we have operator then the experation is non reducancde else it is.
 also we need to check for balanced brackets
 */
bool CheckRedundant(string str){
    stack<char> st;
    for (int i = 0; i < str.length(); i++)
    {
        if(str[i] == '(' ||str[i] == '+'||str[i] == '*'||str[i] == '/'||str[i] == '-'){
            st.push(str[i]);
        }
        else{
            if(str[i] == ')'){
                bool redunand = true;
                while (st.top()!='(')
                {
                    if(st.top() == '+'||st.top() == '*'||st.top() == '/'||st.top() == '-'){
                        redunand = false;
                    }
                    st.pop();
                }
                if(redunand == true){
                    return true;
                }
                st.pop();
            }
        }
    }
    return false;
    
}

int main(){
    string str = "((a+b))";
    cout<<CheckRedundant(str);
return 0;
}