#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Heap sort:
Given a heap we need to sort that heap
Algo:
We will use recursion to solve it 
befor this we need to build heap if given arr
step 1: swap first element of the heap with the last element hence the root will be the greatest and hence will be 
in the right place. and decrement size and forget about that node.
step 2: next place the current node at the right place 
step 3. repeat step 1 and 2 till size == 0

TS: nlog n
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

void heapify(int *arr,int n, int i){
    // setting the largest val = the current element
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;
    if(left<n && arr[largest]<arr[left]){
        largest = left;
    }
    if(right<n && arr[largest]<arr[right]){
        largest = right;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}

void heapsort(int &arr[],int n){
    int size = n;
    while (size>1)
    {
        swap(arr[size],arr[i]);

        size--;
        heapify(arr,size,1);
    }

    
}

int main(){
int n = 6;

return 0;
}