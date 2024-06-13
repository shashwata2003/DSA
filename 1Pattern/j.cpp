#include<iostream>
using namespace std;
/*  
A B C
D E F
G H I
*/
int main(){
int n = 3, i=0;
char c = 'A';
while (i<n)
{
    int j = 0;
    while (j<n)
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