#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Interleave the first half of the queue with second half: 
Given a queue of integers of even length, rearrange the 
elements by interleaving the first half of the queue with the second half of the queue.
Input :  1 2 3 4
Output : 1 3 2 4

Input : 11 12 13 14 15 16 17 18 19 20
Output : 11 16 12 17 13 18 14 19 15 20

meaning divide the input in half and rearrage in a way that first element form first half ans the next element from 
the second half do this till the end.

Solution:
Apporach 1:
Using queue:
1. divide the queue into halves 
2. insert the first half in the new queue
3. now simulataionly pop one element form teh new queue and add it to the end of the old queue, then pop one form 
the old queue front and push it at the end of the queue.
4. complete this till the second halve of the element ends.

Apporach 2:
Using Stack:
1. Push the first halve of the elements of the queue in the stack 
2. then push it back in the end of the queue.
3. pop the element form the front of the queue and push it back in the queue
4. now push the first of the queue in the stack 
5. Now simulataniously pop elements fron the stack and push it back of the queue and then pop from the front of the 
queue and push at the end of the queue.
** multiple stack push are done to make the elements in the perfect order 
 */

void interleave1(queue<int> &q){
    int size = q.size();
    int mid = size/2;
    queue<int> q1;
    for (int i = 0; i < mid; i++)
    {
        int a = q.front();
        q.pop();
        q1.push(a);
    }
    while (!q1.empty()) {
        int f = q1.front();
        q1.pop();
        q.push(f);

        if (!q.empty()) {
            int l = q.front();
            q.pop();
            q.push(l);
        }
    }
}

void interLeaveQueue(queue<int>& q)
{
    if (q.size() % 2 != 0) {
        cout << "Input even number of integers." << endl;
        return;
    }

    stack<int> s;
    int halfSize = q.size() / 2;

    for (int i = 0; i < halfSize; i++) {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    for (int i = 0; i < halfSize; i++) {
        q.push(q.front());
        q.pop();
    }

    for (int i = 0; i < halfSize; i++) {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty()) {
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
}

int main(){
    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    q.push(19);
    q.push(20);
    interleave1(q);
    int n = q.size();
    for (int i = 0; i < n; i++)
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    

return 0;
}