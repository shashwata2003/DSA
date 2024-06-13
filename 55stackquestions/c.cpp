#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Valid Parenthesis:
You're given a string 'S' consisting of "{", "}", "(", ")", "[" and "]" .
Return true if the given string 'S' is balanced, else return false.
For example:
'S' = "{}()".
There is always an opening brace before a closing brace i.e. '{' before '}', '(' before ').
So the 'S' is Balanced.
Example:
Sample Input 1 :
[()]{}{[()()]()}
Sample Output 1 :
Balanced
Solution:
Here we are going to use a stack to check the validity of the parenthesis.
step 1: we are going to terverse the string array of all the parenthesis on by one if the bracket is opening kind
we will push it in the stack
step 2: when we encounter a closing kind bracket in the input string we will check the top of the stack 
for its corresponding opening kind if we find one then we pop the opening bracket for the stack and move on
step 3: after traversing the entire input string we will check if the stack is empty or not if it is empty then 
the input string is valid else the input string is not valid.
 */

bool isvalid(string str){
    stack<char> st;
    for (int i = 0; i < str.length(); i++)
    {
        if(str.empty()){
            st.push(str[i]);
        }
        else if((str[i] ==']' && st.top() == '[') || (str[i] =='}' && st.top() == '{') 
        || (str[i] ==')' && st.top() == '(') ){
            st.pop();
        }else{
            st.push(str[i]);
        }
    }
    if(st.empty()){
        return true;
    }
    return false;
    
}

int main(){
 string str = "[()]{}{[()()]()";
 cout<<isvalid(str)<<endl;
return 0;
}