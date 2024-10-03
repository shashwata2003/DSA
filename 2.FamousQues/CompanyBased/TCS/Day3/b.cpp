/*
Q2:
Problem Statement



Given an array of strings strs, group the anagrams together. You can return the answer in any order.



An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.



Example:

Input: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]

Output: [["bat"],["nat", "tan"],["ate", "eat", "tea"]]                            

Input format :
The first line consists of an integer n, representing the number of strings.

The second line consists of n space-separated strings, represented as strs.

Output format :
The output prints grouped anagrams, where each group is present in a separate line, and inside each group, the anagrams are separated by a space.



Refer to the sample output for the formatting specifications.

Code constraints :
1 ≤ strs.length (n) ≤ 20

1 ≤ strs[i].length ≤ 30

strs[i] consists of lowercase English letters.

Sample test cases :
Input 1 :
6
eat tea tan ate nat bat
Output 1 :
bat 
tan nat 
eat tea ate 
Input 2 :
2
ab nj
Output 2 :
nj 
ab 
Input 3 :
3
abc cba cab
Output 3 :
abc cba cab 

*/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> findAnagramPairs(int n, vector<string> &arr) {
    unordered_map<string, vector<string>> anagramGroups;
    
    for (int i = 0; i < n; i++) {
        string sortedStr = arr[i];
        sort(sortedStr.begin(), sortedStr.end());
        anagramGroups[sortedStr].push_back(arr[i]);
    }

    vector<vector<string>> ans;
    for (auto &group : anagramGroups) {
        ans.push_back(group.second);
    }
    
    return ans;
}

int main() {
    int n;
    cin >> n;
    cin.ignore(); // to consume the leftover newline from cin

    vector<string> arr(n);
    for (int i = 0; i < n; i++) {
        getline(cin, arr[i]);
    }

    vector<vector<string>> ans = findAnagramPairs(n, arr);

    for (const auto &group : ans) {
        for (const string &str : group) {
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}
