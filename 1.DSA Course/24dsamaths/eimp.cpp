#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Modular Exponentiation:
Here we are given x, n and m. we need to find x^n % m.
check the notes for the explaination.
 */
int main(){
    int ans = 1;
    int x = 4;
    int n = 3;
    int m = 10;

    while (n>0)
    {
        if (n&1)
        {
            //odd case:
            ans = (1LL*ans * (x)%m)%m;
        }
        x = (1LL*(x)%m * (x)%m)%m; // using long long for the edge case
        n = n>>1; // dividing n by 2 or right shifting it by 1 
        
    }
    cout<<ans<<endl;
    

return 0;
}