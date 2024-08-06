#include<iostream>
using namespace std;
/*  
A
BC
CDE
DEFG
*/
int main(){
int n = 4, i=0;

while (i<n)
{
    int j =0;
    char c = 'A';
    c=c+i;
    while (j<=i)
    {
        
        cout<<c;
        c++;
        // also we can use a formula that is 'A'+row+col-2
        j++;
    }
    i++;
    cout<<endl;
}

return 0;
}