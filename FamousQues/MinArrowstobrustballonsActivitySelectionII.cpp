#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Minimum Number of Arrows to Burst Balloons:(This a variation of Activity selection problem):
https://www.geeksforgeeks.org/problems/activity-selection-1587115620/1

There are some spherical balloons taped onto a flat wall that represents the XY-plane. The balloons are represented as a 2D integer array points where points[i] = [xstart, xend] denotes a balloon whose horizontal diameter stretches between xstart and xend. You do not know the exact y-coordinates of the balloons.

Arrows can be shot up directly vertically (in the positive y-direction) from different points along the x-axis. A balloon with xstart and xend is burst by an arrow shot at x if xstart <= x <= xend. There is no limit to the number of arrows that can be shot. A shot arrow keeps traveling up infinitely, bursting any balloons in its path.

Given the array points, return the minimum number of arrows that must be shot to burst all balloons.

Example 1:

Input: points = [[10,16],[2,8],[1,6],[7,12]]
Output: 2
Explanation: The balloons can be burst by 2 arrows:
- Shoot an arrow at x = 6, bursting the balloons [2,8] and [1,6].
- Shoot an arrow at x = 11, bursting the balloons [10,16] and [7,12].
Example 2:

Input: points = [[1,2],[3,4],[5,6],[7,8]]
Output: 4
Explanation: One arrow needs to be shot for each balloon for a total of 4 arrows.
Example 3:

Input: points = [[1,2],[2,3],[3,4],[4,5]]
Output: 2
Explanation: The balloons can be burst by 2 arrows:
- Shoot an arrow at x = 2, bursting the balloons [1,2] and [2,3].
- Shoot an arrow at x = 4, bursting the balloons [3,4] and [4,5].
 */

/*APporach:
1. we will sort the array by the xstart index
2. create a counot pointer
3. comapare the xend [i-1] > xstart[i] can be bust by the same arrow
4. else increament the pointer to tell we need another arrow.
*/

bool compare(vector<int> a, vector<int> b){
    return a[0]<b[0];
}

int findMinArrowShots(vector<vector<int>>& points) {
    if(points.size() ==  1){
        return 1;
    }
    int n = points.size();
    sort(points.begin(),points.end(),compare);
    int count = 1;
    int end = points[0][1];
    for (int i = 1; i < n; i++)
    {
        if(end > points[i][0]){
            /*If the current balloon's start is within the end, update the end to be the minimum of the 
            current end and the current balloon's end (this ensures you keep track of the overlapping interval*/
            end = min(end, points[i][1]); 
        }else{
            count++;
            end = points[i][1];
        }
    }
    return count;
}

int main(){
    vector<vector<int>> points = {{3, 9}, {7, 12}, {3, 8}, {6, 8}, {9, 10}, {2, 9}, {0, 9}, {3, 9}, {0, 6}, {2, 8}};
    
return 0;
}