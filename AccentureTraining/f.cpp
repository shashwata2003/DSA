#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
A palindrome is a sequence of characters that has the property of reading the same in either direction.
You are given a function, char converttoprlindrome(char str)
If string is already palindrome the return null
eg: abcdc 
ans: ba
 */
int main(){
    string str = "abcdc";
    int l = str.length();
    int j=l-1,count=0;
    for (int i = 0; i < l; i++)
    {
        while (i < j && str[i] != str[j])
        {
            i++;
            count++;
        }
        j--;
    }
    int k =0;
    while (k<count)
    {
        cout<<str[k]<<" ";
        k++;
    }
    
    return 0;
}