#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  */


int solve(string s) {
    int n = s.length();
    int lastLength = 0;
    int currentLength = 0;

    // Traverse the string
    for (int i = 0; i < n; i++) {
        if (s[i] == '-' || s[i] == '|') {
            // When we hit a separator, update the lastLength if a valid word was found
            if (currentLength > 0) {
                lastLength = currentLength;
            }
            currentLength = 0;  // Reset current length for the next word
        } else {
            currentLength++;  // Count the length of the current word
        }
    }

    // If the last character isn't a separator, update the last length
    if (currentLength > 0) {
        lastLength = currentLength;
    }

    return lastLength;
}


int main() {
    string s = "Elephant-Tiger-lion-";
    string s1 = "|Horse-dog-cat-|";

    cout << solve(s1) << endl;
    return 0;
}
