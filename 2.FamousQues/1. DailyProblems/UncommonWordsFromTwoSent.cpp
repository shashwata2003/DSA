#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
A sentence is a string of single-space separated words where each word consists only of lowercase letters.

A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.

Given two sentences s1 and s2, return a list of all the uncommon words. You may return the answer in any order.

 

Example 1:

Input: s1 = "this apple is sweet", s2 = "this apple is sour"

Output: ["sweet","sour"]

Explanation:

The word "sweet" appears only in s1, while the word "sour" appears only in s2.
 */

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> wordCount; // Map to store the count of each word
        stringstream str1(s1); // String stream for the first sentence
        stringstream str2(s2); // String stream for the second sentence
        string word; // Variable to hold each word

        // Count words in the first sentence
        while (str1 >> word) {
            wordCount[word]++; // Increment the count for each word found
        }

        // Count words in the second sentence
        while (str2 >> word) {
            wordCount[word]++; // Increment the count for each word found
        }

        vector<string> result; // Vector to store the result of uncommon words
        
        // Collect words that appear exactly once in the combined sentences
        for (const auto& pair : wordCount) {
            if (pair.second == 1) { // Check if the word count is exactly one
                result.push_back(pair.first); // Add the word to the result vector
            }
        }

        return result; // Return the vector of uncommon words
    }
};

int main(){

return 0;
}