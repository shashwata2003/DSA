#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Given a string s, return true if the s can be palindrome after deleting at most one character from it.
 */
bool isPalindrome(const string& s) {
    int l = 0;
    int r = s.length() - 1;
    while (l < r) {
        if (s[l] != s[r]) {
            return false;
        }
        l++;
        r--;
    }
    return true;
}
bool checkPalindrome(string s) {
    int l = 0;
    int r = s.length() - 1;
    while (l < r) {
        if (s[l] == s[r]) {
            l++;
            r--;
        } else {
            // Try removing the character at index l
            string s1 = s;
            s1.erase(l, 1);
            if (isPalindrome(s1)) {
                return true;
            }

            // Try removing the character at index r
            string s2 = s;
            s2.erase(r, 1);
            return isPalindrome(s2);
        }
    }
    return true;
}
int main(){
    string s = "aaazza";
    cout<<checkPalindrome(s)<<endl;
return 0;
}