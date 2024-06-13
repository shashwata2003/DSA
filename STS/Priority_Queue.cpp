#include<iostream>
#include <bits/stdc++.h>
#include <array>
#include<queue>

using namespace std;
/* 
It is a datatyoe whos top elements is always the largest value of the queue.
 */
int main(){
priority_queue<int> arr;
arr.push(1);
arr.push(2);
arr.push(3);
cout<<arr.top();
return 0;
}