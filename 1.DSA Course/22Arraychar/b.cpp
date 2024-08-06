#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*
 Problem statement
You are given a string 'S'. Your task is to check whether the string is
 palindrome or not. For checking palindrome, consider alphabets and numbers only and 
 ignore the symbols and whitespaces.
Note :
String 'S' is NOT case sensitive.
  */
bool isAlphanumeric(char c) {
    return std::isalnum(c);
}
bool checkPalindrome(string s) {
  int n = s.length();
  int st = 0;
  int e = n - 1;

  while (st < e) {
    while (st < e && !isAlphanumeric(s[st])) {
      st++;
    }
    while (st < e && !isAlphanumeric(s[e])) {
      e--;
    }
      if (tolower(s[st]) != tolower(s[e])) {
        return false;
      } else {
        st++;
        e--;
      }
    }
    return true;
  }
int main(){

return 0;
}