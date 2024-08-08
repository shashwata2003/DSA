#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Permutations

Given an array nums of distinct integers, return all the possible permutations. 
You can return the answer in any order.
Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]
 
https://leetcode.com/problems/permutations/
 */


/* this method is used when we are selecting a element and using all the element that occure behind and ahead of that element*/

void solve(vector<int>& nums, vector<vector<int>> &ans, int index){
    if(index == nums.size()){
        ans.push_back(nums);
        return;
    }

    for (int i = index; i < nums.size(); i++)
    {
        swap(nums[index],nums[i]);
        solve(nums,ans,index+1);
        swap(nums[index],nums[i]);
    }
    
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    int i = 0;
    solve(nums,ans,i);
    return ans;
}

int main(){
    vector<int> nums = {1,2,3};
    vector<vector<int>> ans = permute(nums);
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