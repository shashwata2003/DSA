#include<iostream>
#include <math.h>
using namespace std;
/*  
decimal to binary 
*/
int main(){
int n = 101;
int ans = 0 , i = 0;
while (n!=0)
{
    int digit = n % 10;
    if (digit == 1)
    {
        ans = ans+ pow(2,i);
    }
    n=n/10;
    i++;    
}
cout<<ans;

return 0;
}