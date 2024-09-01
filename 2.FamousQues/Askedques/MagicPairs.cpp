#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  */
// Function to compare two numbers and check if they share any digit
bool compare(int a, int b) {
    vector<int> diga;
    vector<int> digb;

    // Extract digits of the first number
    while (a) {
        int dig = a % 10;
        diga.push_back(dig);
        a = a / 10;
    }

    // Extract digits of the second number
    while (b) {
        int dig = b % 10;
        digb.push_back(dig);
        b = b / 10;
    }

    // Compare digits of both numbers
    for (int i = 0; i < diga.size(); i++) {
        for (int j = 0; j < digb.size(); j++) {
            if (diga[i] == digb[j]) {
                return true;
            }
        }
    }

    return false;
}

// Function to find the number of magic pairs in the array
int findmagicpairs(int n, vector<int> arr) {
    vector<bool> vis(n, false);
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) { // Start from i + 1 to avoid redundant checks
            if (!vis[i] && !vis[j]) {
                if (compare(arr[i], arr[j])) {
                    count++;
                }
            }
        }
    }

    return count;
}

int main() {
    vector<int> arr = {54, 44, 4};
    cout << "Number of magic pairs: " << findmagicpairs(arr.size(), arr) << endl;
    return 0;
}