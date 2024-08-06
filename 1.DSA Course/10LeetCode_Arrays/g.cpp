#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Approach 3: To optimize the solution we will be using the fact that both the arrays are sorted
hence we have three case:
1. arr1[i]<arr2[j] : i++ (if jth term is greater than then the ith term then there is no point 
of checking the rest of element)
2. arr1[i]==arr[j]: print the element (this the case we want)
3. arr1[i]>arr2[j]: j++;if teh ith term is greater than the jth term then there is no point in checking the other
term in that array.
 */
int main(){
    vector<int> arr1 ={1,2,2,2,3,4};
    vector<int> arr2 = {2,2,3,3}; 
    vector<int> ans;
    int i = 0,j = 0;
    while (i<arr1.size() && j<arr2.size())
    {
        if (arr1[i] == arr2[j])
        {
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
        else if(arr1[i]<arr2[j]){
            i++;
        }else if(arr1[i]>arr2[j]){
            j++;
        }
        
    }
    
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
return 0;
}