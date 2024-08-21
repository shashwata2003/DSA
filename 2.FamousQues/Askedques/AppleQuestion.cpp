#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  */

int solve(vector<int> arr, int k){
    int maxans = INT_MIN;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int temp = 0;
        for (int j = i; j < n; j = j+k)
        {
            temp = arr[j] + temp;
        }
        maxans = max(maxans,temp);
    }
    return maxans;
}

int getSum(vector<int>& arr, int k, int i) {
    // Base case: If index goes out of bounds, return 0
    if (i >= arr.size()) {
        return 0;
    }

    // Recursive case: Include the current element and move k steps ahead
    int sum = arr[i] + getSum(arr, k, i + k);

    return sum;
}

int solveRecursively(vector<int>& arr, int k, int i, int maxans) {
    // Base case: If we've processed all starting indices, return the maxans
    if (i >= arr.size()) {
        return maxans;
    }

    // Get the sum starting from index i, jumping k steps at a time
    int temp = getSum(arr, k, i);

    // Update maxans if the current sum is greater
    maxans = max(maxans, temp);

    // Recur for the next starting index
    return solveRecursively(arr, k, i + 1, maxans);
}

int solverec(vector<int>& arr, int k) {
    return solveRecursively(arr, k, 0, INT_MIN);
}

int main() {
    vector<int> arr = {-1, 6, 4, 3, 4, -2};
    int k = 2;
    cout << solverec(arr, k);
    return 0;
}