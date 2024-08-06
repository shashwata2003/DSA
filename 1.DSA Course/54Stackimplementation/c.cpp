#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  Two Stacks:
We need to implement two stacks using a single array.
push1(NUM) - Push ‘NUM’ into stack1.
push2(NUM) - Push ‘NUM’ into stack2.
pop1() - Pop out a top element from stack1 and return popped element, in case of underflow return -1.
pop2() - Pop out a top element from stack2 and return popped element, in case of underflow return -1.

There are 2 types of queries in the input
Type 1 - These queries correspond to Push operation.
Type 2 - These queries correspond to Pop operation.

Solution:
As we are going to use a single array to implement two stack we will need two top pointers one will point to 
begining of the end and the other will point to the end of the array.
Hence for the first stack the top will go left to right and for stack 2 the top will go left to right.
 */

class Stack{
    public:
    int *arr;
    int top1;
    int top2;
    int size;
    Stack(int s){
        this->arr = new int[s];
        this->top1 = -1;
        this->top2 = s;
        this->size = s;
    }

    void push1(int d){
        if(top2 - top1 >1){
            top1++;
            arr[top1] = d;
        }
    }

    void push2(int d){
        if(top2 - top1 >1){
            top2--;
            arr[top2] =d;
        }
    }

    int pop1(){
        if(top1>=0){
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else{
            return -1;
        }
    }

    int pop2(){
        if(top2 <=size-1){
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else{
            return -1;
        }
    }
};


int main(){
    Stack st(6);
    st.push1(1);
    st.push2(2);
    st.push1(3);
    st.push2(4);
    cout<<st.pop1()<<endl;
    cout<<st.pop2()<<endl;
    cout<<st.pop1()<<endl;
    cout<<st.pop2()<<endl;
return 0;
}