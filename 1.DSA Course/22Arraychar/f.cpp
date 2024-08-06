#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*Replace Spaces:
Given a string we need to replace each space with a @40 
eg: My name 
ans: My@name
sol: we nee to traverse the string, alsp create a new temp data string and whenever there is a ' '  add @40 or
else add the element for the string.
  */
int main(){
    string s = "My Name";
    string temp;
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i] == ' '){
            str[i]
        }else{
            temp.push_back(s[i]);
        }
    }
    cout<<temp<<endl;
return 0;
}