/*

Q4:
Problem Statement
You are given a string. Using a recursive function, you have to obtain different combinations of the string or in other words permutations of the given string and all the sub-strings in alphabetical order.

Note: The characters within the sub-string can be repeated.
Example
Input:
ABC
﻿Output:

AAA AAB AAC ABA ABB ABC ACA ACB ACC BAA BAB BAC BBA BBB BBC BCA BCB BCC CAA CAB CAC CBA CBB CBC CCA CCB CCC 

Input format :
The input consists of a string.

Output format :
The output prints the list of permuted strings, separated by a space.



Refer to the sample output for formatting specifications.

Code constraints :
The input consists of uppercase characters and a maximum length of 4 characters.

Sample test cases :
Input 1 :
BD
Output 1 :
BB BD DB DD 
Input 2 :
ABC
Output 2 :
AAA AAB AAC ABA ABB ABC 

*/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// Recursive function to generate all permutations
void solve(string s, string current, int n, vector<string> &ans) {
    // If the current string is of the same length as the input string
    if(current.length() == n) {
        ans.push_back(current);
        return;
    }
    
    // Loop through each character of the original string and recursively build the combinations
    for(int i = 0; i < n; i++) {
        solve(s, current + s[i], n, ans);  // Recur by adding one more character to the current string
    }
}

// Function to find all permutations
vector<string> findpermutation(string arr){
    int n = arr.size();
    vector<string> ans;
    
    // Sorting the string to ensure lexicographical order
    sort(arr.begin(), arr.end());
    
    // Start the recursion with an empty string
    solve(arr, "", n, ans);
    
    // Sorting is done by default since characters were chosen in lexicographical order
    return ans;
}

int main(){
    string arr;
    getline(cin, arr);  // Input the string
    
    vector<string> ans = findpermutation(arr);
    
    // Print all the generated permutations
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    
    return 0;
}
