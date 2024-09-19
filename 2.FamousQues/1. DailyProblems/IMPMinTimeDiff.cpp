#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.
 

Example 1:

Input: timePoints = ["23:59","00:00"]
Output: 1
Example 2:

Input: timePoints = ["00:00","23:59","00:00"]
Output: 0
 */

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes; // This will store the time in minutes for all time points
        
        // Convert each time point from "HH:MM" format into total minutes
        for(auto i : timePoints){
            int hr = stoi(i.substr(0,2));  // Extract hours and convert to integer
            int min = stoi(i.substr(3));   // Extract minutes and convert to integer
            int totalmin = hr * 60 + min;  // Convert the time to total minutes from midnight
            minutes.push_back(totalmin);   // Store the total minutes in the minutes vector
        }
        
        // Sort the minutes vector to easily find the minimum difference between consecutive times
        sort(minutes.begin(), minutes.end());
        
        // To handle the circular nature of the clock (24 hours), add the first time point again
        // by adding 24*60 minutes (a full day) to it, allowing us to compute the difference between
        // the first and the last time points
        minutes.push_back(minutes[0] + (24 * 60)); // Add 1440 minutes (24 hours) to the first time
        
        int mindiff = INT_MAX;  // Initialize mindiff with a very large value (infinity)
        
        // Iterate through the sorted minutes and find the minimum difference between consecutive times
        for(int i = 1; i < minutes.size(); i++){
            // Calculate the difference between consecutive time points and update mindiff if smaller
            mindiff = min(mindiff, minutes[i] - minutes[i-1]);
        }
        
        return mindiff;  // Return the smallest time difference found
    }
};


int main(){

return 0;
}