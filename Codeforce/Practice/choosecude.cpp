#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 

 */

string ChoosingCubes(vector<int> arr, int k, int f, int n) {
    int fav = arr[f - 1]; // Adjust for 1-based index
    sort(arr.begin(), arr.end(), greater<int>());
    
    bool alwaysRemoved = false;
    bool neverRemoved = true;

    for (int i = 0; i < k; i++) {
        if (arr[i] == fav) {
            alwaysRemoved = true;
        } else if (i + 1 < k && arr[i + 1] == fav) {
            neverRemoved = false;
        }
    }
    
    if (alwaysRemoved && neverRemoved) {
        return "maybe";
    } else if (alwaysRemoved) {
        return "yes";
    } else {
        return "no";
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, k, f;
        cin >> n >> k >> f;
        vector<int> arr(n);
        for (int j = 0; j < n; j++) {
            cin >> arr[j];
        }
        cout << ChoosingCubes(arr, k, f, n) << endl;
    }
    return 0;
}