#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* Decimal to Octal Conversion:

You are given a decimal number as input. You need to convert this number into its equivalent in the octal 
number system. The octal number system is the number system with a base value = 8.

A number system with base value = n means that all numbers, when written in this number system, will be 
represented with only digits from 0 to n-1. For example, the Binary number system has a base value = 2, so 
any number, when written in the binary system, will be represented using the digits 0 and 1 only.

Note:
The binary number system requires 2 digits (0-1), the Ternary number system requires 3 digits (0-2), 
the Octal number system requires 8 digits (0-7), and the decimal number system requires 10 digits (0-9) 
    to represent any numeric value.
 */

long long decimalToOctal(int x) {
    long long octalNumber = 0;
    long long placeValue = 1;
    
    while (x) {
        int remainder = x % 8;
        octalNumber += remainder * placeValue;
        x /= 8;
        placeValue *= 10;
    }
    
    return octalNumber;
}

int main(){
    int x = 8;
    cout<<decimalToOctal(x);
return 0;
}