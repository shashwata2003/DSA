/*
Q3:
You are a software developer working for a grocery store chain. The store manager has asked you to create a tool to help track and identify a specific range of daily expenses that match a target budget. The manager wants to know if there is a continuous subarray of daily expenses that sums up exactly to the target budget, to analyze spending patterns and optimize budget allocations.
Given a list of daily expenses over a period of N days, your task is to write a program that identifies a continuous subarray of these expenses that sums up to a given target budget. If such a subarray exists, the program should output the 1-based indices of the starting and ending days of this subarray. If no such subarray is found, the program should indicate this.
Example 1
Input: 
5
1 2 3 7 5
12
Output: 
2 4
Explanation:
The sum of elements from the 2nd position to the 4th position is 12.
Example 2
Input:
10
1 2 3 4 5 6 7 8 9 10
15
Output:
1 5
Explanation:
The sum of elements from 1st position to 5th position is 15.
Example 3
Input
7
10 36 48 26 39 10 24
100

Output
No subarray found with the given sum
Explanation:

In this test case, there is no subarray whose elements sum up to 100. All possible combinations of subarrays are examined, but none of them have a sum equal to 100. Therefore, the output correctly indicates that no such subarray exists.
Company Tags: Microsoft

Input format :
The first line consists of an integer N representing the number of days.

The second line consists of an array of N integers where each integer represents the daily expense, separated by a space.

The third line consists of an integer S representing the target budget sum.

Output format :
The output displays one of the following:

The 1-based indices of the starting and ending days of the continuous subarray that sum to S.

If no such subarray exists, print "No subarray found with the given sum".



Refer to the sample output for the formatting specifications.

Code constraints :
1 ≤ N ≤ 10

1 ≤ daily expense ≤ 100

1 ≤ S ≤ 1000

Sample test cases :
Input 1 :
5
1 2 3 7 5
12
Output 1 :
2 4
Input 2 :
10
1 2 3 4 5 6 7 8 9 10
15
Output 2 :
1 5
Input 3 :
7
10 36 48 26 39 10 24
100
Output 3 :
No subarray found with the given sum
*/

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

void findtheindex(vector<int> &arr, int t, int n){
    int currsum = 0;
    unordered_map<int, int> mp;
    mp[0] = -1;  // To handle the case when subarray starts from index 0
    
    for (int i = 0; i < n; i++) {
        currsum += arr[i];
        
        // Check if currsum - t exists in the map
        if(mp.find(currsum - t) != mp.end()) {
            cout << mp[currsum - t] + 2 << " " << i + 1 << endl; // 1-based indexing
            return;
        }
        
        // Store the current sum in the map
        mp[currsum] = i;
    }
    
    // If no subarray found, output the default message
    cout << "No subarray found with the given sum" << endl;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    
    // Input array elements
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int t;
    cin >> t;
    
    // Call the function to find the subarray
    findtheindex(arr, t, n);
    
    return 0;
}
