#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Find the square of a number till decimal:
eg : sq 3 = 1.73
 */
int FindSq(int n){
    int s = 0;
    int e = n;
    long long int mid = (s+e)/2;
    long long int ans  = -1;
    while (s<=e)
    {
        if(mid * mid == n){
            return mid;
        }
        if(mid * mid<n){
            ans = mid;
            s=mid+1;
        }else{
            e = mid -1;
        }
        mid = (s+e)/2;
    }
    return ans;
}

double FindDecimal(int n , int precision, int tempsol){
    double factor = 1;
    double ans = tempsol;
    for (int i = 0; i < precision; i++)
    {
        factor = factor /10;
        for (double j = ans; j*j < n; j =j+factor)
        {
            ans = j;
        }
        
    }
    return ans;
}
int main(){
int n = 8;
int TempSol = FindSq(n);
cout<<FindDecimal(n,3,TempSol)<<endl;
return 0;
}