#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
You are given a string of size ‘N’ consisting of only characters ‘a’,’c’,’g’ and ’t’. 
You have to find all the sub-strings of the given string of length 10 that is occurring more than once 
in the given string.
Sample Input 1
2
12
aaaaaaaaaaab
20
aaagggccctaaagggccct
Sample Output 1
aaaaaaaaaa
aaagggccct
Sample Output Explanation
For First Test-case total number of substrings of size 10 are:-
[aaaaaaaaaa,aaaaaaaaaa,aaaaaaaaab]
From the above substrings, aaaaaaaaaa occurs more than once.

For SecondTestcase total number of substrings of size 10 are:-
[aaagggccct,aagggcccta,agggccctaa,gggccctaaa,ggccctaaag,gccctaaagg, ccctaaaggg, cctaaagggc ,ctaaagggcc ,taaagggccc ,aaagggccct]

From the above substrings, aaagggccct occurs more than once.
Sample Input 2
2
11
ggggggggggg
20
aaaaagggggaaaaaggggg
Sample Output 2
gggggggggg
aaaaaggggg
 */

vector<string> repeatedSubstring(int n, string s) {
    set<string> seen;
    set<string> repeated;

    for (int i = 0; i < n - 9; i++) {
        string sub = s.substr(i, 10);
        if (seen.count(sub) > 0) {
            repeated.insert(sub);
        } else {
            seen.insert(sub);
        }
    }

    return vector<string>(repeated.begin(),repeated.end());
}

int main(){
    int n = 20;
    string s = "aaaaagggggaaaaaggggg";
    vector<string> ans = repeatedSubstring(n,s);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
return 0;
}