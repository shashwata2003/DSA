#include<iostream>
using namespace std;
/*
 1 
1*
 12
2**
 123
3***
 1234
4**** 
here j depends on i.
*/
int main(){
int n= 4;
int i =0;
while (i<n)
{
    int j = 0;
    while (j<=i)
    {
        cout<<"*";
        j++;
    }
    cout<<endl;
    i++;
    
}

return 0;
}