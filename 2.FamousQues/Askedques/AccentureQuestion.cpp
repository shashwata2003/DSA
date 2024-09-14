#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
A prime number is a Circular Prime Number if all of its possible rotations are itself prime numbers. Now given a number N check if it is Circular Prime or Not.
 

Example 1:

Input: N = 197
Output: 1
Explanation: 197 is a Circular Prime because
all rotations of 197 are 197, 719, 971 all of 
the 3 are prime number's hence 197 is a 
circular prime.

Example 2:

Input: N = 101
Output: 0
Explanation: 101 and 11 is prime but 110 is
not a prime number.
 
 */

bool isprime(int n)
{
    if (n == 1)
    {
        return false;
    }
    if (n == 2 || n == 3)
    {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0)
    {
        return false;
    }

    for (int i = 5; i * i <= n; i = i + 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
        {
            return false;
        }
    }
    return true;
}


int isCircularPrime(int n)
{
    int cnt = 0;
    int temp = n;
    while (temp)
    {
        cnt++;
        temp = temp / 10;
    }
    temp = n;
    while (isprime(temp))
    {
        int rem = temp % 10;
        int div = temp / 10;
        temp = (pow(10, cnt - 1) * rem) + div;
        if (temp == n)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{

    return 0;
}