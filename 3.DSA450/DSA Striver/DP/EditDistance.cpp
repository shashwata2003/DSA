#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Edit Distance:
Given two strings str1 and str2. Return the minimum number of operations required to convert str1 to str2.
The possible operations are permitted:

Insert a character at any position of the string.
Remove any character from the string.
Replace any character from the string with any other character.
Examples:

Input: str1 = "geek", srt2 = "gesek"
Output: 1
Explanation: One operation is required, inserting 's' between two 'e'.
Input : str1 = "gfg", str2 = "gfg"
Output: 0
Explanation: Both strings are same.
 */

    int solve(string s1, string s2, int i, int j) {
        if (i == 0) {
            return j;
        }
        if (j == 0) {
            return i;
        }
        if (s1[i - 1] == s2[j - 1]) {
            return solve(s1, s2, i - 1, j - 1);
        }
        int insert = 1 + solve(s1, s2, i, j - 1);
        int deleted = 1 + solve(s1, s2, i - 1, j);
        int replace = 1 + solve(s1, s2, i - 1, j - 1);
        return min(insert, min(deleted, replace));
    }

    int editDistance(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        return solve(str1, str2, n, m);
    }


/*DP implemented*/
class Solution{
	private:
	    int solve(int arr[], int n, int curr, int ans){
	        if(curr >= n){
	            return 0;
	        }
	        int taken = 0;
	        if(ans == -1 || arr[curr]>arr[ans]){
	            taken = arr[curr] + solve(arr,n,curr+1,curr);
	        }
	        int nottaken = solve(arr,n,curr+1,ans);
	        return max(taken,nottaken);
	    }
	        int solvetab(int arr[], int n) {
        // Create DP table
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        // Traverse in reverse (from last element to the first)
        for (int curr = n-1; curr >= 0; curr--) {
            for (int prev = curr-1; prev >= -1; prev--) {
                int taken = 0;
                // If prev == -1, no previous element, otherwise ensure arr[curr] > arr[prev]
                if (prev == -1 || arr[curr] > arr[prev]) {
                    taken = arr[curr] + dp[curr+1][curr+1];  // Take the current element
                }
                int nottaken = dp[curr+1][prev+1];  // Skip the current element
                
                // Update DP
                dp[curr][prev+1] = max(taken, nottaken);
            }
        }

        // The answer is in dp[0][0] (start with no previous element)
        return dp[0][0];
    }


	public:
	int maxSumIS(int arr[], int n)  
	{  
	    int curr = 0;
	    int ans = -1;
	    
	    return solvetab(arr,n);
	}  
};

int main(){
    string str1 = "geek";
    string str2 = "gesek";
    cout<<editDistance(str1,str2);
return 0;
}