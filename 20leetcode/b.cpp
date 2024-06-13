#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*
Merge Two sorted arrays: Given two sorted array, now merger both of them to form a third sorted arr
eg: arr1 [1,3,5,7,9]
arr2 [2,4,6]
ans[1,2,3,4,5,6,7,9]
 */

// Optimized solution where we are storing the ans in arr1 not in a different vector ans:
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1;
        int k = m + n - 1; // Index for the merged array in nums1
        
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
        
        // If there are remaining elements in nums2, copy them to nums1
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
int main()
{
    vector<int> arr1 = {1, 3, 5, 7, 9};
    vector<int> arr2 = {2, 4, 6};
    vector<int> ans;
    int i = 0, j = 0;
    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] < arr2[j])
        {
            ans.push_back(arr1[i]);
            i++;
        }
        else
        {
            ans.push_back(arr2[j]);
            j++;
        }
    } 
    // copying the extra ends of the array:
    while (i < arr1.size())
    {
        ans.push_back(arr1[i]);
        i++;
    }
    while (j < arr2.size())
    {
        ans.push_back(arr2[j]);
        j++;
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
