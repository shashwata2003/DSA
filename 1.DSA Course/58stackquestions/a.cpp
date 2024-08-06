#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* N stack:
Given a single array, we need to implement N stack using the single array.
Implement push and pop functions of the stack. 
push(X, M): Pushes an element X into the Mth stack. Returns true if the element is pushed into the stack, 
otherwise false.
pop(M): Pops the top element from Mth Stack. Returns -1 if the stack is empty, otherwise, 
returns the popped element.
Sample Input 1 :
3 6 5
1 10 1
1 20 1
1 30 2
2 1
2 2
Sample Output 1 :
True 
True
True
20
30

Solution:
Apoearch 1:space complexity: O(n);
Here we can divide the array into n no. of segments and each segment we can use as a stack.
But this apporach is not space optimized as there will be alot of space wasted as ... one segment get full and the 
other might be empty still for that segment the stack will return stack full.

Apporach 2:
Now to use the space of the array dynamically we will use the following method,
We need two new arrays called 
1.top[no.of stack]: stores the top values of the stack
2. next[size of arr]: store the next empty spot in the arr also it stores the next element it is pointing to.

At initial when the arr is empty top = [-1,-1,-1] and next[] = [1,2,3,4,5,-1](this shows the next empty spot in the arr)

we need one more variable called the freespot = 0 which will tell the current free spot in the arr.

now consider when a element is asked to push in s1:
step1: find index to push : index = freespot
step 2: update free spot = freespot = next[index];
step3: push the val in arr : arr[index] = val
step3: update next[index]: next[index] = top[m-1]; m tells the stack no. 
step4: update top : top[m-1] = index;

Excution: for push(10,1);
1. index = 0;
2. freespot = next[0] = 1;
3. arr[0] = 10
4. next[0] = top[1-1] = top[0] =-1; // as 10 is the last element it will point to the -1 
5. top[0] = 0;

Time complexity O(1) O(1)
Space complexity O(S+N)
 */

class Stack{
    public:
    int * arr;
    int* top;
    int* next;
    int n,s;
    int freespot;
    
    Stack(int N, int S){
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];

        // initialize top:
        for (int i = 0; i < n; i++)
        {
            top[i] = -1;
        }
        //initialize next:
        for (int i = 0; i < s; i++)
        {
            next[i] = i+1;
        }
        //update the last index of the next to -1
        next[n-1] = -1;
        
        freespot = 0;
    }

    bool push(int x, int m){
        //checking overflow condition:
        if(freespot == -1){
            return false;
        }
        // find index :
        int index = freespot;
        // update freespot:
        freespot = next[index];
        //push the val:
        arr[index] = x;
        //update next:
        next[index] = top[m-1];
        //update top;
        top[m-1] = index;

        return true;
    }

    int pop(int m){
        // we will just reverse the entire push function

        // check for underflow condition:
        if(top[m-1] == -1){
            return -1;
        }
        // now reverse the push function:
        int index = top[m-1];
        top[m-1] = next[index]; 
        next[index] = freespot;
        freespot = index;
        return arr[index];
    }
};


int main(){
    Stack* st = new Stack(3,5);
    st->push(10,1);
    st->push(20,2);
    st->push(30,2);
    cout<<st->pop(1);
return 0;
}