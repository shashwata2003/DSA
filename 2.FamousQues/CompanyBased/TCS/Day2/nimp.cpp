/*

Q12:
Problem Statement:



Given an integer array nums, find the subarray with the largest sum, and return its sum.



Example 1:



Input: n=9

nums = [-2,1,-3,4,-1,2,1,-5,4]

Output: 6

Explanation: The subarray [4,-1,2,1] has the largest sum 6.



Example 2:



Input: n=1 

nums = [1]

Output: 1

Explanation: The subarray [1] has the largest sum of 1.



Example 3:



Input: n=5 

nums = [5,4,-1,7,8]

Output: 23

Explanation: The subarray [5,4,-1,7,8] has the largest sum of 23.

Input format :
The first line consists of an integer n, representing the number of elements in the array nums.

The second line consists of n space-separated integers, representing the elements of the array nums.

Output format :
The output prints an integer, representing the sum of the subarray with the largest sum.



Refer to the sample output for formatting specifications.

Code constraints :
1 ≤ n ≤ 20

-100 ≤ nums[i] ≤ 100

Sample test cases :
Input 1 :
9
-2 1 -3 4 -1 2 1 -5 4
Output 1 :
6
Input 2 :
1
1
Output 2 :
1
Input 3 :
5
5 4 -1 7 8
Output 3:
23
*/

#include<iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int maxsum = 0, sum = 0;
    int start = 0, start_idx = 0, end_idx = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum > maxsum) {
            maxsum = sum;
            start_idx = start;  // Update start index of max subarray
            end_idx = i;        // Update end index of max subarray
        }

        if (sum < 0) {
            sum = 0;
            start = i + 1;  // Reset the start for the next potential subarray
        }
    }

    cout << "Maximum Sum: " << maxsum << endl;
    cout << "Subarray Indices: [" << start_idx << ", " << end_idx << "]" << endl;

    return 0;
}
