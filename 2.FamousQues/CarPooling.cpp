#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*
Car Pooling:
There is a car with capacity empty seats. The vehicle only drives east (i.e., it cannot turn around and
drive west).

You are given the integer capacity and an array trips where trips[i] = [numPassengersi, fromi, toi]
indicates that the ith trip has numPassengersi passengers and the locations to pick them up and drop them
off are fromi and toi respectively. The locations are given as the number of kilometers due east from the
car's initial location.

Return true if it is possible to pick up and drop off all passengers for all the given trips, or false
otherwise.



Example 1:

Input: trips = [[2,1,5],[3,3,7]], capacity = 4
Output: false
Example 2:

Input: trips = [[2,1,5],[3,3,7]], capacity = 5
Output: true
 */

/*
Here we need to check weather we can make all the trips in the input, if anyone of them is not possible
we return false
https://algo.monster/liteproblems/1094

1. Create a centralized data array with total passerges at a given point 
2. now at any on that point the passenger is more than the capacity return false


Try :Minimum Platforms: https://www.geeksforgeeks.org/minimum-number-platforms-required-railwaybus-station/
*/

bool carPooling(vector<vector<int>> &trips, int capacity)
{
    vector<int> delta(1001, 0);
    for (int i = 0; i < trips.size(); i++)
    {
        int pass = trips[i][0];
        int start = trips[i][1];
        int end = trips[i][2];
        delta[start] += pass;
        delta[end] -= pass;
    }

    int currpass = 0;
    for (const int i : delta)
    {
        currpass += i;
        if (currpass > capacity)
        {
            return false;
        }
    }
    return true;
}
int main()
{

    return 0;
}