#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* Minimum Platforms:
Given arrival and departure times of all trains that reach a railway station. Find the minimum number of 
platforms required for the railway station so that no train is kept waiting.
Consider that all the trains arrive on the same day and leave on the same day. Arrival and departure time 
can never be the same for a train but we can have arrival time of one train equal to departure time of the 
other. At any given instance of time, same platform can not be used for both departure of a train and arrival 
of another train. In such cases, we need different platforms.

Examples:

Input: n = 6, arr[] = {0900, 0940, 0950, 1100, 1500, 1800}, 
            dep[] = {0910, 1200, 1120, 1130, 1900, 2000}
Output: 3
Explanation: There are three trains during the time 0940 to 1200. So we need minimum 3 platforms.
Input: n = 3, arr[] = {0900, 1235, 1100}, 
            dep[] = {1000, 1240, 1200}
Output: 1
Explanation: All train times are mutually exlusive. So we need only one platform
Input: n = 3, arr[] = {1000, 0935, 1100}, 
            dep[] = {1200, 1240, 1130}
Output: 3
Explanation: All 3 trains have to be their from 11:00 to 11:30
 */

/*
We will implement kinda same logic that we implemented in carpooling:
1. Create a vector for all the dep.times
2. now increament and decrement the no. of train at the arr and dep time 
3. and now find the max no. of platforms needed.
*/

// Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n) {
        // Finding the maximum departure time
        int lastdeparturetime = dep[0];
        for (int i = 1; i < n; i++) {
            lastdeparturetime = max(lastdeparturetime, dep[i]);
        }

        // Create a vector to store the count of trains at each time
        vector<int> v(lastdeparturetime + 2, 0);

        // Increment the count at the arrival time and decrement at the departure time
        for (int i = 0; i < n; i++) {
            v[arr[i]]++;
            v[dep[i] + 1]--; 
            /* When a train departs at dep[i], it means that a platform is no longer required 
            from the time immediately after dep[i]. Therefore, to signify that the platform is freed 
            right after dep[i], we decrement the count at dep[i] + 1. */
        }

        int maxplat = 0;
        int curr = 0;
        // Iterate over the vector and keep track of the maximum number of platforms needed
        for (int i = 0; i <= lastdeparturetime + 1; i++) {
            curr += v[i];
            maxplat = max(maxplat, curr);
        }

        return maxplat;
    }
int main(){

return 0;
}