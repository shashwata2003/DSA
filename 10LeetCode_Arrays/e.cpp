#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Leetcode: Find all duplicates in an array
given an array find all the duplicate no. which are appearing twice in that array.
constrant the elements are between 1 - n-1
eg : {2,3,1,2,3}
ans{3,2}
sol: First find the index of the first element and at that index add n 
after doing till the end of the array.
now find the divide it by n if any value in th updated array is > 2 hence it apperared twice in the array.
 */
int main(){
    vector<int> arr = {2,3,1,2,3};
    int n = arr.size();
    vector<int> ans;
    for (int  i = 0; i < arr.size(); i++)
    {
        int index = arr[i]%n;
        arr[index]+=n;
    }
    for (int j = 0; j < arr.size(); j++)
    {
        if(arr[j]/n >=2){
            cout<<j<<endl;
            ans.push_back(j);
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
return 0;
}