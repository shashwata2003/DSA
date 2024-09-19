#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

countAndSay(1) = "1"
countAndSay(n) is the run-length encoding of countAndSay(n - 1).
Run-length encoding (RLE) is a string compression method that works by replacing consecutive identical characters (repeated 2 or more times) with the concatenation of the character and the number marking the count of the characters (length of the run). For example, to compress the string "3322251" we replace "33" with "23", replace "222" with "32", replace "5" with "15" and replace "1" with "11". Thus the compressed string becomes "23321511".

Given a positive integer n, return the nth element of the count-and-say sequence.

 

Example 1:

Input: n = 4

Output: "1211"

Explanation:

countAndSay(1) = "1"
countAndSay(2) = RLE of "1" = "11"
countAndSay(3) = RLE of "11" = "21"
countAndSay(4) = RLE of "21" = "1211"
Example 2:

Input: n = 1

Output: "1"

Explanation:

This is the base case. */


/*
Steps
Initialization of ans: The string ans is initialized with "1".
Counting Consecutive Characters: For each iteration, the code goes through the string ans and counts consecutive characters. Once a different character is encountered, it appends the count and the character to the temporary string.
Final Group Handling: The last group of characters is handled outside the loop to ensure it’s counted.
Return the Result: After n-1 iterations, the result is returned.
*/
class Solution {
public:
    string countAndSay(int n) {
        string ans = "1"; // Initialize the base case as a string
        for (int i = 1; i < n; ++i) {
            string temp = "";
            int count = 1;
            for (int j = 1; j < ans.size(); ++j) {
                if (ans[j] == ans[j - 1]) {
                    ++count;
                } else {
                    temp += to_string(count) + ans[j - 1];
                    count = 1;
                }
            }
            temp += to_string(count) + ans.back(); // Handle the last group
            ans = temp;
        }
        return ans;
    }
};


/* Apporach 2: Using recursion */
string countAndSay(int n, string s = "1") { // initial value of the string is "1"
    if(n == 1) return s; // base case, when n recursive calls are finished
	
    int i = 0, j, len = s.size(); // 'len' is the length of the string 's'
    string res = ""; // result after we 'say' the string 's'
	
	// 'i' starts from index 0
    while(i < len) {
        j = i; // fix 'j' as the current position (i)
		
		// increment the value of 'i' till valid position
        while(i < len && s[i] == s[j]) i++;
		
		// substring with same values as s[j] is [j, i-1] & "i-j" is the count of that value
		// add the concatenation of (count + s[j]) to the result 
        res += to_string(i - j) + s[j];
    }
	
	// recursively, call the same function by decrementing the count
	// and update the result 'res', which will be the next string 's'
    return countAndSay(n - 1, res);
}


//Using DP:

class Solution {
public:
    string solve(int n, string s, vector<string>& dp) {
        if (n == 1) {
            return s; // Base case, return the string "1" when n is 1
        }

        if (dp[n] != "-1") {
            return dp[n]; // Return the result from memoization if already computed
        }

        int i = 0, j, len = s.size(); // 'len' is the length of the string 's'
        string res = "";              // Result after we 'say' the string 's'

        // Process the string 's' to build the next sequence
        while (i < len) {
            j = i; // Fix 'j' as the current position (i)
            
            // Increment the value of 'i' till valid position
            while (i < len && s[i] == s[j]) {
                i++;
            }

            // Substring with the same values as s[j] is [j, i-1]
            // Add the concatenation of (count + s[j]) to the result
            res += to_string(i - j) + s[j];
        }

        // Recursively call the same function by decrementing the count
        return dp[n] = solve(n - 1, res, dp); // Update the result 'res' and store it in dp[n]
    }

    string countAndSay(int n) {
        vector<string> dp(n + 1, "-1"); // Initialize dp with "-1"
        return solve(n, "1", dp); // Call solve with initial string "1"
    }
};

int main(){

return 0;
}