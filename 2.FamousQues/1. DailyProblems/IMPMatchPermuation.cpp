#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  */

/*Using Sorting nlogn*/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        string sorteds1 = s1;
        sort(sorteds1.begin(),sorteds1.end());
        for(int i = 0; i<m; i++){
            string temp = s2.substr(i,n);
            sort(temp.begin(),temp.end());
            if(temp == sorteds1){
                return true;
            }
        }
        return false;
    }
};

/*Using Sliding window:*/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        
        // Early return if s1 is longer than s2
        if (n > m) return false;

        // Create frequency maps for s1 and the first window of s2
        vector<int> mp1(26, 0), mp2(26, 0);
        for (char c : s1) {
            mp1[c - 'a']++;
        }

        // Sliding window approach
        for (int r = 0; r < m; r++) {
            mp2[s2[r] - 'a']++;

            // Maintain the window size
            if (r >= n) {
                mp2[s2[r - n] - 'a']--;
            }

            // Compare frequency counts
            if (mp1 == mp2) {
                return true;
            }
        }

        return false;
    }
};


int main(){

return 0;
}