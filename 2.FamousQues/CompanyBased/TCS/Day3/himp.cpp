/*

Q8:

Problem Statement



Given a string s, find the length of the longest substring without repeating characters.



Example 1:

Input: s = "abcabcbb"

Output: 3

Explanation: The answer is "abc", with a length of 3.
Example 2:

Input: s = "bbbbb"

Output: 1

Explanation: The answer is "b", with a length of 1.     



Example 3:

Input: s = "pwwkew"

Output: 3

Explanation: The answer is "wke", with a length of 3.

Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.                                                                                                        

Input format :
The input consists of a string s.

Output format :
The output prints the length of the longest substring without repeating characters.



Refer to the sample output for the formatting specifications.

Code constraints :
1 ≤ s.length ≤ 100

Sample test cases :
Input 1 :
abcabcbb
Output 1 :
3
Input 2 :
bbbb
Output 2 :
1
Input 3 :
pwwkew
Output 3 :
3
*/

#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  */
    int findlengthoflongestsubstring(string str){
        int n = str.length();
        unordered_map<char,int> mp;
        int maxlen = 0;
        int l = 0, r = 0;
        while(r<n){
            if(mp.find(str[r]) != mp.end() && mp[str[r]] >= l){
                l = mp[str[r]]+1;
            }
            mp[str[r]] = r;
            maxlen = max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }

int main(){
    string str;
    getline(cin,str);
    cout<<findlengthoflongestsubstring(str);
return 0;
}