#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Given a string s. to find the smallest english char which is not present in the given string 's' and return the same
eg: aibubudxd
ans: c
 */
int main(){
    string str = "aibubudxd";
    char arr[26] = {0};
    int j=0;
    for (int i = 0; i < str.length(); i++)
    {
        int c = str[i] - 'a';
        arr[c]++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] == 0)
        {
            char ch = 'a'+i;
            cout<<ch<<endl;
            i=26;
            break;
        }
        
    }
    
    
return 0;
}