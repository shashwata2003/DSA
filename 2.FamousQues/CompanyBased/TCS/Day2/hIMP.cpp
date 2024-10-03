/*
Q6:
In the K-partition problem, we need to partition an array of positive integers into k-disjoint subsets that all have an equal sum and completely cover the set.
Example
Input:
9
7 5 2 6 6 1 8 9 4 
4

Output:
Partition 0 is 8 4 
Partition 1 is 2 1 9 
Partition 2 is 6 6 
Partition 3 is 7 5 

Input format :
The first line of input consists of an array size, N.

The second line consists of an array of elements separated by space.

The third line represents the value of k.

Output format :
The output prints the possible partitions that have an equal sum.



Refer to the sample output for the formatting specifications.

Sample test cases :
Input 1 :
9
7 5 2 6 6 1 8 9 4 
4
Output 1 :
Partition 0 is 8 4 
Partition 1 is 2 1 9 
Partition 2 is 6 6 
Partition 3 is 7 5 
Input 2 :
5
5 6 3 1 4 
3
Output 2 :
k-partition of set S is not possible
*/

#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
bool solve(int i, int bucket, int reqsum , unordered_map<int, bool> &vis, int &currsum, vector<int> &arr, int n, int k) {
    if (bucket == k) {  // All buckets successfully filled
        return true;
    }
    if (currsum == reqsum) {  // Current bucket has reached the required sum
        return solve(0, bucket + 1, reqsum, vis, currsum = 0, arr, n, k);
    }
    if (currsum > reqsum || i >= n) {  // Exceeding the sum or out of bounds
        return false;
    }
    if (vis[i]) {
        return solve(i + 1, bucket, reqsum, vis, currsum, arr, n, k);  // Skip already visited element
    } else {
        // Pick the current element
        vis[i] = true;
        currsum += arr[i];
        bool op1 = solve(i + 1, bucket, reqsum, vis, currsum, arr, n, k);

        // Backtrack
        vis[i] = false;
        currsum -= arr[i];
        bool op2 = solve(i + 1, bucket, reqsum, vis, currsum, arr, n, k);

        return op1 || op2;
    }
}

bool ispossible(int n, vector<int> &arr, int k) {
    unordered_map<int, bool> vis;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    if (sum % k != 0) {
        return false;
    }
    int reqsum = sum / k;
    int currsum = 0;
    int bucket = 1;
    int index = 0;
    return solve(index, bucket, reqsum, vis, currsum, arr, n, k);
}

int main() {
    int n;
    cin >> n;  // Input the size of the array
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    cout << ispossible(n, arr, k) << endl;

    return 0;
}
