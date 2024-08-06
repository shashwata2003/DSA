#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Implement stack using Array:
Here we need to perform push pop and peek and empty function similar to a stack using a class of arrays.
 */
class Stack {
public:
    int top;
    int* arr;
    int size;

    Stack(int s) {
        this->size = s;
        this->top = -1;
        this->arr = new int[s];
    }

    void push(int d) {
        if (top < size - 1) {
            top++;
            arr[top] = d;
        }
        else {
            cout << "Stack full" << endl;
        }
    }

    void pop() {
        if (top >= 0) {
            top--;
        }
        else {
            cout << "Stack is empty" << endl;
        }
    }

    int peek() {
        if (top >= 0) {
            return arr[top];
        }
        else {
            return -1; // Indicate stack underflow
        }
    }

    bool empty() {
        cout<<top<<endl;
        return top == 0;
    }
};

int main(){
    Stack st(5);
    st.push(3);
    st.push(2);
    st.push(4);
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    cout<<st.empty()<<endl;
return 0;
}