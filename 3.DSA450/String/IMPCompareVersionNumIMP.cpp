#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Given two version strings, version1 and version2, compare them. A version string consists of revisions separated by dots '.'. The value of the revision is its integer conversion ignoring leading zeros.

To compare version strings, compare their revision values in left-to-right order. If one of the version strings has fewer revisions, treat the missing revision values as 0.

Return the following:

If version1 < version2, return -1.
If version1 > version2, return 1.
Otherwise, return 0.
 

Example 1:

Input: version1 = "1.2", version2 = "1.10"

Output: -1

Explanation:

version1's second revision is "2" and version2's second revision is "10": 2 < 10, so version1 < version2.

Example 2:

Input: version1 = "1.01", version2 = "1.001"

Output: 0

Explanation:

Ignoring leading zeroes, both "01" and "001" represent the same integer "1".

Example 3:

Input: version1 = "1.0", version2 = "1.0.0.0"

Output: 0

Explanation:

version1 has less revisions, which means every missing revision are treated as "0".
 */

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n = version1.length();
        int m = version2.length();
        int i = 0, j = 0;
        
        while (i < n || j < m) {
            int v1 = 0, v2 = 0;
            
            // Parse version1 segment
            while (i < n && version1[i] != '.') {
                v1 = v1 * 10 + (version1[i] - '0');
                i++;
            }
            
            // Parse version2 segment
            while (j < m && version2[j] != '.') {
                v2 = v2 * 10 + (version2[j] - '0');
                j++;
            }
            
            // Compare parsed segments
            if (v1 < v2) {
                return -1;
            } else if (v1 > v2) {
                return 1;
            }
            
            // Move past the dot in version strings, if present
            if (i < n && version1[i] == '.') {
                i++;
            }
            if (j < m && version2[j] == '.') {
                j++;
            }
        }
        
        return 0;
    }
};


int main(){

return 0;
}