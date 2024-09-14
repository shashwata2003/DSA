#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Given a string A. The only operation allowed is to insert characters at the beginning of the string.
Find how many minimum characters are needed to be inserted to make the string a palindrome string.


Problem Constraints
1 <= |A| <= 106


Input Format
The only argument given is string A.


Output Format
Return the minimum characters that are needed to be inserted to make the string a palindrome string.


Example Input
Input 1:
A = "ABC"
Input 2:
A = "AACECAAAA"


Example Output
Output 1:
2
Output 2:
2


Example Explanation
Explanation 1:
Insert 'B' at beginning, string becomes: "BABC".
Insert 'C' at beginning, string becomes: "CBABC".
Explanation 2:
Insert 'A' at beginning, string becomes: "AAACECAAAA".
Insert 'A' at beginning, string becomes: "AAAACECAAAA".
 */

int ispalindrome(string A){
    string rev = A;
    reverse(rev.begin(),rev.end());
    if(rev == A){
        return true;
    }else{
        return false;
    }
}

int solve(string A){
    int n = A.length();
    
    int cnt = 0;
    while(A.length()>0 && ispalindrome(A) == false){
        cnt++;
        A.erase(A.begin()+A.length() - 1);
    }
    return cnt;
}

int main(){
    string A = "AACECAAAA";
    cout<<solve(A)<<endl;
return 0;
}