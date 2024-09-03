#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  */
class MedianFinder {
private:
    // Max heap to store the smaller half of the numbers (this will be a max heap by default)
    priority_queue<int> maxheap;

    // Min heap to store the larger half of the numbers (this will be a min heap using greater<int>)
    priority_queue<int, vector<int>, greater<int>> minheap;

public:
    // Constructor: Initializes the MedianFinder object
    MedianFinder() {
        // No specific initialization needed as heaps are ready to use
    }
    
    // Function to add a new number to the data structure
    void addNum(int num) {
        // Step 1: Add the new number to maxheap
        maxheap.push(num);

        // Step 2: Balance the heaps - Move the largest element from maxheap to minheap
        minheap.push(maxheap.top());
        maxheap.pop();

        // Step 3: If minheap has more elements than maxheap, balance again by moving the smallest element 
        // from minheap back to maxheap
        if (minheap.size() > maxheap.size()) {
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }
    
    // Function to find the median of the current numbers
    double findMedian() {
        // If maxheap has more elements, the median is the root of maxheap
        if (maxheap.size() > minheap.size()) {
            return maxheap.top();
        }

        // If both heaps are of equal size, the median is the average of the roots of both heaps
        return (maxheap.top() + minheap.top()) / 2.0;
    }
};

int main(){

return 0;
}