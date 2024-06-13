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
int main(){

return 0;
}