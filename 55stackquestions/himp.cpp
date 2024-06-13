#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*
Minimum Cost To Make String Valid:
Given a string of parenthesis we need to minimum no. of changes we need to make in that string to make the parenthesis
valid.
eg: Minimum operations to make ‘STR’ =  “{{“ valid is 1.
Sample Input 1:
2
{{{}
{{}{}}
Sample Output 1:
1
0
Sample Input 2:
3
{}}{}}
{{{{
{{{}}
Sample Output 2:
1
2
-1 // return -1 if the string is impossible to make valid.

Solution:
Here we going to use the following logic:
1. if the length == odd return -1
2. now remove the valid portion of the string like if{{{} remove the last two parenthesis hence leaving {{
3. after removing the valid portion we might have only three case:
    i. {{{{ -> all { brackets
    ii. }}}}... -> all } brakets
    iii. mixture of { } in even no. 
all this should be even no. if not then return -1
4. we will create two variables a ( count of { ) and b (count of }) now after analsing the pattern we can 
conclude the following formulate ans = (a+1)/2 + (b+1)/2
return ans .
*/

int findMinimumCost(string str){
    stack<char> st;
    if(str.length()%2 == 1){
        return -1;
    }
    for (int i = 0; i < str.length(); i++)
    {
        if(str[i] == '{'){
            st.push(str[i]);
        }
        else{
            if(!st.empty() && st.top() == '{' && str[i]=='}'){
                st.pop();
            }else{
                st.push(str[i]);
            }
        }
    }
    int a  = 0,b = 0;
    while (!st.empty())
    {
        if(st.top() == '{'){
            a++;
        }else{
            b++;
        }
        st.pop();
    }

    int ans = (a+1)/2 + (b+1)/2;
    return ans;
    
    
}

int main()
{
    string str = "{{{}}";
    int ans = findMinimumCost(str);
    cout<<ans;
    return 0;
}