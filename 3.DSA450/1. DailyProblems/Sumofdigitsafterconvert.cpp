#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
You are given a string s consisting of lowercase English letters, and an integer k.

First, convert s into an integer by replacing each letter with its position in the alphabet (i.e., replace 'a' with 1, 'b' with 2, ..., 'z' with 26). Then, transform the integer by replacing it with the sum of its digits. Repeat the transform operation k times in total.

For example, if s = "zbax" and k = 2, then the resulting integer would be 8 by the following operations:

Convert: "zbax" ➝ "(26)(2)(1)(24)" ➝ "262124" ➝ 262124
Transform #1: 262124 ➝ 2 + 6 + 2 + 1 + 2 + 4 ➝ 17
Transform #2: 17 ➝ 1 + 7 ➝ 8
Return the resulting integer after performing the operations described above.

 

Example 1:

Input: s = "iiii", k = 1
Output: 36
Explanation: The operations are as follows:
- Convert: "iiii" ➝ "(9)(9)(9)(9)" ➝ "9999" ➝ 9999
- Transform #1: 9999 ➝ 9 + 9 + 9 + 9 ➝ 36
Thus the resulting integer is 36.
Example 2:

Input: s = "leetcode", k = 2
Output: 6
Explanation: The operations are as follows:
- Convert: "leetcode" ➝ "(12)(5)(5)(20)(3)(15)(4)(5)" ➝ "12552031545" ➝ 12552031545
- Transform #1: 12552031545 ➝ 1 + 2 + 5 + 5 + 2 + 0 + 3 + 1 + 5 + 4 + 5 ➝ 33
- Transform #2: 33 ➝ 3 + 3 ➝ 6
Thus the resulting integer is 6.
Example 3:

Input: s = "zbax", k = 2
Output: 8
 */

/*
Steps:
1. convert all the letter in the string to its int vals and store the combined string in numarr
2. next find the sum of each digit in numarr and update the val of numarr to curr sum 
3. do this till k == 0
4. finily convert the ans to int

*/

class Solution {
public:
    int getLucky(string s, int k) {
        string numarr;
        
        // Convert each character to its corresponding number in string form
        for (char ch : s) {
            int num = (ch - 'a') + 1;
            numarr += to_string(num);  // Convert the number to a string and append
        }
        
        // Perform the transformation k times
        while (k > 0) {
            int sum = 0;
            
            // Sum all digits in numarr
            for (char digit : numarr) {
                sum += (digit - '0');  // Convert character to integer and add to sum
            }
            
            // Convert the sum back to a string
            numarr = to_string(sum);
            k--;
        }
        
        // Convert the final string to an integer and return
        return stoi(numarr);
    }
};


int main(){

return 0;
}