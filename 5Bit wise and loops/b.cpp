#include<iostream>
using namespace std;
/* 
check for prime no.
 */
int main(){
int n = 2;
bool isprime = true;
for (int i = 2; i < n; i++)
{
    if (n%i == 0)
    {
        //cout<<"Not a prime number";
        isprime = false;
        break;
    }
    
}
if (isprime == false)
{
    cout<<"not prime";
}else{
    cout<<"prime";
}


return 0;
}