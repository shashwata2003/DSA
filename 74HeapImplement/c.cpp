#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*
Build min heap:
Given arr of int convert it into a min heap.
Here the input array follows 0 base indexing meaning first element of teh arr is not -1
hence here left = 2*i +1
and right = 2*i+2
 */

class heap
{
    int arr[100];
    int size;
    heap()
    {
        arr[0] = -1;
        size = 0;
    }
};


void heapifymin(vector<int> &arr, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest]) {
        smallest = left;
    }
    if (right < n && arr[right] < arr[smallest]) {
        smallest = right;
    }
    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapifymin(arr, n, smallest);
    }
}

int main() {
    vector<int> arr = {4, 1, 2, 5, 7};
    int n = arr.size();

    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifymin(arr, n, i);
    }

    // Print the array after heapify
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}