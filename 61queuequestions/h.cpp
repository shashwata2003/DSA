#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*
Given an array of both positive and negative integers, 
the task is to compute sum of minimum and maximum elements of all sub-array of size k.
Input : arr[] = {2, 5, -1, 7, -3, -1, -2}  
        K = 4
Output : 18
Explanation : Subarrays of size 4 are : 
     {2, 5, -1, 7},   min + max = -1 + 7 = 6
     {5, -1, 7, -3},  min + max = -3 + 7 = 4      
     {-1, 7, -3, -1}, min + max = -3 + 7 = 4
     {7, -3, -1, -2}, min + max = -3 + 7 = 4 

Solution:
Apporach 1:
Using brute Force:
trave each element for each windom and find the min and max and find the sum 
Steps to implement-
Initialize a variable sum with value 0 to store the final answer
Run two loops to find all subarrays
Simultaneously find the length of the subarray
If there is any subarray of size k
Then find its maximum and minimum element
Then add that to the sum variable
In the last print/return value stored in the sum variable
Time: O(n*k)

Apporach 2:
We create two empty double-ended queues of size k (‘S’ , ‘G’) that only store indices of elements of 
current window that are not useless.
 An element is useless if it can not be maximum or minimum of next subarrays. 
Time :O(n)
space: 0(k)



  */

// C++ program to find sum of all minimum and maximum
// elements Of Sub-array Size k.
#include<bits/stdc++.h>
using namespace std;

// Returns sum of min and max element of all subarrays
// of size k
int solve(int *arr, int n, int k) {

    deque<int> maxi(k);
    deque<int> mini(k);

    //Addition of first k size window

    for(int i=0; i<k; i++) {

        while(!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();

        while(!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);
    }
    int ans = 0;

    ans += arr[maxi.front()] + arr[mini.front()];

    //remaining windows ko process karlo
    for(int i=k; i<n; i++) {

        

        //next window

        //removal
        while(!maxi.empty() && i - maxi.front() >=k) {
            maxi.pop_front();
        }

        while(!mini.empty() && i - mini.front() >=k) {
            mini.pop_front();
        }

        //addition

        while(!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();

        while(!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);    

        ans += arr[maxi.front()] + arr[mini.front()];
    }
    return ans;
}

int main() {


    int arr[7] = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    cout << solve(arr, 7, k) << endl;


    return 0;
}
