#include<iostream>
using namespace std;
/* 
Leetcode: Compliment if base 10.
n = 5 , 101 
compliment 010 = 2 ans
- Take ones compliment of the 32 bit binary int 
- then create a mask which has one 111 at the end of the 32 bits and it with compliented ans. Doing this will
remove all the 1's at the beginning of the 32 bit int.
ans = (~n)&mask

** Edge case when n = 0 comliment is 1
 */
int main(){
int n = 10;
int m = n;
int mask = 0;
//edge case
if (n == 0)
{
    cout<<0;
}

while (m != 0 )
{
    mask = (mask << 1) | 1;
    m = m>>1;
}
int ans = (~n)&mask;
cout<<ans;

return 0;
}