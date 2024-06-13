#include <iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*
IsPrime:
The function to tell if the no. is prime or not.
Count Primes:
Given an integer n, return the number of prime numbers that are strictly less than n.
Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
 */
//The is prime function:
bool isPrime(int n)
{
    if (n<=1)
    {
        return false;
    }
    
    for (int i = 2; i < n - 1; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n = 10;
    //bool isprime = isPrime(n);
    //cout << isprime << endl;
    //count prime:
    int count=0;
    for (int i = 2; i < n; i++)
    {
        if (isPrime(i))
        {
            count++;
        }
        
        
    }
    cout<<count<<endl;

    return 0;
}