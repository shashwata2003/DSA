#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Given an integer array nums of unique elements, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.
Power set is the set of all subset.
eg: {1,2} ans {1}{2}{1,2}
hence given a set we need to return the power set
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]] 
Sol:
We need to run a loop in the i/p arr and for every value of we will run two function 1. Exclude the value from the 
o/p vector and a include function to include the value of in in the ans vector

 */

void solve(vector<int> arr,vector<vector<int>> &ans, vector<int> output,int index){
    if (index>=arr.size())
    {
        ans.push_back(output);
        return ;
    }
    //exclude:
    solve(arr,ans,output,index+1);
    //include:
    int element = arr[index];
    output.push_back(element);
    solve(arr,ans,output,index+1);
}
int main(){
    vector<int> arr={1,2,3};
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    solve(arr,ans,output,index);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j]<<endl;
        }
        
        cout<<endl;
    }
    
return 0;
}