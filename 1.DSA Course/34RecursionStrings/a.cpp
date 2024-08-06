#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Reverse the string:
Reverse a string using recurtion.
Base case: i>j return 
 */
void reversestring(string &str, int s , int e){
    if(s>e){
        return ;
    }
    swap(str[s],str[e]);
    s++;
    e--;
    reversestring(str,s,e);
}
int main(){
    string str = "abcde";
    reversestring(str,0,str.length()-1);
    cout<<str;
return 0;
}