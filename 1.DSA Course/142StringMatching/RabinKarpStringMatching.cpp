#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
The Karp-Rabin algorithm is a string searching algorithm that uses hashing to find a pattern in a text.
 */



class KarpRabin {
private:
    const int PRIME = 101;

    // Function to calculate the initial hash value for the string
    long long calculateHash(const string& str) {
        long long hash = 0;
        for (int i = 0; i < str.length(); i++) {
            hash += str[i] * pow(PRIME, i);
        }
        return hash;
    }

    // Function to update the hash when sliding the window in the text
    long long updateHash(long long prevHash, char oldChar, char newChar, int patternLength) {
        long long newHash = (prevHash - oldChar) / PRIME;
        newHash += newChar * pow(PRIME, patternLength - 1);
        return newHash;
    }

public:
    // Function to search for the pattern in the given text
    void search(const string& text, const string& pattern) {
        int patternLength = pattern.length();
        int textLength = text.length();

        // Calculate the hash for the pattern and the first window of text
        long long patternHash = calculateHash(pattern);
        long long textHash = calculateHash(text.substr(0, patternLength));

        // Loop through the text to find matches
        for (int i = 0; i <= textLength - patternLength; i++) {
            // If the hashes match, check the actual substring
            if (textHash == patternHash) {
                if (text.substr(i, patternLength) == pattern) {
                    cout << "Pattern found at index " << i << endl;
                }
            }

            // Update the hash for the next window
            if (i < textLength - patternLength) {
                textHash = updateHash(textHash, text[i], text[i + patternLength], patternLength);
            }
        }
    }
};

int main() {
    KarpRabin kr;
    string text = "ababcabcabababd";
    string pattern = "ababd";
    kr.search(text, pattern);
    return 0;
}

