#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  k Queues in a single array:
Using a single array implement k no. of queues.
Solution:
Apporach 1:
Brute Force:
Divide the given array in K parts, treat each part as one queue.

Apporach 2:
Similar to N stack in a single array.
we need three array:
front[]: This is of size k and stores indexes of front elements in all queues. init = -1
rear[]: This is of size k and stores indexes of rear elements in all queues. init = -1
next[]: This is of size n and stores next free index init {1,2,3,4,5,-1}
**Push:


*/

class kqueue
{
private:
    int *arr;
    int size;
    int *rear;
    int *front;
    int *next;
    int free;
    int k;

public:
    kqueue(int s, int k)
    {
        this->size = s;
        this->k = k;
        this->rear = new int[k];
        this->front = new int[k];
        this->next = new int[s];
        this->arr = new int[s];
        this->free = 0;
        for (int i = 0; i < k; i++)
        {
            front[i] = -1;
            rear[i] = -1;
        }
        for (int i = 0; i < s; i++)
        {
            next = i + 1;
        }
        next[s - 1] = -1;
    }
    void push(int data, int k){
        if(free == -1){
            cout<<"full"<<endl;
        }
        int index = free;
        free = next[index];
        if (front[k] == -1)
        {
            front[k] = index;
        }else{
            next[rear[k]] = index  ;
        }
        next[index] = -1;
        rear[k-1] = index;
        arr[index] = data;
        
    }

    int pop(int k){
        if (front[k] == -1)
        {
            cout<<"empty"<<endl;
            return -1;
        }
        int index = front[k-1];
        front[k]=next[index];
        next[index] = free;
        free = index;
        return arr[index];
        
    }

}

int
main()
{

    return 0;
}