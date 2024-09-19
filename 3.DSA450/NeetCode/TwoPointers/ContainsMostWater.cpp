#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  Container With Most Water
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
Example 2:

Input: height = [1,1]
Output: 1
 */

/* 
Steps:
1. Use two pointers one at the 0 and one at the end
2. now find the area of the current points using the min height and breath
3. now when we need to move the l and r 
4. find the pointer which is bigger if l > r then move r --
5. else move l++;
 */

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n-1;
        int ans = INT_MIN;
        while(l<r){
            int area = min(height[l],height[r]) * (r-l);
            ans = max(area,ans);
            if(height[l] > height[r]){
                r--;
            }else{
                l++;
            }
        }
        return ans;
    }
};

int main(){

return 0;
}