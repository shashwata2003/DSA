#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  */

/*Apporach 1: Using prefix and suffix:*/
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n);
        vector<int> right(n);
        left[0] = height[0];
        for(int i = 1; i<n; i++){
            left[i] = max(height[i],left[i-1]);
        }
        right[n-1] = height[n-1];
        for(int i = n-2; i>=0; i--){
            right[i] = max(height[i],right[i+1]);
        }
        int ans = 0;
        for(int i = 0; i<n; i++){
            ans = ans+ min(right[i],left[i]) - height[i];
        }
        return ans;
    }
};

/*Apporach 2:
Steps:
1. We need to maintain two pointers l and r and two max value storing the max walls and we need cal the water stored between that walls
2. now we we encouter a higher wall we update the max l or r value 
3. if it smaller than the current wall we need to add the water that the curr wall and the max wall will store
hence that will we be given by the difference
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int right = n-1;
        int left = 0;
        int maxleft = 0; // max walls from left
        int maxright = 0; // from right
        int ans = 0;
        while(left<right){
            if(height[left] <= height[right]){ // right side wall is bigger
                if(height[left] >= maxleft){
                    maxleft = height[left]; // updating the maxwall value
                }else{
                    ans = ans + (maxleft - height[left]); // if not bigger then calcuate the water stored between maxwall and curr
                }
                left++;
            }else{ // similar here the left side has max wall
                if(height[right] > maxright){
                    maxright = height[right];
                }else{
                    ans = ans + (maxright - height[right]);
                }
                right--;
            }
        }
        return ans;
    }
};
int main(){

return 0;
}