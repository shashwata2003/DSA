/*

Q5:

Problem Statement
Given an array and a value x, write a program to find if there is a triplet in the array whose sum is equal to the given value. If there is such a triplet present in the array, print the triplet.
Example
Input:

array = {12, 3, 4, 1, 6, 9}, x = 24
Output: 
12 3 9
Explanation: 

There is a triplet (12, 3, and 9) present, whose sum is equal to the given value of 24.

Input format :
The first line of input consists of an integer n, representing the number of elements.

The second line of input consists of n integers arr[i], separated by space.

The third line of input consists of an integer x, representing the sum value.

Output format :
If there exists a triplet in the array A whose sum is equal to the sum, print the three integers separated by space.

If no such triplet exists, print "No triplet found with the given sum".



Refer to the sample output for the formatting specifications.

Code constraints :
1 ≤ n ≤ 20

1 ≤ arr[i] ≤ 100

1 ≤ x ≤ 200

Sample test cases :
Input 1 :
6
12 3 4 1 6 9
24
Output 1 :
12 3 9
Input 2 :
6
4 8 9 3 4 5
25
Output 2 :
No triplet found with 
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void findTripletSum(vector<int> &arr, int n, int target) {
    sort(arr.begin(), arr.end());  // Sort the array for the two-pointer approach
    
    for (int i = 0; i < n - 2; i++) {  // Loop over the array
        if (i > 0 && arr[i] == arr[i - 1]) continue;  // Skip duplicates for the first element

        int l = i + 1;
        int r = n - 1;
        
        while (l < r) {
            int sum = arr[i] + arr[l] + arr[r];  // Calculate the sum of the triplet

            if (sum == target) {
                cout << arr[i] << " " << arr[l] << " " << arr[r] << endl;
                return;  // Return as soon as we find the first triplet
            } 
            else if (sum > target) {
                r--;  // Move right pointer to the left
            } 
            else {
                l++;  // Move left pointer to the right
            }
        }
    }

    // If no triplet is found
    cout << "No triplet found with the given sum" << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    
    // Input array elements
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int target;
    cin >> target;

    // Call the function to find the triplet
    findTripletSum(arr, n, target);
    
    return 0;
}
