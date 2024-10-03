/*
Q1:
We have given Ankit an input string, s, and a target string, t. The strings will have lengths - lenS, and lenT respectively. He has to find the smallest subset in the input string that contains all the elements in the target. If he fails to do so, he must return null.

Example1



Input:
sajkfhk
hjk

Output:
Smallest subset: jkfh
Explanation:
Since the target value is hjk, the smallest subset containing these characters is jkfh.



Example2



Input:

sajkab

hjk



Output:

Smallest subset: null



Explanation:

﻿Since the target value is hjk, the smallest subset does not contain all these elements. Thus, it returns null.

Input format :
The first line of input consists of a string, S.

The second line of input consists of a string, T.

Output format :
The output displays "Smallest subset: " followed by the smallest subset.



Refer to the sample output for formatting specifications.

Code constraints :
The strings contain lowercase characters.

1 ≤ lenS ≤ 20

1 ≤ lenT ≤ 10

Sample test cases :
Input 1 :
sajkfhk
hjk
Output 1 :
Smallest subset: jkfh
Input 2 :
sajkab
hjk
Output 2 :
Smallest subset: null
*/

#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  */

void findsmallestsubset(string s, string t){
    int n = s.length();
    int m = t.length();
    unordered_map<char,int> mp;
    for (int i = 0; i < m; i++)
    {
        mp[t[i]]++;
    }

    int l = 0, r = 0;
    int index = -1;
    int minsize = INT_MAX;
    int cnt = 0;
    while(r<n){
        mp[s[r]]--;
        if(mp[s[r]] >= 0){
            cnt++;
        }
        while(cnt == m){
            if(r-l+1 < minsize){
                minsize = r-l+1;
                index = l;
            }
            mp[s[l]]++;
            if(mp[s[l]] > 0){
                cnt--;
            }
            l++;
        }
        r++;
    }

    cout<<s.substr(index,minsize);
    
}

int main(){
    string s,t;
    cin>>s>>t;
    findsmallestsubset(s,t);
return 0;
}