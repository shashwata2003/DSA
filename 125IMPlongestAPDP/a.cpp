#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Longest Arithmetic Subsequence:
Given an array arr[] of sorted positive integers. For an array having no duplicate elements, 
find the length of the longest arithmetic progression in a given array arr[].

Note: A sequence seq is an arithmetic progression if seq[i + 1] - seq[i] are all the same value 
(for 0 <= i < seq.length - 1).

Examples:

Input:arr[] = [1, 7, 10, 13, 14, 19]
Output: 4
Explanation: The longest arithmetic progression is [1, 7, 13, 19].

Input:arr[] = [2, 4, 6, 8, 10]
Output: 5
Explanation: The whole array is in AP.


Sol:
Implemented Memorization and just recursion solution here

Next file implementated the tabulation method:

 */

//Using recursion: O(N^3)
int solverecursion(vector<int>& arr, int diff, int index){
    // This here is the part where we check the element before i and find and add the element with the same diff
    //Base case:
    if(index < 0){
        return 0;
    }

    int ans = 0;
    // we will start the traversal form the index and move till first index.
    for (int i = index-1; i >= 0; i--)
    {
        // Now when the differnce of element match we need to check the rest of the element
        if(arr[index] - arr[i] == diff){
            //Like: for pass 4 when we inserted 7, we need to start check after 7 taking it as the new ith 
            //index.
            ans = max(ans,1+solverecursion(arr, diff,i));
        }
    }
    return ans;
}

int solveusingmemorization(vector<int>& arr, int diff, int index, unordered_map<int,int> dp[]){
    // This here is the part where we check the element before i and find and add the element with the same diff
    //Base case:
    if(index < 0){
        return 0;
    }
    if(dp[index].count(diff)){
        return dp[index][diff];
    }
    int ans = 0;
    // we will start the traversal form the index and move till first index.
    for (int i = index-1; i >= 0; i--)
    {
        // Now when the differnce of element match we need to check the rest of the element
        if(arr[index] - arr[i] == diff){
            //Like: for pass 4 when we inserted 7, we need to start check after 7 taking it as the new ith 
            //index.
            ans = max(ans,1+solveusingmemorization(arr, diff,i,dp));
        }
    }

    return dp[index][diff] = ans;
}

int lengthOfLongestAP(vector<int>& arr) {
    //if the length of the input array is 1 then the max length will be 1 and same goes for 2:
    int n = arr.size();
    if(n<=2){
        return n;
    }

    //Now we will treverse each element using two pointers and find difference b/w each point like we did in 
    //Notebook:

    //Dp:
    unordered_map<int,int> dp[n+1];
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            //we are doing 2+ because while traversing the array using two pointer and finding the difference
            // we need to include the those two element that gave use the init difference to which we are
            // finding the other elements with the difference 
            //eg: (notebook) in pass 4, the solve function will return only 1,7 but we need to include 13,19
            /* which gave the init difference to start with.*/

            //Using recursion:
            // ans = max(ans,2+solverecursion(arr,arr[j] -  arr[i], i));

            //USing memorization:
            ans = max(ans,2+solveusingmemorization(arr,arr[j]- arr[i] ,i,dp));
        }
        
    }
    return ans;
}
int main(){
    vector<int> arr = {1, 7, 10, 13, 14, 19};
    cout<<lengthOfLongestAP(arr);
return 0;
}