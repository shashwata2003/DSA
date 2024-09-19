#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
 */

/*Apporach 3:
Using Prefix array:
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        // Initialize prefix array with size n
        vector<int> prefix(n);
        prefix[0] = 1;

        // Calculate the prefix product
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }

        // Initialize the suffix product and the result array `ans` with size n
        int suffix = 1;
        vector<int> ans(n); // Ensures ans has space for all elements

        // Calculate the result by combining prefix and suffix products
        for (int i = n - 1; i >= 0; i--) {
            ans[i] = suffix * prefix[i];
            suffix *= nums[i]; // Update the suffix for the next iteration
        }

        return ans;
    }
};

/*Apporach 2:
Using both suffix and prefix array
*/
void findproduct(int arr[], int product[],int n)
{
    int prefix[n];
    prefix[0]=1; // since first element can have no prefix
    for(int i=1;i<n;i++)
    {
        prefix[i]=prefix[i-1]*arr[i-1];
    }
    int suffix[n];
    suffix[n-1]=1; // since last element can have no suffix
    for(int i=n-2;i>=0;i--)
    {
        suffix[i]=suffix[i+1]*arr[i+1];
    }
    // Building Product Array
    for(int i=0;i<n;i++)
    {
        product[i]=prefix[i]*suffix[i];
    }
}

/*Apporach 1:*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i = 0; i<n; i++){
            int temp = 1;
            for(int j = 0; j<n; j++){
                if(i!=j){
                    temp = temp* nums[j];
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

int main(){

return 0;
}