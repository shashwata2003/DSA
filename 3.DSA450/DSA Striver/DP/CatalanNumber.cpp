#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*  
Program for nth Catalan Number
(2n)! / ((n+1)!*n!)
*/

unsigned long int catalan(unsigned int n)
{
    // Base case
    if (n <= 1)
        return 1;
 
    // catalan(n) is sum of
    // catalan(i)*catalan(n-i-1)
    unsigned long int res = 0;
    for (int i = 0; i < n; i++)
        res += catalan(i) * catalan(n - i - 1);
 
    return res;
}

int main(){

return 0;
}