#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  
Minimum Score Triangulation of Polygon:
You have a convex n-sided polygon where each vertex has an integer value. You are given an integer array 
values where values[i] is the value of the ith vertex (i.e., clockwise order).

You will triangulate the polygon into n - 2 triangles. For each triangle, the value of that triangle is 
the product of the values of its vertices, and the total score of the triangulation is the sum of these 
values over all n - 2 triangles in the triangulation.

Return the smallest possible total score that you can achieve with some triangulation of the polygon.

Input: values = [1,2,3]
Output: 6
Explanation: The polygon is already triangulated, and the score of the only triangle is 6.

Input: values = [3,7,4,5]
Output: 144
Explanation: There are two triangulations, with possible scores: 3*7*5 + 4*5*7 = 245, or 3*4*5 + 3*4*7 = 144.
The minimum score is 144.

*/

//Using recursion only
int solveusingrecursion(vector<int> &val,int start, int end){
    //If there are only two points in the triangle hence the next point will be the end 
    if(start+1 == end){
        return 0;
    }
    int ans = INT_MAX;
    //finding the third point b/w start and end
    for (int i = start+1; i < end; i++)
    {
        int temp = val[start]*val[end]*val[i] + solveusingrecursion(val,start,i) 
                    + solveusingrecursion(val,i,end); // finding the score for start to i and i to end 
                                                      //and adding it all 
        ans = min(ans,temp); //finding the min score
    }
    return ans;
}

//Ts: O(n*n) SP: O(n*n)
int solveusingmemorization(vector<int> &val,int start, int end, vector<vector<int>> &dp){
    //If there are only two points in the triangle hence the next point will be the end 
    if(start+1 == end){
        return 0;
    }
    if(dp[start][end] != -1){
        return dp[start][end];
    }
    int ans = INT_MAX;
    //finding the third point b/w start and end
    for (int i = start+1; i < end; i++)
    {
        int temp = val[start]*val[end]*val[i] + solveusingmemorization(val,start,i,dp) 
                    + solveusingmemorization(val,i,end,dp); // finding the score for start to i and i to end 
                                                      //and adding it all 
        ans = min(ans,temp); //finding the min score
    }
    dp[start][end] = ans;
    return dp[start][end];
}

int solveusingtabulation(vector<int> &val,int n){
    vector<vector<int>> dp(n,vector<int> (n,0));
    for (int i = n-1; i >= 0; i--)
    {
        for (int j = i+2; j < n; j++)
        {
            //i is the start and j is the end index:
            int ans = INT_MAX;
            for (int k = i+1; k < j; k++)
            {
                int temp = val[i]*val[j]*val[k] + dp[i][k] + dp[k][j];
                ans = min(ans,temp);
            }
            dp[i][j] = ans;
        }
        
    }
    
    return dp[0][n-1];
}

int minScoreTriangulation(vector<int>& values) {

    int start = 0, end = values.size()-1;

    //Using recursion:
    // int ans = solveusingrecursion(values,start,end);

    //Using DP:
    int n = values.size();
    // vector<vector<int>> dp(n,vector<int>(n,-1));
    // int ans = solveusingmemorization(values,start,end,dp);

    //Using tabulation:
    int ans = solveusingtabulation(values,n);

    //Using Space opt:
    // Here we cannot implement space optimization as for each ans both row and col are changing
    // this lead us to create the entire dp vector which will be not space optimized.
    
    return ans;
}

int main(){
    vector<int> arr = {3,7,4,5};
    cout<<minScoreTriangulation(arr);
return 0;
}