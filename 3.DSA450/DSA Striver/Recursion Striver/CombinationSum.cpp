#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*
Given an array of distinct integers candidates and a target integer target, return a list of all unique 
combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the 
frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 
150 combinations for the given input.

 

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
Example 3:

Input: candidates = [2], target = 1
Output: []


https://leetcode.com/problems/combination-sum/submissions/1348583128/
*/

void solve(vector<int>& candidates, int target,vector<vector<int>> &ans,int index, vector<int> &temp){
    if(target == 0){
        ans.push_back(temp);
        return;
    }
    if(index >= candidates.size() || target < 0){
        return;
    }
    temp.push_back(candidates[index]);
    solve(candidates,target-candidates[index],ans,index,temp);
    temp.pop_back();
    solve(candidates,target,ans,index+1,temp);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    int i = 0;
    vector<int> temp;
    solve(candidates,target,ans,i,temp);
    return ans;
}
int main(){
    vector<int> arr = {2,3,5};
    int target = 8;
    vector<vector<int>> ans = combinationSum(arr,target);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    
return 0;
}