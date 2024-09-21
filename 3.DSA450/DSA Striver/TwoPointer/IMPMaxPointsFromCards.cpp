#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Maximum Points You Can Obtain from Cards
There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.
Example 1:

Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.
Example 2:

Input: cardPoints = [2,2,2], k = 2
Output: 4
Explanation: Regardless of which two cards you take, your score will always be 4.
Example 3:

Input: cardPoints = [9,7,7,9,7,7,9], k = 7
Output: 55
Explanation: You have to take all the cards. Your score is the sum of points of all cards.

Steps:
As we can only select from the begining or the end of the array so 
1. we will have two sum one r and l sum 
2. first find sum of all the ele form teh left side and 
3. then try removing one from the left and adding one to the right form the back 
4. keep tracking the maxsum 
 */

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int maxsum = 0;
        int lsum = 0;
        int rsum = 0;
        int n = cardPoints.size();
        for(int i =0; i<k; i++){
            lsum = lsum + cardPoints[i];
        }
        maxsum = lsum;
        int j = n-1;
        for(int i = k-1; i>=0; i--){
            lsum -= cardPoints[i];
            rsum += cardPoints[j];
            j--;
            maxsum = max(maxsum,lsum+rsum);
        }
        return maxsum;
    }
};

int main(){

return 0;
}