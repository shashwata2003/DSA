#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Heap Implementation:
1. Insertion TC: O(lon n)
2. deletion: TC: O(log n) (delete the node)
3. STL priority queue
 */

class heap{
    public:
    int arr[100];
    int size;
    heap(){
        arr[0] = -1;
        size = 0;
    }

    void insertheap(int d){
        size = size + 1;
        int index = size;
        // Insert at the end 
        arr[index] = d;
         while(index > 1){
            // finding the right place for the new element
            // comparing with the parent val
            int parentIndex = index / 2;
            if(arr[parentIndex] < arr[index]){
                // if grater swap the val
                swap(arr[parentIndex], arr[index]);
                index = parentIndex;
            } else {
                break;
            }
        }

    }

    void deleteheap(){
        if(size == 0){
            cout<<"Empty";
            return;
        }
        // move the last element to the root and remove the root
        arr[1] = arr[size];
        size--;

        // Finding the right place for the new root.
        int i = 1;
        while (i<size)
        {
            int left = 2*i;
            int right = 2*i+1;
            if (left<size && arr[i]<arr[left])
            {
                swap(arr[i],arr[left]);
                i = left;
            }
            if (right<size && arr[i]<arr[right])
            {
                swap(arr[i],arr[right]);
                i = right;
            }
            else{
                return;
            }
            
        }
        

    }

    void printheap(){
        for (int i = 1; i <= size; i++)
        {
            cout<<arr[i]<<" ";
        }
        
    }
};

int main(){
    heap p;
    p.insertheap(50);
    p.insertheap(55);
    p.insertheap(40);
    p.insertheap(60);
    p.printheap();
    p.deleteheap();
    cout<<endl;
    p.printheap();
return 0;
}