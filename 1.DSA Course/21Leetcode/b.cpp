#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* Check if the array is sorted and reversed:
Given an array nums, return true if the array was originally sorted in non-decreasing order,
then rotated some number of positions (including zero). Otherwise, return false.
There may be duplicates in the original array.
eg : [3,4,5,1,2] ans: true
Here we need to check weather if the element i - 1 > i if so then we should return false. But it may be true once
when 5 > 1 in the above example, Hence to find the difference we will maintain a count which should be less or
equal to 1
 */
int main()
{
    vector<int> arr = {3, 4, 5, 1, 2};
    int n = arr.size();
    int count = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i - 1] > arr[i])
        {
            count++;
        }
    }
    if (arr[n - 1] > arr[0])
    {
        count++;
    }
    if (count >= 0)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }

    return 0;
}