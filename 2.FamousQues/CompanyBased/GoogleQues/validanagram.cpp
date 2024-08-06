#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Valid Anagram:
Given two strings we need to find weather they are anagrams or not.
two words are called anagrams when both of them have same no. of chars
eg:
dog and god 
ans true
expl: d = 1
      o = 1
      g = 1
 */

bool findanagram(string a, string b){
    vector<int> str(26,0);
    if(a.size()!=b.size()){
        return false;
    }
    for (int i = 0; i < a.size(); i++)
    {
        int ch = a[i] - 'a';
        str[ch]++;
    }
    for (int i = 0; i < b.size(); i++)
    {
        int ch = b[i] - 'a';
        str[ch]--;
    }
    for(int i : str){
        if(i != 0){
            return false;
        }
    }
    
    return true;
}

int main(){
    string s1 = "anagraa" , s2 = "nagaram";
    cout<<findanagram(s1,s2);
return 0;
}