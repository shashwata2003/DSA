#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Minimum swaps to make the aseq increasing:

Given two int array of same length, we can swap num1[i] and num2[i] , 
find the min no. of such swaps to make the num1 and num2 strictly increasing.

eg:
nums1[] = {1,3,5,4};
nums2[] = {1,2,3,7};
ans: 1:

 */

int solveusingrecursion(vector<int> &num1, vector<int> &num2, int i , bool swaped){
    if(i == num1.size()){
        return 0;
    }

    int prev1 =  num1[i-1];
    int prev2 =  num2[i-1];
    //The swaped variable is used as we are not making any changes in the actual array, so
    // so if the the previos variable is swaped and we are trying to find the prev then we will get the non
    //swaped vals only which will be wrong so , will in the previous call we swaped the ints then we need to 
    // swap rn
    if(swaped){
        swap(prev1,prev2);
    }

    int ans = INT_MAX;
    // no Swap
    if(num1[i] > prev1 && num2[i]>prev2){
        //swap == 0 as there is no swaps
        ans = solveusingrecursion(num1,num2,i+1,0);
    }
    
    //here we will swap only when the prev1<num2 and vice verse, as we need to check weather it will fit after 
    // the swap
    //IMP cond:
    if(num1[i]>prev2 && num2[i]>prev1){
        // finding the min also adding 1 as we have currently swaped
        ans = min(ans,1 + solveusingrecursion(num1,num2,i+1,1));
    }
    return ans;
}

//TS: O(n) SP: O(n)
int solveusingmemoization(vector<int> &num1, vector<int> &num2, int i , bool swaped, vector<vector<int>> &dp){
    if(i == num1.size()){
        return 0;
    }
    if(dp[i][swaped] != -1){
        return dp[i][swaped];
    }
    int prev1 =  num1[i-1];
    int prev2 =  num2[i-1];
    //The swaped variable is used as we are not making any changes in the actual array, so
    // so if the the previos variable is swaped and we are trying to find the prev then we will get the non
    //swaped vals only which will be wrong so , will in the previous call we swaped the ints then we need to 
    // swap rn
    if(swaped){
        swap(prev1,prev2);
    }

    int ans = INT_MAX;
    // no Swap
    if(num1[i] > prev1 && num2[i]>prev2){
        //swap == 0 as there is no swaps
        ans = solveusingmemoization(num1,num2,i+1,0,dp);
    }
    
    //here we will swap only when the prev1<num2 and vice verse, as we need to check weather it will fit after 
    // the swap
    //IMP cond:
    if(num1[i]>prev2 && num2[i]>prev1){
        // finding the min also adding 1 as we have currently swaped
        ans = min(ans,1 + solveusingmemoization(num1,num2,i+1,1,dp));
    }   
    dp[i][swaped] = ans;
    return dp[i][swaped];
}

//TS: O(n) SP: O(n)
int solveusingtabulation(vector<int> &num1, vector<int> &num2){
    //Base case is handled by the init of 0
    int n = num1.size();
    vector<vector<int>> dp(n+1,vector<int> (2,0));
    for (int index = n-1; index >= 0; index--)
    {
        for (int swaped = 1; swaped >= 0; swaped--)
        {
            int prev1 =  num1[index-1];
            int prev2 =  num2[index-1];
            //The swaped variable is used as we are not making any changes in the actual array, so
            // so if the the previos variable is swaped and we are trying to find the prev then we will get the non
            //swaped vals only which will be wrong so , will in the previous call we swaped the ints then we need to 
            // swap rn
            if(swaped){
                swap(prev1,prev2);
            }

            int ans = INT_MAX;
            // no Swap
            if(num1[index] > prev1 && num2[index]>prev2){
                //swap == 0 as there is no swaps
                ans = dp[index+1][0];
            }
            
            //here we will swap only when the prev1<num2 and vice verse, as we need to check weather it will fit after 
            // the swap
            //IMP cond:
            if(num1[index]>prev2 && num2[index]>prev1){
                // finding the min also adding 1 as we have currently swaped
                ans = min(ans,1 + dp[index+1][1]);
            }
            dp[index][swaped] = ans;
        }
        
    }
    return dp[1][0];
}


int solveusingspaceopti(vector<int> &num1, vector<int> &num2) {
    int n = num1.size();
    int swaps = 0;
    int noswap = 0;
    int currswap = 0;
    int currnoswap = 0;

    for (int index = n - 1; index > 0; index--) {
        currswap = INT_MAX;
        currnoswap = INT_MAX;

        for (int swaped = 0; swaped <= 1; swaped++) {
            int prev1 = num1[index - 1];
            int prev2 = num2[index - 1];
            int ans = INT_MAX;

            if (swaped) {
                swap(prev1, prev2);
            }

            if (num1[index] > prev1 && num2[index] > prev2) {
                ans = noswap;
            }

            if (num1[index] > prev2 && num2[index] > prev1) {
                ans = min(ans, 1 + swaps);
            }

            if (swaped) {
                currswap = ans;
            } else {
                currnoswap = ans;
            }
        }
        swaps = currswap;
        noswap = currnoswap;
    }
    return min(swaps, noswap);
}

int minSwap(vector<int> &num1, vector<int> &num2){

    // insert -1 at the begining of both the array/
    num1.insert(num1.begin(),-1);
    num2.insert(num2.begin(),-1);

    bool swapped = false;// this variable tells us that weather the last element pair was swapped or not
    int index = 1; // we are going to start from index 1 as we have inserted -1 at the beginning of the arr.

    //Using recursion:
    // int ans = solveusingrecursion(num1, num2, index, swapped);

    //Using memorization:
    int n = num1.size();
    // vector<vector<int>> dp(n,vector<int> (2,-1));
    // int ans = solveusingmemoization(num1,num2,index,swapped,dp);

    //Using tabulation:
    // int ans = solveusingtabulation(num1,num2);

    //Using Space optimization:
    // Here the ans depends upon: index+1 and 0 and index+1 and 1 , hence this means that the ans depends upon
    // 2*2 matrix like in notebook:
    int ans = solveusingspaceopti(num1,num2);

    return ans;
}



int main(){
    vector<int> num1 = {1,3,5,4};
    vector<int> num2 = {1,2,3,7};
    cout<<minSwap(num1,num2);
return 0;
}