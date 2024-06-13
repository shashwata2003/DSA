#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*
First negative integer in every window of size k:
Given an array A[] of size N and a positive integer K, find the first negative integer for each and
every window(contiguous subarray) of size K.
Input :
N = 5
A[] = {-8, 2, 3, -6, 10}
K = 2
Output :
-8 0 -6 -6
Explanation :
First negative integer for each window of size k
{-8, 2} = -8
{2, 3} = 0 (does not contain a negative integer)
{3, -6} = -6
{-6, 10} = -6

N = 8
A[] = {12, -1, -7, 8, -15, 30, 16, 28}
K = 3
Output :
-1 -1 -7 -15 -15 0
Solution:
Apporch 1: Using dequeue (Not optimized)
1. first process the first k elements in the array.
    i. check if there is any negative elements in the first k window if there is then store that index in the 
    dequeue.
    ii. now to store the ans of the first k elements , check if the deque > 0 if there is element add that element
    in the ans vector ans.push_back(arr[de.front()])
2. now process the rest of the elements. by running a loop from k to n and repeat the following steps
    i. remove a element if it doesnot belong to the k window like: if (!dq.empty() && i - dq.front() >= k)
    pop the front of the dequeue
    ii.  to add a element check if the element is < 0 then add the index in the dequeue at the rare end of the 
    dequeue.
    iii. follow the same steps to store the add the ans in the ans vector.

time complexity: O(n);
space complexity: O(n)

Apporach 2: optimized way:

*/

vector<long long int> firstnegative1(vector<long long int> arr, int n, int k){
    int negativeindex = 0;
    int negativelement;
    vector<long long int> ans;
    for (int i = k-1; i < n; i++)
    {
        while ((negativeindex<i) && (arr[negativeindex] > 0 || negativeindex<=i-k))
        {
            negativeindex++;
        }

        if(arr[negativeindex] < 0){
            negativelement = arr[negativeindex];
        }
        else{
            negativelement = 0;
        }
        ans.push_back(negativelement);
    }
    return ans;
}

vector<long long int> firstnegative(vector<long long int> arr, int n, int k)
{
    deque<long long int> dq;
    vector<long long int> ans;

    // check for the first window:
    for (int i = 0; i < k; i++)
    {
        if (arr[i] < 0)
        {
            dq.push_back(i);
        }
    }
    // store the answer of the first window:
    if (dq.size() > 0)
    {
        ans.push_back(arr[dq.front()]);
    }
    else
    {
        ans.push_back(0);
    }

    // now process the rest of the array:
    for (int i = k; i < n; i++)
    {
        // removing an element
        if (!dq.empty() && i - dq.front() >= k)
        {
            dq.pop_front();
        }
        // adding an element
        if (arr[i] < 0)
        {
            dq.push_back(i);
        }
        // store the answer
        if (dq.size() > 0)
        {
            ans.push_back(arr[dq.front()]);
        }
        else
        {
            ans.push_back(0);
        }
    }

    return ans;
}

int main()
{
    vector<long long int> arr = {-8, 2, 3, -6, 10};
    int n = 5;
    int k = 2;
    vector<long long int> ans = firstnegative1(arr, n, k);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}