#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Merge 2 max heaps:
Given two binary max heaps as arrays, merge the given heaps to form a new max heap.
using zero base indexing
eg:
Input  : 
n = 4 m = 3
a[] = {10, 5, 6, 2}, 
b[] = {12, 7, 9}
Output : 
{12, 10, 9, 2, 5, 7, 6}

Solution:
step1: Merge both the arrays
step 2 : use the merged  array to create a max heap using heapify method


Expected Time Complexity: O(m+n)
Expected Auxiliary Space: O(n + m)

 */


void heapify(vector<int> &ans, int i, int n) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && ans[left] > ans[largest]) {
        largest = left;
    }
    if (right < n && ans[right] > ans[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(ans[largest], ans[i]);
        heapify(ans, largest, n);
    }
}

vector<int> mergeheap(vector<int> a, vector<int> b) {
    // Step 1: merge the arrays:
    vector<int> ans;
    for (auto i : a) {
        ans.push_back(i);
    }
    for (auto i : b) {
        ans.push_back(i);
    }
    int n = ans.size();

    // Step 2: converting into a max heap.
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(ans, i, n);
    }
    return ans;
}

int main() {
    vector<int> a = {10, 5, 6, 2};
    vector<int> b = {12, 7, 9};
    vector<int> ans = mergeheap(a, b);
    int size = ans.size();
    for (int i = 0; i < size; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}