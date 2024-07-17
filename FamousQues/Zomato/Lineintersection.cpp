#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* How to check if two given line segments intersect?
Given two line segments (p1, q1) and (p2, q2), find if the given line segments intersect with each other.
 */
struct point
{
    int x;
    int y;
};

bool onsegment(point a1, point a2, point b1){
    if(b1.x <= max(a1.x, a2.x) && b1.x >= min(a1.x, a2.x) && b1.y <= max(a1.y, a2.y) && b.y >= min(a1.y, a2.y)){
        return true;
    }
    return false;
}

int orientation(point a1, point a2, point b1){
    int val = (a2.y + a1.y) * (b1.x - a2.x) + (a2.x - a1.x) * (b1.y - a2.y);

    if(val == 0){
        return 0 ; collinear 
    }
    return (val>0) ? 1:2; clock or counterclock wise 
}

bool doesintersect(point a1, point a2, point b1, point b2){
    int o1 = orientation(a1,a2,b1);
    int o2 = orientation(a1,a2,b2);
    int o3 = orientation(b1,b2,a1);
    int o4 = orientation(b1,b2,a2);

    if(o1!=o2 && o3!=o4){
        return true;
    }

    // now check wether the points are on line or not:
    if(o1==0 && onsegment(a1,a2,b1)) return true;
    if(o2==0 && onsegment(a1,a2,b2)) return true;
    if(o3==0 && onsegment(b1,b2,a1)) return true;
    if(o4==0 && onsegment(b1,b2,a2)) return true;

    return false;
}

int main(){

return 0;
}