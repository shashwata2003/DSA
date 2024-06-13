#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* Leetcode Candy problem: Hard */

void MaxCandy(const vector<int>& rating, int& a, int size) {
    vector<int> left(size, 1);
    vector<int> right(size, 1);

    for (int i = 1; i < size; i++) {
        if (rating[i] > rating[i - 1]) {
            left[i] = left[i - 1] + 1; // Incrementing the candy count
        }
    }

    for (int i = size - 2; i >= 0; i--) {
        if (rating[i] > rating[i + 1]) {
            right[i] = right[i + 1] + 1; // Incrementing the candy count
        }
    }

    vector<int> ans(size);
    for (int i = 0; i < size; i++) {
        ans[i] = max(left[i], right[i]);
    }

    a = 0; // Reset 'a' to accumulate anew
    for (int i = 0; i < size; i++) {
        a += ans[i];
    }
}
int main(){
    vector<int> rating = {1,2,87,87,87,2,1};
    int ans  = 0;
    MaxCandy(rating,ans,rating.size());
    cout<<ans<<endl;
return 0;
}