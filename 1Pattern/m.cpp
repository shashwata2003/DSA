#include<iostream>
using namespace std;
/* 
A
BC
DEF */
int main(){
int n = 3, i =0;

    char c = 'A';
while (i<n)
{
    int j =0;
    while (j<=i)
    {
        cout<<c;
        c++;
        j++;

    }
    cout<<endl;
    i++;
    
}

return 0;
}