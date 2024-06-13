#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/* 
Sieve of Eratoshences: used to find the prime no.
Here we first lay out all the no. form 2 to n -1 and follow each steps:
1. mark all the no. as prime 
2. No terverse the prime no. one by one and mark the the table of that no. as non prime eg first prime will be 2 
hence mark all the no. in 2s table as no prime 
3. continue till u have traveres every prime no.

?? this a more efficent way of finding the count of the prime no. then the pervious method.
// time complixity: o(nlog*log(n))
 */
int main(){
    int n = 10;
    int count = 0;
    //created a array where we set all element as prime
    vector<bool> arr(n+1,true);
    //seting 1 and 0 as non prime:
    arr[0]=arr[1]=false;
    //travering all the prime no.
    for (int i = 2; i < n; i++)
    {
        if(arr[i]){
            count++;
            for (int j = 2*i; j < n; j=j+i)
            {
                arr[j] = false;
            }
            
        }
    }
    cout<<count<<endl;
    

return 0;
}