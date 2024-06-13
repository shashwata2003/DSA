#include<iostream>
using namespace std;
/* 
leetcode problem: Subtract the product and sum of digit of an Integer
given n = 234
product = 2*3*4 = 24
sum = 2+3+4 = 9;
ans: 24 - 9 = 15
 */
int main(){
int n = 234;
int sum = 0;
int prod = 1;
while (n!=0)
{
    int digit = n % 10;
    sum = sum + digit;
    prod = prod * digit;
    n =n /10;
}
cout<<prod- sum <<endl;
return 0;
}