#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Two sum II 
Given a sorted array and a target we need to find the indexs whose sum will be equal to the target
1 based index.
eg:
arr {2,7,11,15}
target: 9
ans: 1,2
 */

vector<int> twosum(vector<int> arr, int target){
    int mini = 0;
    int maxi = arr.size()-1;
    vector<int> ans;
    while(mini<maxi){
        int sum = arr[mini]+arr[maxi];
        if(sum == target){
            ans.push_back(mini+1);
            ans.push_back(maxi+1);
            break;
        }
        else if(sum > target){
            maxi = maxi -1;
        }
        else if(sum<target){
            mini = mini +1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {2,7,11,15};
    int target = 9;
    vector<int> ans = twosum(arr,target);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
return 0;
}