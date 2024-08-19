#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Given three corner points of a triangle, and one more point P. Write a function to check whether P 
lies within the triangle or not.

Example:

Input: A = (0, 0), B = (10, 30), C = (20, 0), P(10, 15)
Output: Inside
 */

/*
Find the area of teh given trangle 
then find the area of 3 triangle made with given point
Check if sum of A1, A2 and A3 is same as A 
*/


// Function to calculate the area of a triangle
float area(int x1, int y1, int x2, int y2, int x3, int y3) {
    return fabs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}

// Function to check if a point (x, y) is inside the triangle defined by (x1, y1), (x2, y2), (x3, y3)
bool isInside(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y) {
    // Calculate the area of the whole triangle
    float A = area(x1, y1, x2, y2, x3, y3);

    // Calculate the area of the triangle formed by the point and two vertices of the original triangle
    float A1 = area(x, y, x2, y2, x3, y3);
    float A2 = area(x1, y1, x, y, x3, y3);
    float A3 = area(x1, y1, x2, y2, x, y);

    // Check if the sum of A1, A2, and A3 is the same as A
    return (A == A1 + A2 + A3);
}

int main() {
    if (isInside(0, 0, 10, 30, 20, 0, 10, 15))
        cout << "Inside";
    else
        cout << "Not Inside";
    return 0;
}