#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Given a operationbinarystring(char*str) string represting thr binary number separated by an alphabet
A -> and
B -> or
C -> XOR
 */
int main(){
    string str = "1C0C1C1A0B1";
    int ans = str[0] - '0';
    for (int i = 0; i < str.size(); i= i+2)
    {
        //int a = str[i] - '0';
        int b = str[i+2] - '0';
        if(str[i+1] == 'A'){
            ans = ans & b;
            str[i+2] = ans;
        }
        else if(str[i+1] == 'B'){
            ans=ans | b;
            str[i+2] = ans;
        }
        else if(str[i+1] == 'C'){
            ans = ans ^ b;
            str[i+2] = ans;
        }
    }
    cout<<ans;
return 0;
}