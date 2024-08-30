#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Problem 1: Save the Plants
There are n number of dying plants. Each plant i has a saving factor sf[i], which is the minimum size of fertilizer bag that the plant can be saved with, and each fertilizer bag j has a size s[j]. If s[j] >= sf[i], we want to assign the fertilizer bag j to plant i, and the plant can be saved. Maximize the number of plants that we can save.

Example 1:
Input: saving factor (sf) = [1,2,3], fertilizer bag size (s) = [1,1]
Output: 1
Explanation: You have 3 plants and 2 fertilizer bags.
The saving factor of 3 plants are 1, 2, 3.
And even though you have 2 fertilizer bag, since their size is both 1, you could only save the plant having saving factor 1
You need to output 1.
 */

/* steps:
1. sort both the array:
2. now traverse each array one by one if at anypoint g<=s hence meeting the critiare we will move both the 
pointers ahead and and increment cnt
3. else we will just move the s counter to the head, as the array are sorted that means g[i] > s[j] that means 
we will never find a smaller value then this ahead
*/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int cnt = 0;
        int i = 0;
        int j = 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        while (i < g.size() && j < s.size()) {
            if (g[i] <= s[j]) {
                i++;
                j++;
                cnt++;
            }
            else if(g[i] >  s[j]){
                j++;
            }
        }
        return cnt;
    }
};

int main(){
    vector<int> sf = {1,2,3};
    vector<int> bag = {1,1};
    cout<<findContentChildren(sf,bag);
return 0;
}