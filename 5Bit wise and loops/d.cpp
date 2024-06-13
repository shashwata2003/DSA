#include<iostream>
using namespace std;
/* 
leetcode: number of 1 bit 
Given n = 11
count the no. of 1 bit in its binary form.
11 is 1011 in 32 bit formate 
ans will be 3
 */
int main(){
int n =12;
int count = 0;
while (n!=0)
{
    if(n&1){
        count++;

    }
    n=n>>1;
}
cout<<count;
return 0;
}