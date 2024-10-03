/*

Q6:
Problem Statement



Jin is working on a string manipulation problem. He needs to replace all occurrences of a specified pattern within a given word with a specified character. 



Write a program to help Jin achieve this task efficiently.



Example



Input:

ABCABCXABCabc

ABC

#

Output:

##X#abc

Explanation:

After replacing occurrences of the pattern ABC with #, the resultant string becomes ##X#abc.

Input format :
The first line of input consists of the original word as a string.

The second line consists of the pattern as a string.

The third line consists of the character that will replace occurrences of the pattern.

Output format :
The output prints a string representing the modified word after replacing occurrences of the pattern with the specified character.



Refer to the sample output for formatting specifications.

Code constraints :
The length of the word is at most 200 characters.

The strings are case sensitive.

Sample test cases :
Input 1 :
ABCABCXABCabc
ABC
#
Output 1 :
##X#abc
Input 2 :
abxgyuabx
abx
5
Output 2 :
5gyu5
Input 3 :
ABXVYUABXE
ABX
C
Output 3 :
CVYUCE
*/

#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  */

string createnewstring(string str, string t, string re){
    int n = t.length();
    string res = "";
    int l = 0;
    int r = 0;
    int i = 0;
    while(r<str.length()){
        if(str[r] == t[i]){
            i++;
            if(i == n){
                res += re;
                i = 0;
            }
        }else{
            res+=str[r];
        }
        r++;
    }
    return res;
}

int main(){
    string str,target, replace;
    getline(cin,str);
    getline(cin,target);
    getline(cin,replace);
    cout<<createnewstring(str,target,replace);
return 0;
}