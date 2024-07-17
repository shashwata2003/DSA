#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Min days to bloom:
Given a array of roses which store min days to bloom that rows, also we are given min no. of bouques we need 
and k which state k no. of consequetive roses will be called a bouque 
hence we need to  find the min days to meet the min bouque requirements.

eg:
{1,2,4,9,3,4,1} k = 2 n = 2;
ans : 4
 */

int mindays(vector<int> days, int k , int n){
    int mini = 1;
    int maxi = -1111;
    int size = days.size();
    for (int i = 0; i < size; i++)
    {
        maxi = max(maxi,days[i]);
    }
    int ans = 999;
    while(mini<=maxi){
        int mid = mini+(maxi - mini) / 2;
        int b = 0;
        int i = 0;
        while(i<size){
            int r = 0;
            while(i<size && days[i++] <= mid && ++r < k);
            if(r == k){
                b++;
            }
        }
        if(b>=n){
            ans = min(ans,mid);
            maxi = mid -1;
        }else{
            mini = mid+1;
        }
        
        
    }
    return ans;
}

int main(){
    vector<int> days = {1,2,4,9,3,4,1};
    int k = 2;
    int n = 2;

    cout<<mindays(days,k,n);
return 0;
}