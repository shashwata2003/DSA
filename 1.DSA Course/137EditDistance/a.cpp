#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Edit Distance:
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
 */

int solveusingrecursion(string w1, string w2, int i , int j){
    //base case out of bound:
    //This are the cases when the w1 is smaller than w2 hence we need to delete all the remaning words hence 
    // returning the length of that word
    if(i == w1.length()){
        return w2.length() - j;
    }
    if(j == w2.length()){
        return w1.length() - i;
    }

    int ans = 0;
    if(w1[i] == w2[j]){
        return solveusingrecursion(w1,w2,i+1,j+1);
    }else{
        //insert
        int insertletter = 1 + solveusingrecursion(w1,w2,i,j+1);
        //delete
        int deleteletter = 1 + solveusingrecursion(w1,w2,i+1,j);
        //replace:
        int replaceletter = 1 + solveusingrecursion(w1,w2,i+1,j+1);

        ans  = min(insertletter,min(deleteletter,replaceletter));
    }
    return ans;
}

int solveusingmemorization(string w1, string w2, int i , int j,vector<vector<int>> &dp){
    //base case out of bound:
    //This are the cases when the w1 is smaller than w2 hence we need to delete all the remaning words hence 
    // returning the length of that word
    if(i == w1.length()){
        return w2.length() - j;
    }
    if(j == w2.length()){
        return w1.length() - i;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int ans = 0;
    if(w1[i] == w2[j]){
        return solveusingmemorization(w1,w2,i+1,j+1,dp);
    }else{
        //insert
        int insertletter = 1 + solveusingmemorization(w1,w2,i,j+1,dp);
        //delete
        int deleteletter = 1 + solveusingmemorization(w1,w2,i+1,j,dp);
        //replace:
        int replaceletter = 1 + solveusingmemorization(w1,w2,i+1,j+1,dp);

        ans  = min(insertletter,min(deleteletter,replaceletter));
    }
    return dp[i][j] = ans;
}

int solveusingtabulation(string w1, string w2) {
    int n = w1.length();
    int m = w2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
    // Base cases
    for (int j = 0; j <= m; j++) {
        dp[n][j] = m - j;
    }
    for (int i = 0; i <= n; i++) {
        dp[i][m] = n - i;
    }

    // Fill the dp table
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (w1[i] == w2[j]) {
                dp[i][j] = dp[i + 1][j + 1];
            } else {
                int insertLetter = 1 + dp[i][j + 1];
                int deleteLetter = 1 + dp[i + 1][j];
                int replaceLetter = 1 + dp[i + 1][j + 1];
                dp[i][j] = min({insertLetter, deleteLetter, replaceLetter});
            }
        }
    }

    return dp[0][0];
}

int solveusingspaceopti(string w1, string w2) {
    int n = w1.length();
    int m = w2.length();
    vector<int> curr(m+1,0); //i
    vector<int> next(m+1,0); //i+1
    
    // Base cases:

    for (int j = 0; j <= m; j++) {
        next[j] = m - j;
    }
    // Fill the dp table
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            //base case: analysing the base case 2
            //Every last row need to have n-i value store as next = curr after each iternation hence placing 
            // it here
            curr[m] = n - i;
            if (w1[i] == w2[j]) {
                curr[j] = next[j + 1];
            } else {
                int insertLetter = 1 + curr[j + 1];
                int deleteLetter = 1 + next[j];
                int replaceLetter = 1 + next[j + 1];
                curr[j] = min({insertLetter, deleteLetter, replaceLetter});
            }
        }
        next = curr;
    }

    return curr[0];
}

int minDistance(string word1, string word2) {
    int i = 0, j = 0;
    int n = word1.length();
    int m = word2.length();
    if(m==0){
        return n;
    }
    if(n==0){
        return m;
    }
    //Using recursion:
    // int ans = solveusingrecursion(word1,word2,i,j);

    //using memorization:
    // vector<vector<int>> dp(n, vector<int>(m, -1));
    // int ans = solveusingmemorization(word1, word2, i, j, dp);

    //Using buttom down: using tabulation:
    // int ans = solveusingtabulation(word1,word2);

    //Using space optimization:
    int ans = solveusingspaceopti(word1,word2);
    
    return ans;
}

int main(){
    string word1 = "intention", word2 = "execution";
    cout<<minDistance(word1,word2);
return 0;
}