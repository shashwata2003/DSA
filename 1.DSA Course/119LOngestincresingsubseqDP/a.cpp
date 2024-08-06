#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Longest Increasing Subsequence

Given an array a[ ] of n integers, find the Length of the Longest Strictly Increasing Subsequence.

A sequence of numbers is called "strictly increasing" when each term in the sequence is smaller than the 
term that comes after it.

Example 1:

Input: n = 6, a[ ] = {5,8,3,7,9,1}
Output: 3
Explanation: There are more than one LIS in this array.  
One such Longest increasing subsequence is {5,7,9}.
Example 2:

Input: n = 16, a[ ] = {0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15}
Output: 6
Explanation: There are more than one LIS in this array. 
One such Longest increasing subsequence is {0,2,6,9,13,15}.
 */

//Using only recursion:
int solveusingrecursion(int n, int a[],int currindex, int ansindex){
    if(currindex == n){
        return 0;
    }
    
    //Include:
    int taken = 0;
    if(ansindex == -1 || a[currindex]>a[ansindex]){
        //Includeing the current element in the ans, hence the ansindex becomes the curr
        // 1+ to increment the size of the ans vector
        taken = 1+solveusingrecursion(n,a,currindex+1,currindex);
    }

    //exclud:
    // as the current element is not included hende the ansindex remains the same and the currindex become +1
    int nottaken = solveusingrecursion(n,a,currindex+1,ansindex);

    return max(taken,nottaken); // max of the two will be the ans
}

//SP: O(n2) and Ts: O(n2)
int solveUsingMemorization(int n, int a[], int currIndex, int ansIndex, vector<vector<int>> &dp) {
    if (currIndex == n) {
        return 0;
    }
    //+1 because we are starting the index of ans form -1 which is a invalid index.
    if (dp[currIndex][ansIndex + 1] != -1) {
        return dp[currIndex][ansIndex + 1];
    }

    // Include the current element
    int taken = 0;
    if (ansIndex == -1 || a[currIndex] > a[ansIndex]) {
        // Including the current element in the answer, hence ansIndex becomes currIndex
        // 1+ to increment the size of the answer vector
        taken = 1 + solveUsingMemorization(n, a, currIndex + 1, currIndex, dp);
    }

    // Exclude the current element
    // As the current element is not included, the ansIndex remains the same and currIndex becomes currIndex + 1
    int notTaken = solveUsingMemorization(n, a, currIndex + 1, ansIndex, dp);

    dp[currIndex][ansIndex + 1] = max(taken, notTaken);
    return dp[currIndex][ansIndex + 1]; // Max of the two will be the answer
}

int solveusingatbulation(int n , int a[]){
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    // base case is handled by the init:
    // we will start filling from the end
    for (int cur = n-1; cur >= 0; cur--)
    {
        // the ans index prev will always start from one back from curr
        for (int prev = cur - 1; prev >= -1; prev--)
        {
            //same logic:
            int taken = 0;
            if(prev == -1 || a[prev]<a[cur]){
                //cur+1 beacause we need to change the location of the current to 
                taken = 1 + dp[cur+1][cur+1];
            }
            
            int notaken = 0 + dp[cur+1][prev+1];
            //prev+1 because we need to take care of the case prev = -1
            dp[cur][prev+1] = max(taken,notaken);
        }
        
    }
    return dp[0][0];
}

//SP: O(n)
int solveusingspaceopti(int n , int a[]){
    vector<int> curr(n+1,0); //n
    vector<int> next(n+1,0); //n+1
    for (int cur = n-1; cur >= 0; cur--)
    {
        // the ans index prev will always start from one back from curr
        for (int prev = cur - 1; prev >= -1; prev--)
        {
            //same logic:
            int taken = 0;
            if(prev == -1 || a[prev]<a[cur]){
                //cur+1 beacause we need to change the location of the current to 
                taken = 1 + next[cur+1];
            }
            
            int notaken = 0 + next[prev+1];
            //prev+1 because we need to take care of the case prev = -1
            curr[prev+1] = max(taken,notaken);
        }
        next = curr;
        
    }
    return next[0];
}

int solveusingninarysearch(int n, int a[]){
    if(n == 0){
        return 0;
    }
    vector<int> ans;
    //Push the first element as we dont have anything to compare with the first element
    ans.push_back(a[0]);

    for (int i = 1; i < n; i++)
    {
        //checking every element after that.
        if(a[i]>ans.back()){
            //if the current element is greather than the last element we will push it 
            ans.push_back(a[i]);
        }else{
            //now find the just bigger element to the a[i]:
            //Using lowerbound of binary search:  return an iterator pointing to the 
            //first element in the range [first, last) which has a value not less than val.
            int index = lower_bound(ans.begin(),ans.end(),a[i]) - ans.begin();
            // now replace:
            ans[index] = a[i];
        }
    }
    return ans.size();
}

 int longestSubsequence(int n, int a[])
{
    int currindex = 0, ansindex = -1;
    //using only recursion
    // int ans = solveusingrecursion(n,a,currindex,ansindex);

    //Using memorization:
    // the matrix is made for n element and for ans vector from -1 to n-1 index
    // vector<vector<int>> dp(n,vector<int> (n+1,-1));
    // int ans = solveUsingMemorization(n,a,currindex,ansindex,dp);

    //Using tabulation: buttom up:
    // int ans = solveusingatbulation(n,a);

    //using space optimization:
    // Here the ans depends upon two rows cur and cur+1
    // int ans = solveusingspaceopti(n,a);

    //Using binary search + dp:
    int ans = solveusingninarysearch(n,a);

    return ans;
}

int main(){
    int n = 16;
    int a[n] = {0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15};
    cout<<longestSubsequence(n,a);
return 0;
}