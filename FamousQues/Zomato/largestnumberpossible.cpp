#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Arrange given numbers to form the biggest number | Set 1
Given an array of strings arr[] of length n, where every string representing a non-negative integers, 
the task is to arrange them in a manner such that after concatenating them in order, it results in the 
largest possible number. Since the result may be very large, return it as a string.

Input: n = 5, arr[] = {“3”, “30”, “34”, “5”, “9”}
Output: “9534330”
Explanation: Given numbers are {“3”, “30”, “34”, “5”, “9”}, the arrangement “9534330” gives the largest value.

Input: n = 4, arr[] = {“54”, “546”, “548”, “60”}
Output: “6054854654”
Explanation: Given numbers are {“54”, “546”, “548”, “60”}, the arrangement “6054854654” gives the largest value.
*/

bool mycompare(const string & a, const string &b){
    // check after concating two strings:
    return (a+b) > (b+a);
}

string largestNumber(vector<string> arr){
    vector<string> sortedarr = arr;
    sort(sortedarr.begin(),sortedarr.end(),mycompare);
    string result;
    for(auto num : sortedarr){
        result = result+num;
    }
    return result;
}   

int main()
{
    // if the input is given in vector of ints formate convert the vector to string using "to_string()"
    // function.
    vector<string> arr1 = { "3", "30", "34", "5", "9" };
    cout << largestNumber(arr1)
         << endl; // Output: "9534330"

    vector<string> arr2 = { "54", "546", "548", "60" };
    cout << largestNumber(arr2)
         << endl; // Output: "6054854654"

    return 0;
}