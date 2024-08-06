#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Reverse Words:

Given a String S, reverse the string without reversing its individual words. Words are separated by dots.

Example 1:

Input:
S = i.like.this.program.very.much
Output: much.very.program.this.like.i
Explanation: After reversing the whole
string(not individual words), the input
string becomes
much.very.program.this.like.i
Example 2:

Input:
S = pqr.mno
Output: mno.pqr
Explanation: After reversing the whole
string , the input string becomes
mno.pqr

Sol:
we will traverse back and as we hit a '.' we will reverse the string till that point.
 */

string reverseWords(string S) 
{ 
    int n = S.length();
    string ans ="";
    string temp = "";
    for (int i = n-1; i >= 0; i--)
    {
        if(S[i] == '.'){
            reverse(temp.begin(),temp.end());
            ans = ans + temp;
            ans.push_back('.');
            temp = "";
        }else{
            temp.push_back(S[i]);
        }
    }
    reverse(temp.begin(),temp.end());
    ans = ans + temp;
    return ans;
    
} 

int main(){
    string S = "pqr.mno";
    cout<<reverseWords(S);
return 0;
}