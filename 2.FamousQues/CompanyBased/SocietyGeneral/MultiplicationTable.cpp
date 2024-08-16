#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
K smallest element in multiplication table:
*/

int solve(int n, int m, int k){
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ans.push_back((i+1)*(j+1));
        }
    }
    sort(ans.begin(),ans.end());
    
    return ans[k-1];
}

//Apporach 2:
int countLessEqual(int mid, int m, int n) {
    int count = 0;
    for (int i = 1; i <= m; i++) {
        count += min(mid / i, n);
    }
    return count;
}

int findKthNumber(int m, int n, int k) {
    int low = 1, high = m * n;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (countLessEqual(mid, m, n) < k) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    cout<<solve(n,m,k);
return 0;
}