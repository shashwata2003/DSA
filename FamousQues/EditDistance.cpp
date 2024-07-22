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

int solveusingrecursion(string &w1, string &w2, int n, int m){
    if(n == 0){
        return m;
    }
    if(m == 0){
        return n;
    }

    if(w1[n-1] == w2[m-1]){
        return solveusingrecursion(w1,w2,n-1,m-1);
    }
    int insert = solveusingrecursion(w1,w2,n-1,m);
    int replace = solveusingrecursion(w1,w2,n-1,m-1);
    int remove = solveusingrecursion(w1,w2,n,m-1);
    int ans = 1 + min(insert,min(replace,remove));
    
    return ans;
}

int solveusingmemorization(string &w1, string &w2, int n, int m, vector<vector<int>> &dp){
    //Base case: if any word length is 0 then we need to add the entire other word in it in the length of the 
    //other word is returned.
    if(n == 0){
        return m;
    }
    if(m == 0){
        return n;
    }
    if(dp[n][m] != -1){
        return dp[n][m];
    }
    //if the last letter is same then check the rest of the element
    if(w1[n-1] == w2[m-1]){
        return solveusingrecursion(w1,w2,n-1,m-1);
    }

    //CHecking all three operation:
    int insert = solveusingrecursion(w1,w2,n-1,m);
    int replace = solveusingrecursion(w1,w2,n-1,m-1);
    int remove = solveusingrecursion(w1,w2,n,m-1);
    
    //add +1 for the current and add the min of three   
    int ans = 1 + min(insert,min(replace,remove));
    dp[n][m] = ans;
    return dp[n][m];
}

int minDistance(string word1, string word2) {
    int n = word1.length();
    int m = word2.length();
    //Using recursion:
    // int ans = solveusingrecursion(word1,word2,n,m);

    //Using memorization:
    // the Sol dependends upon the length of both words hence the 2d dp array.
    vector<vector<int>> dp(n+1,vector<int> (m+1, -1));
    int ans = solveusingmemorization(word1, word2,n,m,dp);
    return  ans;        
}
int main(){
    string w1 = "intention";
    string w2 = "execution";
    cout<<minDistance(w1,w2);
return 0;
}