#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Mr. X is a professional robber planning to rob houses along a street. Each house has a certain amount of money 
hidden.
All houses along this street are arranged in a circle. That means the first house is the neighbour of the last
one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police 
if two adjacent houses are broken into on the same night.
You are given an array/list of non-negative integers 'ARR' representing the amount of money of each house.
Your task is to return the maximum amount of money Mr. X can rob tonight without alerting the police.

Sample Input 1:
3
1
0
3
2 3 2
4
1 3 2 1
Sample Output 1:
0
3
4

// Check notes:
Here we are only using the space optimized apporach:

TS: O(n)
SP: O(n)
 */



long long int solvespaceopt(vector<int> &arr, int n){
    if(n == 0) return 0;
    if(n == 1) return arr[0];
    
    long long int prev1 = arr[n-1]; // i+1
    long long int prev2 = 0; // i+2
    for (int i = n-2; i >= 0; i--) {
        long long int inclu = prev2 + arr[i];
        long long int exclu = prev1;
        long long int ans = max(inclu, exclu);
        prev2 = prev1;
        prev1 = ans;
    }

    return prev1;
}

long long int houseRobber(vector<int>& valueInHouse) {
    int n = valueInHouse.size();
    if (n == 1) {
        return valueInHouse[0];
    }

    vector<int> first(valueInHouse.begin(), valueInHouse.end()-1);
    vector<int> second(valueInHouse.begin()+1, valueInHouse.end());
    
    return max(solvespaceopt(first, n-1), solvespaceopt(second, n-1));
}
int main(){
    vector<int> arr = {2, 3, 2};
    cout<<houseRobber(arr);
return 0;
}