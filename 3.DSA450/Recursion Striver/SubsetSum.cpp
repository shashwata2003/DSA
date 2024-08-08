#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  
Given a list arr of n integers, return sums of all subsets in it. Output sums can be printed in any order.

Example 1:
Input:
n = 2
arr[] = {2, 3}
Output:
0 2 3 5
Explanation:
When no elements is taken then Sum = 0.
When only 2 is taken then Sum = 2.
When only 3 is taken then Sum = 3.
When element 2 and 3 are taken then 
Sum = 2+3 = 5.

Example 2:
Input:
n = 3
arr = {5, 2, 1}
Output:
0 1 2 3 5 6 7 8


https://www.geeksforgeeks.org/problems/subset-sums2234/1

Same inclu and exclu logic , to inclu or not to inclu the current eem in the sum

*/

void solve(vector<int> &arr, vector<int> &ans, int n, int i, int sum){
    if(i == n){
        ans.push_back(sum);
        return;
    }
     solve(arr,ans,n,i+1,sum+arr[i]);
     solve(arr,ans,n,i+1,sum);

}

vector<int> subsetSums(vector<int> arr, int n) {
    vector<int> ans;
    int i = 0, sum = 0;
    solve(arr,ans,n,i,sum);
    sort(ans.begin(),ans.end());
    return ans;
}

int main(){
    int n = 3;
    vector<int> arr = {5, 2, 1};
    vector<int> ans = subsetSums(arr,n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
return 0;
}