#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  */

/*Solution 2: Optimised  Approach 1

Approach: We will have two pointers left and right. Pointer ‘left’ is used for maintaining the starting point of the substring while ‘right’ will maintain the endpoint of the substring.’ right’ pointer will move forward and check for the duplicate occurrence of the current element if found then the ‘left’ pointer will be shifted ahead so as to delete the duplicate elements.*/

int solve(string str) {

  if(str.size()==0)
      return 0;
  int maxans = INT_MIN;
  unordered_set < int > set;
  int l = 0;
  for (int r = 0; r < str.length(); r++) // outer loop for traversing the string
  {
    if (set.find(str[r]) != set.end()) //if duplicate element is found
    {
      while (l < r && set.find(str[r]) != set.end()) {
        set.erase(str[l]);
        l++;
      }
    }
    set.insert(str[r]);
    maxans = max(maxans, r - l + 1);
  }
  return maxans;
}


/*Apporach 2:
Here in place of the set we will manage a map with the index of the appearing chars
Everything will be same as the previous apporach.
Just when we find the repeating char in the map we will not just increment l = l+1 but we will move L = mp[ch]+1
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0; 
        int r = 0;
        int maxlength = 0;
        unordered_map<char, int> mp;
        int n = s.length();
        
        while (r < n) {
            // If the character has been seen before and its index is greater or equal to l
            if (mp.find(s[r]) != mp.end() && mp[s[r]] >= l) {
                l = mp[s[r]] + 1;  // Move l to the right of the last occurrence
            }
            
            // Update the current character's index
            mp[s[r]] = r;
            
            // Calculate the max length
            maxlength = max(maxlength, r - l + 1);
            
            // Move to the next character
            r++;
        }
        
        return maxlength;
    }
};

int main(){

return 0;
}