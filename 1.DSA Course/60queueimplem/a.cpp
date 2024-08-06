#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Implement a queue using a array:
Implement push pop front and empty function of the queue using a array
 */
class myqueue{
    public:
    int * arr;
    int size;
    int front;
    int rear;
    myqueue(int s){
        this->size = s;
        this->arr = new int[s];
        this->front = 0;
        this->rear = 0;
    }

    void push(int data){
        if(rear == size){
            cout<<"full";
        }
        else{
            arr[rear] = data;
            rear++;
        }
    }
    void pop(){
        if(rear == front){
            cout<<"empty stack";
        }
        else{
            arr[front] = -1;
            front++;
            if(front == rear){
                rear = 0;
                front = 0;
            }
        }
    }
    
    int top(){
        if(rear==front){
            return -1;
        }else{
            return arr[front];
        }
    }
};
int main(){
    myqueue q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    cout<<q.top()<<endl;
    q.pop();
    cout<<q.top()<<endl;
return 0;
}