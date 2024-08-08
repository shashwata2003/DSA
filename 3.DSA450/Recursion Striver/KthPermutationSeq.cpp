#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*
Permutation Sequence:

The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

 

Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"
Example 3:

Input: n = 3, k = 1
Output: "123"

https://leetcode.com/problems/permutation-sequence/

*/


/* Brute Force:
Find all the possible permutation and sort them 
and return the kth permutation
 */
void findAllPermutations(string &s, int index, vector<string> &permu) {
    if (index == s.size()) {
        permu.push_back(s);
        return;
    }
    for (int i = index; i < s.size(); i++) {
        swap(s[index], s[i]);
        findAllPermutations(s, index + 1, permu);
        swap(s[index], s[i]); // Backtrack
    }
}

string getPermutation(int n,int k) {
    string s;
    for (int i = 1; i <= n; i++) {
        s += to_string(i);
    }
    vector<string> permu;
    findAllPermutations(s, 0, permu);
    sort(permu.begin(),permu.end());
    return permu[k-1];
}

/*
OPtimization:
Check notes for the explaination:

https://takeuforward.org/data-structure/find-k-th-permutation-sequence/

*/

string getPermutation(int n, int k) {
    int fact = 1;
    vector<int> num;
    for (int i = 1; i < n; i++)
    {
        fact = fact * i;
        num.push_back(i);
    }
    num.push_back(n);

    string ans = "";
    k = k-1;
    while (true)
    {
        ans = ans + to_string(num[k/fact]);
        num.erase(num.begin()+ k/fact);
        if(num.size() == 0){
            break;
        }
        k = k%fact;
        fact = fact/num.size();
    }
    return ans;
}

int main(){
    int n = 3;
    string ans = getPermutation(n,3);
    cout<<ans;
    
return 0;
}