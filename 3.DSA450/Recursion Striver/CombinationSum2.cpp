#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  
Given a collection of candidate numbers (candidates) and a target number (target), find all unique 
combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]


https://leetcode.com/problems/combination-sum-ii/
*/

/*
Similar to last problem, the only two difference will be we will increment i for both inclu and exclu, as we 
cannot use same element multiple times
also we need to sort the array before to avoid duplicate subseq
*/

void solve(vector<int>& candidates, int target, vector<vector<int>> &ans, int index, vector<int> &temp){
    if(target == 0){
        ans.push_back(temp);
        return;
    }
    if(index >= candidates.size() || index < 0){
        return;
    }
    //to remove duplicates: we  need to use a loop the contidion that no two consecutive no. are same
    // and are processed simulatationallu
    // By using for loop eliminates the use of the not inclu case
    for (int i = index; i < candidates.size(); i++)
    {
        if(i > index && candidates[i] == candidates[i-1]) continue;
        
        temp.push_back(candidates[i]);
        solve(candidates,target - candidates[i],ans,i+1,temp);
        temp.pop_back();
    }
    
}

vector<vector<int>> combinationSum21(vector<int>& candidates, int target) {
    
    sort(candidates.begin(),candidates.end());
    int i = 0;
    vector<int> temp;
    solve(candidates,target,ans,i,temp);
    vector<vector<int>> ans = solve(candidates,target,ans,i,temp);
    return ans;
}

//Using DP:


int main(){
    vector<int> arr = {2,5,2,1,2};
    int n = 5;
    vector<vector<int>> ans = combinationSum21(arr,n);
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