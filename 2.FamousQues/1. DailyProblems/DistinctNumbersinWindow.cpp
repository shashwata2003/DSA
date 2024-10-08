#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* Distinct numbers in Window.
Problem Description

You are given an array of N integers, A1, A2 ,..., AN and an integer B. Return the of count of distinct numbers in all windows of size B.

Formally, return an array of size N-B+1 where i'th element in this array contains number of distinct elements in sequence Ai, Ai+1 ,..., Ai+B-1.

NOTE:  if B > N, return an empty array.



Input Format
First argument is an integer array A

Second argument is an integer B.



Output Format
Return an integer array.



Example Input
Input 1:

 A = [1, 2, 1, 3, 4, 3]
 B = 3
Input 2:

 A = [1, 1, 2, 2]
 B = 1


Example Output
Output 1:

 [2, 3, 3, 2]
Output 2:

 [1, 1, 1, 1]


Example Explanation
Explanation 1:

 A=[1, 2, 1, 3, 4, 3] and B = 3
 All windows of size B are
 [1, 2, 1]
 [2, 1, 3]
 [1, 3, 4]
 [3, 4, 3]
 So, we return an array [2, 3, 3, 2].
Explanation 2:

 Window size is 1, so the output array is [1, 1, 1, 1].
 */

vector<int> dNums(vector<int> &A, int B) {
    int n = A.size();
    int i = 0;
    vector<int> ans;
    unordered_set<int> st;
    while(i < B){
        st.insert(A[i]);
        i++;        
    }
    ans.push_back(st.size());
    for(int j = 1 ; j < n; j++){
        int k = j;
        unordered_set<int> st;
        while(k < i+1){
            st.insert(A[k]);
            k++;
        }
        ans.push_back(st.size());
        i++;
        if(i == n){
            break;
        }
    }
    return ans;
}

int main(){
    vector<int> A = {1, 2, 1, 3, 4, 3};
    int B = 3;
    vector<int> ans = dNums(A,B);
    for(int i = 0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
return 0;
}