#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Remove all the occurance of a substring:
Given a two string a and b remove the occurance of b in a 
eg: Input: s = "daabcbaabcbc", part = "abc"
Output: "dab"
sol: we need to use find function on the given string. so we check first that weather the part is in s or not and 
s.length is not == 0 
if it is there then we will use the erase function to remove it from the string.
 */
int main(){
    string s = "daabcbaabcbc";
    string part = "abc";
    while (s.length()!=0 && s.find(part) < s.length())
    {
        s.erase(s.find(part),part.length());
    }
    cout<<s<<endl;
return 0;
}