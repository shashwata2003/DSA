#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
 Combination Sum IV:
You are given an array of distinct integers and you have to tell how many different ways of selecting the 
elements from the array are there such that the sum of chosen elements is equal to the target number tar.

Note: Two ways are considered the same if for every index the contents of both the ways are equal example 
way1=[1,2,3,1] and way2= [1,2,3,1] both way1 and way 2 are the same.

But if way1 =[1,2,3,4] and way2= [4,3,2,1] then both ways are different.

Input is given such that the answer will fit in a 32-bit integer. 
For Example:
If N = 3 and tar = 5 and array elements are [1,2,5] then the number of possible ways of making sum = 5 are:
(1,1,1,1,1)
(1,1,1,2)
(1,2,1,1)
(2,1,1,1)
(1,1,2,1)
(2,2,1)
(1,2,2)
(2,1,2)
(5)
Hence the output will be 9. 

Sample Input 1 :
2
3 5
1 2 5
2 3
1 2
Sample output 1 :
9
3
 */

//using only recusrion: TS: exponial
int solveusingrecursion(vector<int> &num, int tar, int n){
    if(tar == 0){
        return 1;
    }
    if( tar < 0){
        return 0;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = ans + solveusingrecursion(num,tar - num[i],n);
    }
    return ans;
}

//Using memorization: TS: O(tar) SP: O(tar)
int solveusingmemorization(vector<int> &num, int tar, int n, vector<int> &dp){
    if(tar == 0){
        return 1;
    }
    if( tar < 0){
        return 0;
    }
    if(dp[tar] != -1){
        return dp[tar];
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = ans + solveusingmemorization(num,tar - num[i],n,dp);
    }
    dp[tar] = ans;
    return dp[tar];
}

//Using tabulation method: TS: O(tar) SP: O(tar)
int solveusingtabulation(vector<int> &num, int tar, int n){
    vector<int> dp(tar+1,0);
    dp[0] = 1;

    //This terverses the dp array 
    for (int i = 1; i <= tar; i++)
    {
        // this tarversed the num array 
        for (int j = 0; j < n; j++)
        {
            //checking if the index for dp is valid or not:
            if(i-num[j] >= 0){
                dp[i] = dp[i] + dp[i-num[j]];
            }
        }
        
    }
    return dp[tar];
}

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    
    //Using only recursion:
    // int ans = solveusingrecursion(num,tar,n);

    //Using memorization:
    // the dp is dependent on the tar value hence the size , also we will make the recursion tree of size tar
    // vector<int> dp(tar+1,-1);
    // int ans = solveusingmemorization(num,tar,n,dp);

    //Using tabulation:
    // int ans = solveusingtabulation(num,tar,n);

    //Using spaceoptimization:
    // here we cannot implement as the dp[i] depents upon i - num[j] which we cannot store in a static varible 
    // like prev 1 hence we cannot optimize the space here

    return ans;
}

int main(){
    vector<int> nums = {1, 2, 5};
    int n = nums.size();
    int tar = 5;
    cout<<findWays(nums,tar);
return 0;
}