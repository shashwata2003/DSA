#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*
Bus Routes:
You are given an array routes representing bus routes where routes[i] is a bus route that the ith bus
repeats forever.

For example, if routes[0] = [1, 5, 7], this means that the 0th bus travels in the sequence
1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ... forever.

You will start at the bus stop source (You are not on any bus initially), and you want to go to the bus stop
target. You can travel between bus stops by buses only.

Return the least number of buses you must take to travel from source to target. Return -1 if it is not possible.

Example 1:
Input: routes = [[1,2,7],[3,6,7]], source = 1, target = 6
Output: 2
Explanation: The best strategy is take the first bus to the bus stop 7, then take the second bus to the bus
stop 6.

Example 2:
Input: routes = [[7,12],[4,5,15],[6],[15,19],[9,12,13]], source = 15, target = 12
Output: -1

TS: O(m*k^2)
SP: O(m*k^2)
 */

int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
{
    if (source == target)
        return 0;

    // Map each stop to the list of routes that go through it
    unordered_map<int, vector<int>> stopsMap;
    for (int i = 0; i < routes.size(); i++)
    {
        for (int stop : routes[i])
        {
            stopsMap[stop].push_back(i);
        }
    }

    // BFS initialization
    unordered_set<int> visitedRoutes;
    queue<int> q;

    // Push all routes that contain the source stop
    for (int route : stopsMap[source])
    {
        q.push(route);
        visitedRoutes.insert(route);
    }

    int busCount = 1;

    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            int route = q.front();
            q.pop();

            // Visit all stops in the current route
            for (int stop : routes[route])
            {
                if (stop == target)
                {
                    return busCount;
                }
                // Add all routes that pass through this stop to the queue
                for (int nextRoute : stopsMap[stop])
                {
                    if (visitedRoutes.find(nextRoute) == visitedRoutes.end())
                    {
                        q.push(nextRoute);
                        visitedRoutes.insert(nextRoute);
                    }
                }
            }
        }
        busCount++;
    }

    return -1;
}

int main()
{
    vector<vector<int>> routes = {{1, 2, 7}, {3, 6, 7}};
    int src = 1;
    int tar = 6;
    cout << numBusesToDestination(routes, src, tar);
    return 0;
}