#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* Doubly ended queue:
    Init front and rear == -1.
    function: pushback, pushfront , popfront, popback

    to implement pushfront: 
    we need to move the front pointer towards the 0th index. 
    1. if front == -1 first element 
    2. if queue is full
    3. to implement the circular condition hence when front == 0 then front == size -1
    4. normal push front --

    Pushback: will be same as the enqueue function
    popfront : similar to dequeue
    pop rare: 
    same 4 condition:
    1. check if empty:
    2. check if single element and then set front == rear = -1
    3. cyclic nature: if rear == 0 then rare = n-1
    4. normal process : rear--
 */

class MyDeque
{
    int * arr;
    int size;
    int front;
    int rear;
    MyDeque(int s){
        this->size = s;
        this->arr = new int[s];
        this->front = -1;
        this->rear = -1;
    }

    void pushback(int d){
         if( isFull() ) {
            return false;
        }
        else if(isEmpty()) {
            front  = rear = 0;
        }
        else if(rear == size-1 && front != 0) {
            rear = 0;
        } 
        else
        {
             rear++;
        }
        arr[rear] = x;
    }
    void pushfront(int d){
        f( isFull() ) {
            return false;
        }
        else if(isEmpty()) {
            front  = rear = 0;
        }
        else if(front == 0 && rear != size-1) {
            front = size-1;
        } 
        else
        {
            front--;
        }
        arr[front] = x;
    }
    void popback(){
        if( isFull() ) {
            return false;
        }
        else if(isEmpty()) {
            front  = rear = 0;
        }
        else if(rear == size-1 && front != 0) {
            rear = 0;
        } 
        else
        {
             rear++;
        }
        arr[rear] = x;
    }
    void popfront(){
        if(isEmpty()){//to check queue is empty
            //cout << "Queue is Empty " << endl;
            return -1;
        }
        
        int ans = arr[front];
        arr[front] = -1;
        
        if(front == rear) { //single element is present
            front = rear = -1;
        }
        else if(front == size - 1) {
            front = 0; //to maintain cyclic nature
        }
        else
        {//normal flow
            front++;
        }
    }
    int top(){
        if(isEmpty()){
            return -1;
        }
        return arr[front];
    }
};
int main(){
    
return 0;
}