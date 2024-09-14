#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

 

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
 */

/*
Steps:
1. Using divide and conquore method 
2. find the power for n/2 's and then multiple them together

The problem can be recursively defined by:

power(x, n) = power(x, n / 2) * power(x, n / 2);        // if n is even
power(x, n) = x * power(x, n / 2) * power(x, n / 2);    // if n is odd

3. Also handle the negative value.
*/

class Solution {
public:
    double myPow(double x, int n) {
        double temp;
        if(n == 0){
            return 1;
        }
        temp = myPow(x,n/2);
        if(n%2 == 0){
            return temp*temp;
        }
        else{
            if(n > 0){
                return x*temp*temp;
            }
            else{
                return temp*temp/x;
            }
        }
    }
};

int main(){

return 0;
}