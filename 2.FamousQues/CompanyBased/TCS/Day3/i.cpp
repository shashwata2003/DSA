/*

Q9:
Problem Statement



Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.



Note that the same word in the dictionary may be reused multiple times in the segmentation.



Example 1:

Input: s = "applepenapple", wordDict = ["apple","pen"]

Output: true

Explanation: Return true because "applepenapple" can be segmented as "apple pen apple". Note that you are allowed to reuse a dictionary word.



Example 2:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]

Output: false

Input format :
The first line of input consists of a string s, representing the input string.

The second line consists of an integer n, indicating the number of words in the dictionary.

The next line consists of n space-separated strings representing the words of the dictionary.

Output format :
If the input string can be segmented into words from the dictionary, output "true".

If the input string cannot be segmented into words from the dictionary, output "false".



Refer to the sample output for the formatting specifications.

Code constraints :
1 ≤ s.length ≤ 100

1 ≤ wordDict.length ≤ 10

1 ≤ wordDict[i].length ≤ 100

s and wordDict[i] consist of only lowercase English letters.

All the strings of wordDict are unique.

Sample test cases :
Input 1 :
applepenapple
2
apple pen
Output 1 :
true
Input 2 :
catsandog
5
cats dog sand and cat
Output 2 :
false
*/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

bool ispossible(string str, int n, vector<string> &arr) {
    int m = str.length();
    int l = 0, r = 0;
    set<string> st(arr.begin(), arr.end());

    while (r < m) {
        string s = str.substr(l, r - l + 1);
        if (st.find(s) != st.end()) {  // Corrected the check for substring s
            l = r + 1;  // Move 'l' to the next position after the matched word
        }
        r++;
    }

    return l == m;  // Check if the entire string was processed
}

int main() {
    string str;
    getline(cin, str);  // Input the main string
    int n;
    cin >> n;  // Input the number of words in the dictionary
    vector<string> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];  // Input the dictionary words
    }

    if (ispossible(str, n, arr)) {
        cout << "true";
    } else {
        cout << "false";
    }
    
    return 0;
}
