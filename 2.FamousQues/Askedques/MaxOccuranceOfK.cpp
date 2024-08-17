#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* Number with maxi occurrence of digit k:
Given a arr of int of size n, and given a int k find the number in the arr, which has maximum occurace of k in them
k = 2
37,823,122,2322,6017
ans = 2322

k=1
2153,65,1,12,111,1111  
ans: 1111
 */

int maxOccurance(vector<int> &arr, int k) {
    int maxlength = INT_MIN;
    int ans = -1;

    for (int i = 0; i < arr.size(); i++) {
        string dig = to_string(arr[i]);
        int count = 0;
        for (int j = 0; j < dig.length(); j++) {
            if (k + '0' == dig[j]) {
                count++;
            }
        }
        if (count > maxlength) {
            maxlength = count;
            ans = arr[i];
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {37,823,122,2322,6017};
    int k = 2;
    cout<<maxOccurance(arr,k);
return 0;
}