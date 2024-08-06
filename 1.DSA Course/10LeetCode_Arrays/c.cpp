#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Leetcode: Unique number of Occurance
Given an array of int. If the no. of occurance of each value is unique return true else false
eg {1,2}
1 occures once
2 occures once hence not unique return false
eg {1,2,2,3,3,3}
1 occurs once 
2 -> 2 times
3-> 3 times return true
 */
int main(){
vector<int> a = {-3,0,1,-3,1,1,1,-3,10,0};
int size = a.size();
sort(a.begin(),a.end());
int count;
int i =0,k=0;
vector<int> ans;
while(i<size)
{
    count = 1;
    for (int j = i+1; j < size; j++)
    {
        if (a[i] == a[j])
        {
            count++;
        }else{
            break;
        }

    }
    ans.push_back(count);

    i=i+count;
}
sort(ans.begin(),ans.end());
for (int i = 0; i < ans.size(); i++)
{
    if (ans[i] == ans[i+1])
    {
       cout<<"false";
    }
}
cout<<"true";
return 0;
}