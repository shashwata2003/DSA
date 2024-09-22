#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.

You must write an algorithm that runs in O(n) time and uses O(1) extra space. 

 

Example 1:

Input: n = 13
Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]
Example 2:

Input: n = 2
Output: [1,2]
 
 */

class Solution {
public:
    void solve(int curr, int n, vector<int> &result){
        if(curr > n){
            return;
        }
        result.push_back(curr);
        for(int i = 0; i<=9; i++){
            int newnum = curr*10+i;
            solve(newnum,n,result);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        for(int i = 1; i<=9; i++){
            solve(i,n,result);
        }
        return result;
    }
};

int main(){

return 0;
}