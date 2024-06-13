#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  
Circular Queue using array:
If the front of the array is empty and the rare is at the end of the array, we can start add the element at the 
front and take the rare at the front of the array.
Condition weather the queue is full:
1. front == 0 and rear = size - 1
2. rear == front-1 % size -1

and init front and rear == -1 
for the first element front == -1 

and to move the rear to front we need to check the following condition:
i. if rear == size -1 and front != 0 then we can set rear = 0


Deque: here if the front == rare then there is a single element in the queue
*/

class mydequeue{
    public:
    int *arr;
    int size;
    int front;
    int rare;
    mydequeue(int s){
        this->size = s;
        this->arr = new int[s];
        this->front = -1;
        this->rare = -1;
    }

    void push(int d){
        // four cond.
        /*
        1. check stack full (rare == front-1 % size -1)
        2. first element 
        3. last element
        4. normal in
        */
        if((front == 0 && rare == size - 1 )||(rare == (front-1) % (size -1))){
            cout<<"Queu full";
        }
        else if(front == -1){
            front = rare = 0;
            arr[rare] = d;
        }
        else if(rare == size-1 && front != 0){
            rare = 0;
            arr[rare] = d;
        }else{
            rare++;
            arr[rare] = d;
        }
    }

    void pop(){
        /*
        four cond:
        1. Check empty
        2. check if front and rare are same
        3.front at end of the array
        4. normal*/
        if(front  == -1){
            cout<<"empty";
        }
        else if(front == rare){
            arr[front] = -1;
            front = rare = -1;
        }
        else if(front == size -1){
            arr[front] = -1;
            front = 0;
        }else{
            arr[front] = -1;
            front++;
        }
    }

    int top(){
        if(front == -1){
            return -1;
        }
        return arr[front];
    }

};

int main(){
    mydequeue dq(5);
    dq.push(2);
    cout<<dq.top()<<endl;
    dq.push(3);
    dq.push(4);
    cout<<dq.top()<<endl;
    dq.pop();
    cout<<dq.top()<<endl;


return 0;
}