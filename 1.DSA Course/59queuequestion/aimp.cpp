#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Create a stack data structure that allows operations such as push (adding an element), 
pop (removing the top element), top (retrieving the top element), and also provides a way to
 retrieve the minimum element in constant time.
Implement the following public functions :

1. push(data) :
This function should take one argument of type integer. It pushes the element into the stack and returns nothing.

2. pop() :
It pops the element from the top of the stack and returns nothing.

3. top() :
It returns the element being kept at the top of the stack.

4.  getMin() :
It returns the smallest element present in the stack.

Sample Input 1:
6
1 13
1 47
3
1 8
2
4
Sample Output 1:
47
13

Solution: 
Apporach1 :
Here we going to use two stacks one will push the val normally and the oother will push the min of the the currently 
pushed value and the top pervios min val . hence the top of stack 2 will return the getmin() ans.

But this approach will take O(n) space complexity which we dont want.

Apporach 2:
This formula is used to find the previous min using the current min. Check the video once more.
here we are going to use a single variable called the min_val which will store the mini val of the stack
now to implement this we need to follow the following steps:
for push():
1. check for overflow condition:
2. first element push normally to the stack and update the val of min_val = current val
3. for nect n-1 element check the conditio:
    if(curr<min_val): val = 2*curr-min // this formula is used to find the prev element using the current val
    push val and min_val = current
4. else: push the element normally

for pop()
1. check for underflow condition
2. if(curr>mini): normal pop()
3. else: val = 2*mini - curr
    min_val = val
    pop()




Time complexity and space complexity : O(1)
 */

class sStack{
    public:
    stack<int> st;
    int mini ;

    void push(int d){
        if(st.empty()){
            st.push(d);
        }
        else{
            if (d<mini)
            {
               int val = 2*d-mini;
               st.push(val);
               mini= d;
            }
        }
    }
    int pop(){
        if(st.empty()){
            return -1;
        }
        else{
            int curr = st.top();
            if(curr>mini){
                return curr;
            }
            else{
                int prevmin = mini;
                int val = 2*mini-curr;
                mini = val;
                return prevmin;
            }
        }
    }

    int top(){
        if(st.empty()){
            return -1;
        }
        else{
            int curr = st.top();
            if(curr<mini){
                return mini;
            }
            else{
                return curr;
            }
        }
    }

    bool empty(){
        return st.empty();
    }

    int getmin(){
        if(st.empty()){
            return -1;
        }
        else{
            return mini;
        }
    }
};

int main(){
    sStack* s = new sStack();
    s->push(2);
    // s->push(2);
    s->push(5);
    s->push(3);
    cout<<s->getmin()<<endl;
    cout<<s->top();
return 0;
}