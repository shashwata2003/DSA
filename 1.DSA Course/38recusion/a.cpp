#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
IMP:
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the 
number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. 
Note that 1 does not map to any letters.
The string will form using the keypad phone arrangement.
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Sol:
Here we first need to create a mapping array which will store the value of every number key of the keyboard and map 
it with the no.. Next then take the input string and for each no. find the the mapped string to it . 
-> run a for loop for the string and start adding that to the output string 
- End case i>digit. lenght() return and ans.pushback(output)
 */

void solve(string input, vector<string> &ans, int i, string out, string map[]) {
    if (i >= input.length()) {  // corrected condition
        ans.push_back(out);
        return;
    }
    // the input number and the letter it holds
    int number = input[i] - '0';
    string value = map[number];
    // now run the loop for the i value 
    for (int j = 0; j < value.length(); j++) {
        out.push_back(value[j]);
        solve(input, ans, i + 1, out, map);
        out.pop_back();
    }
}

int main() {
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string input = "23";
    // if the input is null:
    if (input.length() == 0) {
        cout << "empty" << endl;
    }
    vector<string> ans;
    int index = 0;
    string output = "";
    solve(input, ans, index, output, mapping);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}