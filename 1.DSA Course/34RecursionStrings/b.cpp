#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  
Check Palindrome: 
Base case: i>j return;
*/

bool checkPalindrome(string str,int s,int e){
    if(s>e){
        return true;
    }
    if(str[s]!=str[e]){
        return false;
    }else{
        s++;
        e--;
        return checkPalindrome(str,s,e);
    }
}

int main(){
    string str = "ABBAa";
    cout<<checkPalindrome(str,0,str.length()-1);
return 0;
}