#include<iostream>
using namespace std;
/* 

A B C D
A B C D
A B C D
A B C D
 */
int main(){
int n = 4, i =0;
while (i<n)
{
    int j = 0;
char c = 'A' ;// also one more way we can do this is like c = c +j
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