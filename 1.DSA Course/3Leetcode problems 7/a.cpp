#include<iostream>
#include <climits>
using namespace std;
/* 
Leetcode question: Reverse integer
Given n = 123
case1  reverse the integer as 321
if it is negative -123 then -321
case 2 :
if the reversed no. is out of bound then print 0
 */
int main(){
int n = -123;
int ans = 0;
while (n!=0)
{
    int digit = n % 10;
    if (ans> INT_MAX/10 || ans < INT_MIN/10)
    {
        return 0;
    }
    
    ans = ans * 10 + digit;
    n =n/10;
}
cout<<ans;
return 0;
}