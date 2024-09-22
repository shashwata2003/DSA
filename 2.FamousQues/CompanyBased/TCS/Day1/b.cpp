#include <bits/stdc++.h>
using namespace std;
/*
Problem statement
Given an array 'arr' with 'n' elements, the task is to rotate the array to the left by 'k' steps, where 'k' is non-negative.

Example:

'arr '= [1,2,3,4,5]

'k' = 1  rotated array = [2,3,4,5,1]

'k' = 2  rotated array = [3,4,5,1,2]

'k' = 3  rotated array = [4,5,1,2,3] and so on.



Sample Input 1: 

8

7 5 2 11 2 43 1 1

2

Sample Output 1:

2 11 2 43 1 1 7 5

Explanation of Sample Input 1:

Rotate 1 steps to the left: 5 2 11 2 43 1 1 7

Rotate 2 steps to the left: 2 11 2 43 1 1 7 5



Sample Input 2:

4

5 6 7 8

3

Sample Output 2:

8 5 6 7

Explanation of Sample Input 2:

Rotate 1 steps to the left: 6 7 8 5

Rotate 2 steps to the left: 7 8 5 6

Rotate 3 steps to the left: 8 5 6 7

Expected Time Complexity:

O(n), where ‘n’ is the size of the array ‘arr’ and ‘k’ is the number of rotations.
 */

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int k;
    cin >> k; // Read the value of k

    // Rotate the array k times
    while (k--) {
        int ele = arr[0]; // Get the first element
        arr.erase(arr.begin()); // Remove the first element
        arr.push_back(ele); // Push the first element to the back
    }

    // Output the modified vector
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    return 0;
}
