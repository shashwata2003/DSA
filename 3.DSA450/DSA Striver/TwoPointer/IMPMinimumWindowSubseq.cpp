#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* Minimum Window Subsequence
Given strings str1 and str2 containing lowercase English letters, find the minimum (contiguous) substring w of str1, so that str2 is a subsequence of w. If there is no such window in str1 that covers all characters in str2, return the empty string. If there are multiple such minimum-length windows, return the one with the left-most starting index.

Examples:

Input: str1: geeksforgeeks  str2: eksrg
Output: eksforg
Explanation: "eksforg" satisfies all required conditions. str2 is its subsequence and it is longest and leftmost among all possible valid substrings of str1.
Input: 
Input: str1: abcdebdde str2: bde 
Output:  bcde 
Explanation:  "bcde" is the answer and "deb" is not a smaller window because the elements in the window must occur in order.
 */

class Solution {
  public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        int i=0, j=0, k=0;
        string ans;
        int sz = 1e9;
        for(i=0,j=0; i<n && k<m; ){
            if(s[i]==t[k]){
                k++;
            }
            
            // fixing end point
            if(k==m){
                j=i;
                k=m-1;
                
                //minimising our starting point
                while(k>=0 && j>=0){
                    if(s[j]==t[k]) k--;
                    j--;
                }
                j++;
                
                // now this can be our substring i.e. s[j..i]
                if(sz>(i-j+1)){
                    sz = i-j+1;
                    ans = s.substr(j,sz);
                }
                i=j;
                k=0;
            }
            i++;
        }
        return ans;
    }
};

int main(){

return 0;
}