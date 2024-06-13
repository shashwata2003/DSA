#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Reverse the string - ii:
You are given a string ‘STR’ containing space-separated words. 
A word is a sequence of non-space characters. Your task is to reverse the order of words in ‘STR’.
Note: Try to do it in-place without allocating extra space.
Example:
‘STR’ = “when in doubt use brute force”
The reverse order of words in ‘STR’ is: “force brute use doubt in when”.
Note:
1. ‘STR’ does not contain any leading or trailing spaces.
2. The words are always separated by a single whitespace character.
eg: when all else fails reboot
ans: reboot fails else all when
solution:
we need to follow two steps:
1. reverse the entire string
2. reverse each words

 */
int main(){
    string s = "when all else fails reboot";
    int size = s.length();
    reverse(s.begin(),s.end());
    auto start = s.begin();
    while (start != s.end)
    {
        // finding the end of the particular word.
        auto end = find(start,s.end()," ");
        reverse(start,end);
        if(end == s.end){
            break;
        }
        start = end+1;
    }
    cout<<s;

return 0;
}