#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  
Minimum Score Triangulation of Polygon:
You have a convex n-sided polygon where each vertex has an integer value. You are given an integer array 
values where values[i] is the value of the ith vertex (i.e., clockwise order).

You will triangulate the polygon into n - 2 triangles. For each triangle, the value of that triangle is 
the product of the values of its vertices, and the total score of the triangulation is the sum of these 
values over all n - 2 triangles in the triangulation.

Return the smallest possible total score that you can achieve with some triangulation of the polygon.

Input: values = [1,2,3]
Output: 6
Explanation: The polygon is already triangulated, and the score of the only triangle is 6.

Input: values = [3,7,4,5]
Output: 144
Explanation: There are two triangulations, with possible scores: 3*7*5 + 4*5*7 = 245, or 3*4*5 + 3*4*7 = 144.
The minimum score is 144.

*/

int minScoreTriangulation(vector<int>& values) {
        
}

int main(){
    vector<int> arr = {3,7,4,5};
    cout<<minScoreTriangulation(arr);
return 0;
}