#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
given a positive integer N, return the sum of digits at even places and odd places.
 */

pair<int, int> findsum(int N) {
    string num = to_string(N);
    int evensum = 0;
    int oddsum = 0;
    for (int i = 0; i < num.length(); i++) {
        if (i % 2 == 0) {
            evensum += num[i] - '0';  // Convert character to integer
        } else {
            oddsum += num[i] - '0';  // Convert character to integer
        }
    }
    return {evensum, oddsum};
}

int main() {
    int N = 1234;
    pair<int, int> sums = findsum(N);
    cout << "Even index sum: " << sums.first << ", Odd index sum: " << sums.second << endl;
    return 0;
}