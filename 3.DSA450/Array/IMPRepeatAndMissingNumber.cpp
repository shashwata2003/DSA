#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
You are given a read only array of n integers from 1 to n.

Each integer appears exactly once except A which appears twice and B which is missing.

Return A and B.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Note that in your output A should precede B.

Example:

Input:[3 1 2 5 3] 

Output:[3, 4] 

A = 3, B = 4
 */
/*Brute Force:*/
pair<int,int> solve(vector<int> &arr, int n){
    unordered_map<int,int> mp;
    for(int i: arr){
        mp[i]++;
    }
    pair<int,int> ans;
    for(int i = 1; i<=n; i++){
        if(mp[i] == 0){
            ans.first = i;
        }
        if(mp[i] == 2){
            ans.second = i;
        }
    }
    return ans;
}

/*optimized Apporach: Maths
1. First find the sum of the all the elements in the arr
2. now find the sum of all n element 1 to n
3. the diff of these two sum will be give x-y 
4. now find the difference of (sq val of all the elements - sq val of elements 1 to n)  this will give x+y
5. now find the x and y
*/

vector<int> findMissingRepeatingNumbers(vector<int> a) {
    long long n = a.size(); // size of the array

    // Find Sn and S2n: 
    long long SN = (n * (n + 1)) / 2;
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6; //  sq sum of n number 

    // Calculate S and S2:  for the all val
    long long S = 0, S2 = 0;
    for (int i = 0; i < n; i++) {
        S += a[i];
        S2 += (long long)a[i] * (long long)a[i];
    }

    //S-Sn = X-Y:
    long long val1 = S - SN;

    // S2-S2n = X^2-Y^2:
    long long val2 = S2 - S2N;

    //Find X+Y = (X^2-Y^2)/(X-Y):
    val2 = val2 / val1;

    //Find X and Y: X = ((X+Y)+(X-Y))/2 and Y = X-(X-Y),
    // Here, X-Y = val1 and X+Y = val2:
    long long x = (val1 + val2) / 2;
    long long y = x - val1;

    return {(int)x, (int)y};
}

/*Optimized apporach XOR:*/

vector<int> findMissingRepeatingNumbers(vector<int> a) {
    int n = a.size(); // size of the array

    int xr = 0;

    //Step 1: Find XOR of all elements:
    for (int i = 0; i < n; i++) {
        xr = xr ^ a[i];
        xr = xr ^ (i + 1);
    }

    //Step 2: Find the differentiating bit number:
    int number = (xr & ~(xr - 1));

    //Step 3: Group the numbers:
    int zero = 0;
    int one = 0;
    for (int i = 0; i < n; i++) {
        //part of 1 group:
        if ((a[i] & number) != 0) {
            one = one ^ a[i];
        }
        //part of 0 group:
        else {
            zero = zero ^ a[i];
        }
    }

    for (int i = 1; i <= n; i++) {
        //part of 1 group:
        if ((i & number) != 0) {
            one = one ^ i;
        }
        //part of 0 group:
        else {
            zero = zero ^ i;
        }
    }

    // Last step: Identify the numbers:
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == zero) cnt++;
    }

    if (cnt == 2) return {zero, one};
    return {one, zero};
}

int main(){
    vector<int> arr = {3, 1, 2, 5, 3};
    cout<<solve(arr,5).first<<" "<<solve(arr,5).second<<" ";
return 0;
}