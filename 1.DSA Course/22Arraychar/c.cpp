#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Valid palindrome:
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing 
all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include 
letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
sol: 1. we need to remove all the unwanted char
2. Convert it to lower
3. check palendrome
 */
bool IsValid(char c){
    if((c>='a'&&c<='z') || (c>='A'&&c<='Z') || (c>='0'&&c<='9')){
        return true;
    }
    else{
        return false;
    }
}
char ToLower(char ch){
    if((ch>='a' && ch<='z') || (ch>='0' && ch<='9')){
        return ch;
    }else
    {
        char temp = ch -'A'+'a';
        return temp;
    }
    
}
int main(){
    string s;
    s ="A man, a plan, a canal: Panama";
    string temp = "";
    bool count = false;
    // creating a new string with the valid strings
    for (int i = 0; i < s.length(); i++)
    {
        if(IsValid(s[i])){
            temp.push_back(s[i]);
        }
    }
    int st = 0;
    int en = temp.length() - 1;
    while (st<en)
    {
        if (ToLower(temp[st]) != ToLower(temp[en]))
        {
            count = true;
        }else{
            st++;
            en--;
        }
    }
    if(count){
        cout<<"False"<<endl;
    }else{
        cout<<"true"<<endl;
    }
return 0;
}