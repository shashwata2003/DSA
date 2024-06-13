#include<iostream>
using namespace std;
/*  
D
CD
BCD
ABCD
*/
int main(){
int n = 4, i =0;

while (i<n)
{
    int j =0;
    char c;
    c='A'+n-i -1;
    while (j<=i)
    {
        cout<<c;
        c++;
        j++;
    }
    i++;
    cout<<endl;
    
}

return 0;
}