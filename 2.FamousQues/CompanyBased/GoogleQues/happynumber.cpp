#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Happy Number:
Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which 
does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.

Example 1:

Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
 */
int run(int n) {
    int sum = 0;
    while (n != 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}

bool happynumber(int n) {
    int slow = n;
    int fast = run(n);
    
    while (fast != 1 && slow != fast) {
        slow = run(slow);
        fast = run(run(fast));
    }
    return fast == 1;

}
int main(){
    int n = 19;
    cout<<happynumber(n);
return 0;
}