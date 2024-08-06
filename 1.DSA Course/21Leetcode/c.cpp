#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Sum Of Two Arrays:
Given two arrays we need to add both of them to find the sum in the third array like:
a = [1 2 3 4]
b = [6]
ans = [1 2 4 0]
Here we need to consider three case:
1. lenght of a > b: 
2. Lenght of a<b:
3. lenght a = b
 */
int main(){
    vector<int> a = {1,2,3,4};
    vector<int> b = {6};
    vector<int> ans;
   
    int carry = 0;
    int i = a.size()- 1;
    int j = b.size() - 1;
    while (i>=0 && j >= 0)
    {
        int x = a[i];
        int y = b[j];
        int sum = x + y +carry;
        carry = sum/10;
        sum = sum % 10;
        ans.push_back(sum);
        i--;
        j--;
    }
    while (i>=0)
    {
        int sum = a[i] + carry;
        carry = sum/10;
        sum = sum % 10;
        ans.push_back(sum);
        i--;
    }
    while (j>=0)
    {
        int sum = b[j] + carry;
        carry = sum/10;
        sum = sum % 10;
        ans.push_back(sum);
        j--;
    }
    while (carry!=0)
    {
        int sum = carry;
        carry = sum/10;
        sum = sum % 10;
        ans.push_back(sum);
    }
    reverse(ans.begin(),ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
    
    
return 0;
}