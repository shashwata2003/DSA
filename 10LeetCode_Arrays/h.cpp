#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
code studio: pair sum
Given a array of n elements and the sum s. Find the pair of element which addes up equal to the sum
eg : {1,2,3,4,5}
ans : 1,4 and 2,3
also the ans should be min and max order
Sol: Just travers the array one by one and check for the sum once found the match print it 
 */
int main(){
vector<int> arr = {1,2,3,4,5};
int sum = 5;
vector<vector<int>> ans;
for (int i = 0; i < arr.size(); i++)
{
   for (int j = i+1; j < arr.size(); j++)
   {
        if(sum == arr[i]+arr[j]){
            vector<int> temp;
            temp.push_back(min(arr[i],arr[j]));
            temp.push_back(max(arr[i],arr[j]));
            ans.push_back(temp);
        }
   }
   
}
sort(ans.begin(),ans.end());
for (int i = 0; i < ans.size(); i++)
{
    cout<<ans[i]<<" ";
}

return 0;
}