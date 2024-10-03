/*

Q10:
Problem Statement



Given two strings, s, and t, the task is to find the maximum length of some prefix of the string s that occurs in string t as a subsequence.



Example



Input: 

s = "digger"

t = "biggerdiagram"

Output: 

3

Explanation: 

Prefix "dig" of s is the longest subsequence in t.

Input format :
The first line input consists of a string, representing s.

The second line of string consists of a string representing t.

Output format :
The output displays the maximum length of subsequence found in t.



Refer to the sample output for formatting specifications.

Code constraints :
Strings s and t consist of alphabetical characters (a-z) with lengths ranging from 1 to 1000 characters.

Sample test cases :
Input 1 :
digger
biggerdiagram
Output 1 :
3
Input 2 :
iamneo
abcidfaiimon
Output 2 :
4
*/

#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  */

int findprefic(string s, string t){
    int n = t.length();
    int m = s.length();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if(count == m){
            break;
        }
        if(s[count] == t[i]){
            count++;
        }
    }
    return count;
}

int main(){
    string s,t;
    getline(cin,s);
    getline(cin,t);
    cout<<findprefic(s,t);
return 0;
}