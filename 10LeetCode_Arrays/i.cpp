#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Find Triplet:
Given a array of integers, and a sum value. now find a triplet which will add up to the value of sum.

 */
int main(){
vector<int> arr = {1,2,3,4,5,6};
int sum = 6;
for (int i = 0; i < arr.size(); i++)
{
    for (int j = i+1; j < arr.size(); j++)
    {
        for (int k = j+1; k < arr.size(); k++)
        {
            if(arr[i]+arr[j]+arr[k] == sum){
                cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<endl;
            }
        }
        
    }
    
}

return 0;
}