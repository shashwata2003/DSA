/*
Consider an event where a log register is maintained containing the guest’s arrival and departure times. Given an array of arrival and departure times from entries in the log register, find the point when there were the most guests present at the event.
Note: If an arrival and departure event coincide, the arrival time is preferred over the departure time.
Example:

Input:
arrival = { 1, 2, 4, 7, 8, 12 }
departure = { 2, 7, 8, 12, 10, 15 }
Output: Maximum number of guests is 3, present at time 7
Explanation:

Maximum Overlapping Interval

Input format :
The first line of input contains an integer value 'n', representing the number of guests.

The second line of input consists of n integers representing the arrival time of each guest.

The third line of input is an integer value 'm', which represents the number of guests for departure.

The fourth line of input consists of m integers representing the departure time of each guest.

Output format :
The first line of the output displays the maximum number of guests present at any time.

The second line of the output displays the time when the maximum number of guests are present.



Refer to the sample output for the formatting specifications.

Code constraints :
1 ≤ n ≤ 10

1 ≤ m ≤ 10

Sample test cases :
Input 1 :
6
5 2 3 7 8 9
6
1 2 3 5 6 7
Output 1 :
2
1
Input 2 :
6
1 2 4 7 8 12
6
2 7 8 12 10 15
Output 2 :
7
3
Expected Time Complexity : O(1)
Expected Space Complexity : O(1)
*/

#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;

int main(){
    int n;
    cin >> n; // Read the number of guests
    
    vector<int> arr(n); // Vector to store arrival times
    vector<int> dep(n); // Vector to store departure times

    // Input arrival times
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // Input departure times
    for(int i = 0; i < n; i++){
        cin >> dep[i];
    }

    // Sorting both arrival and departure times to process them in order
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int i = 0, j = 0; // i tracks arrivals, j tracks departures
    int cnt = 0; // Variable to keep track of the current number of guests
    int maxguest = 0; // To store the maximum number of guests at any time
    int time = arr[0]; // To store the time at which maxguest occurs

    // Traverse through both arrays to find max number of guests at any time
    while(i < n && j < n){
        // If a guest arrives before or at the same time as a departure
        if(arr[i] <= dep[j]){
            cnt++; // Increment guest count
            // Update maxguest and the time if the current guest count is the highest so far
            if(maxguest < cnt){
                maxguest = cnt;
                time = arr[i]; // Record the time when max guests were present
            }
            i++; // Move to the next arrival
        }else{
            cnt--; // Guest departs, decrease count
            j++; // Move to the next departure
        }
    }

    // Output the maximum number of guests and the time at which it happens
    cout << maxguest << " " << time;
    return 0;
}
